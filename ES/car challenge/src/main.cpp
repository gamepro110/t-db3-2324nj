#include "lib/Interfaces/IBtnIRQ.hpp"
#include "lib/Interfaces/IButton.hpp"
#include "lib/Interfaces/IDistanceSensor.hpp"
#include "lib/Interfaces/IFeedbackSensor.hpp"

#include "lib/MsgQueueData.hpp"
#include "lib/CarSystem.hpp"
#include "lib/ManualControlPanel.hpp"
#include "lib/FeedbackSensor.hpp"
#include "lib/MotorController.hpp"
#include "lib/Button.hpp"
#include "lib/NucleoPin.hpp"
#include "lib/Pid.hpp"
#include "lib/ServoMotor.hpp"
#include "lib/HC_SR04_DistSensor.hpp"
#include "lib/Logger.hpp"
#include "lib/Watchdog.hpp"

#include "main.h"
#include "cmsis_os.h"
#include "usart.h"
#include "gpio.h"
#include <string.h>
#include <stdio.h>

#define EnableWatchdog 1
#define USE_FREERTOS 1

void SystemClock_Config(void);
void MX_FREERTOS_Init(void);

#   if USE_FREERTOS
    // const osThreadAttr_t defaultTask_attributes = {
    //     .name = "defaultTask",
    //     .attr_bits = osThreadDetached,
    //     .cb_mem = NULL,
    //     .cb_size = 0,
    //     .stack_mem = NULL,
    //     .stack_size = 128 * 4,
    //     .priority = (osPriority_t)osPriorityNormal,
    //     .tz_module = 0,
    //     .reserved = 0
    // };

    const osThreadAttr_t CarSysTask_attributes = {
        .name = "carSysTask",
    };
    const osThreadAttr_t MCPTask_attributes = {
        .name = "mcpTask",
    };
    const osThreadAttr_t watchdogTask_attributes = {
        .name = "watchdogTask"
    };
#   endif

IButton* but0{ nullptr };
IButton* but1{ nullptr };

Watchdog watchdog{
    #if EnableWatchdog
    1 << 11
    #else
    0
    #endif
};

void carSysThreadFunc(void* sys);
void mcpThreadFunc(void* mcpPtr);
void watchdogTaskFunc(void* watchdog);
void thing(void*) {
    while (1) {
        osDelay(1);
    }
}

int main(void) {
    HAL_Init();
    SystemClock_Config();
    MX_GPIO_Init();
    MX_USART2_UART_Init();
    logger.Log("program start\n");

    osMessageQueueId_t buttonQueueId = nullptr;
    osMessageQueueId_t sensorQueueId = nullptr;

#   if USE_FREERTOS

    while(buttonQueueId == NULL) {
        buttonQueueId = osMessageQueueNew(20, sizeof(BtnMsgData), nullptr);
    }
    while(sensorQueueId == NULL) {
        sensorQueueId = osMessageQueueNew(20, sizeof(SensorMsgData), nullptr);
    }

    HC_SR04_DistSensor sensor{
        NucleoPin{ GPIOB, 6, 2 },
        NucleoPin{ GPIOB, 8, 2 },
        HardwareTimer{ TIM4 }
    };

    CarSystem carSystem{
        buttonQueueId,
        sensor
    };
#   endif

    Button button0 = Button({
        NucleoPin{ GPIOC, 0, PinMode::digital_input_pullup },
        EXTI0_IRQn,
        buttonQueueId,
        // []{ logger.Log("shortPress c0\n"); },
        // []{ logger.Log("longPress c0\n"); }
    });
    Button button1 = Button({
        NucleoPin{ GPIOC, 1, PinMode::digital_input_pullup },
        EXTI1_IRQn,
        buttonQueueId,
        // []{ logger.Log("shortPress c1"); },
        // []{ logger.Log("longPress c1"); }
    });

    but0 = &button0;
    but1 = &button1;

    ManualControlPanel controlPanel{
        button0,
        button1
    };


#   if !USE_FREERTOS
    //! temp!! (call and vars)
    if (!controlPanel.Setup()) {
        logger.Error("failed setting up MCP\n");
    }
#   endif

#   if USE_FREERTOS
    /* Init scheduler */
    // ES Course Comments: Uncomment the three lines below to enable FreeRTOS.
    osKernelInitialize(); /* Call init function for freertos objects (in freertos.c) */

    osThreadId_t threadWatchdog     { osThreadNew(watchdogTaskFunc, &watchdog, &watchdogTask_attributes) };
    osThreadId_t threadCarSys       { osThreadNew(carSysThreadFunc, &carSystem, &CarSysTask_attributes) };
    // osThreadId_t threadMCP          { osThreadNew(mcpThreadFunc, &controlPanel, &MCPTask_attributes) };
    osThreadId_t threadThing        { osThreadNew(thing, nullptr, nullptr) };

    // add threads.
    if (!(threadWatchdog
        && threadCarSys
        // && threadMCP
        && threadThing
    )) {
        logger.Error("failed setting up threads");
    }

    osKernelStart(); /* Start scheduler */
#   else
    /* We should never get here as control is now taken by the scheduler */
    /* Infinite loop */
    logger.Log("Hello World!\n");

    while (1) {
        controlPanel.Loop();
    }
#   endif
}

//! irq are broken inside freeRtos..... wtf
/*
// create task for irq?
// vTaskSuspend(nullptr) pauses its own task
// BaseType_t checkIfYieldRequired{ }; //<https://youtu.be/8lJuSn1xKfY?t=397>
extern "C" void EXTI0_IRQHandler(void) {
    // if (EXTI->PR & EXTI_PR_PR0) {
        EXTI->PR |= EXTI_PR_PR0;

        if (but0 != nullptr) {
            but0->HandleIrq();
        }
    // }
}

extern "C" void EXTI1_IRQHandler(void) {
    // if (EXTI->PR & EXTI_PR_PR1) {
        EXTI->PR |= EXTI_PR_PR1;

        if (but1 != nullptr) {
            but1->HandleIrq();
        }
    // }
}
//*/

void carSysThreadFunc(void* sys) {
    CarSystem* car = (CarSystem*)sys;

    if (car == nullptr) {
        osThreadExit();
        return;
    }

    if (!car->Setup()) {
        logger.Error("failed to init MCP. terminated thread\n\n");
        osThreadExit();
    }

    while (car != nullptr) {
        car->Update();
    }

    osThreadExit();
}

void mcpThreadFunc(void* mcpPtr) {
    ManualControlPanel* mcp = (ManualControlPanel*)mcpPtr; // void* > mcp* > mcp&

    if (mcp == nullptr) {
        osThreadExit();
        return;
    }

    watchdog.Reset();

    if (!mcp->Setup()) {
        logger.Error("failed to init MCP. terminated thread\n\n");
        osThreadExit();
    }

    while (mcp != nullptr) {
        mcp->Loop();
    }

    osThreadExit();
}

void watchdogTaskFunc(void* watchdog) {
    Watchdog& wd = *(Watchdog*)watchdog;

    while (1) {
        wd.Reset();
    }
}

#if 1 // hidden
/**
 * @brief System Clock Configuration
 * @retval None
 */
void SystemClock_Config(void)
{
    RCC_OscInitTypeDef RCC_OscInitStruct = {0};
    RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};
    RCC_PeriphCLKInitTypeDef PeriphClkInit = {0};

    /** Initializes the RCC Oscillators according to the specified parameters
     * in the RCC_OscInitTypeDef structure.
     */
    RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI;
    RCC_OscInitStruct.HSIState = RCC_HSI_ON;
    RCC_OscInitStruct.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;
    RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
    RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSI;
    RCC_OscInitStruct.PLL.PLLMUL = RCC_PLL_MUL9;
    RCC_OscInitStruct.PLL.PREDIV = RCC_PREDIV_DIV1;
    if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
    {
        Error_Handler();
    }
    /** Initializes the CPU, AHB and APB buses clocks
     */
    RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK | RCC_CLOCKTYPE_SYSCLK | RCC_CLOCKTYPE_PCLK1 | RCC_CLOCKTYPE_PCLK2;
    RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
    RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
    RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV2;
    RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

    if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_2) != HAL_OK)
    {
        Error_Handler();
    }
    PeriphClkInit.PeriphClockSelection = RCC_PERIPHCLK_USART2;
    PeriphClkInit.Usart2ClockSelection = RCC_USART2CLKSOURCE_PCLK1;
    if (HAL_RCCEx_PeriphCLKConfig(&PeriphClkInit) != HAL_OK)
    {
        Error_Handler();
    }
}

/* USER CODE BEGIN 4 */

/* USER CODE END 4 */

/**
 * @brief  Period elapsed callback in non blocking mode
 * @note   This function is called  when TIM17 interrupt took place, inside
 * HAL_TIM_IRQHandler(). It makes a direct call to HAL_IncTick() to increment
 * a global variable "uwTick" used as application time base.
 * @param  htim : TIM handle
 * @retval None
 */
void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
{
    /* USER CODE BEGIN Callback 0 */

    /* USER CODE END Callback 0 */
    if (htim->Instance == TIM17)
    {
        HAL_IncTick();
    }
    /* USER CODE BEGIN Callback 1 */

    /* USER CODE END Callback 1 */
}

/**
 * @brief  This function is executed in case of error occurrence.
 * @retval None
 */
void Error_Handler(void)
{
    /* USER CODE BEGIN Error_Handler_Debug */
    /* User can add his own implementation to report the HAL error return state */
    __disable_irq();
    while (1)
    {
    }
    /* USER CODE END Error_Handler_Debug */
}

#ifdef USE_FULL_ASSERT
/**
 * @brief  Reports the name of the source file and the source line number
 *         where the assert_param error has occurred.
 * @param  file: pointer to the source file name
 * @param  line: assert_param error line source number
 * @retval None
 */
void assert_failed(uint8_t *file, uint32_t line)
{
    /* USER CODE BEGIN 6 */
    /* User can add his own implementation to report the file name and line number,
       ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
    /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
#endif
