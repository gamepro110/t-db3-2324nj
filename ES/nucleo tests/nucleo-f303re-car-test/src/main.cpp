#include "lib/MsgQueueData.hpp"
#include "lib/NucleoPin.hpp"

#include "lib/Interfaces/IButton.hpp"
#include "lib/Button.hpp"
#include "lib/ManualControlPanel.hpp"

#include "lib/CarSystem.hpp"
#include "lib/HC_SR04_DistSensor.hpp"

#include "lib/Interfaces/IMotor.hpp"
#include "lib/Interfaces/IFeedbackSensor.hpp"
#include "lib/ServoMotor.hpp"
#include "lib/FeedbackSensor.hpp"
#include "lib/MotorController.hpp"

#include "lib/Watchdog.hpp"

#include "main.h"
#include "cmsis_os.h"
#include "usart.h"
#include "gpio.h"

#include <string.h>
#include <stdio.h>

// Watchdog wd{ 1 << 11 };

osMessageQueueAttr_t distQueueAttr{
    .name = "distance message queue"
};
osMessageQueueAttr_t btnQueueAttr{
    .name = "button message queue"
};
osMessageQueueAttr_t logQueueAttr{
    .name = "log message queue"
};

osMessageQueueId_t distMsgQId{ nullptr };
osMessageQueueId_t btnMsgQId{ nullptr };
osMessageQueueId_t logMsgQId{ nullptr };

HC_SR04_DistSensor distSensor;
CarSystem carSys;

IButton* iBut_a{ nullptr };
IButton* iBut_b{ nullptr };
Button but_a;
Button but_b;
ManualControlPanel mcp;

ServoMotor servoLeft;
ServoMotor servoRight;
FeedbackSensor sensorLeft;
FeedbackSensor sensorRight;
MotorController controller;

void SystemClock_Config(void);
void MX_FREERTOS_Init(void);
void checkInit(const char* name, bool setupVal);

void btn0Long();
void btn0Short();

int main(void) {
    HAL_Init();
    SystemClock_Config();
    MX_GPIO_Init();
    MX_USART2_UART_Init();

    //<https://interrupt.memfault.com/blog/cortex-m-hardfault-debug#cortex-m3-m4-debug-trick>
    // uint32_t* ACTLR{ (uint32_t*)0xE000E008};
    // *ACTLR |= 1 << 1;

    /* Init scheduler */
    // ES Course Comments: Uncomment the three lines below to enable FreeRTOS.
    osKernelInitialize(); /* Call init function for freertos objects (in freertos.c) */
    //-----------------------------------------------------------------------
    HAL_Delay(1000); // delay for serial monitor to wake up
    logger.Log("Hello World!\n");

    while (distMsgQId == nullptr) {
        distMsgQId = osMessageQueueNew(20, sizeof(SensorMsgData), &distQueueAttr);
    }
    while (btnMsgQId == nullptr) {
        btnMsgQId = osMessageQueueNew(20, sizeof(BtnMsgData), &btnQueueAttr);
    }
    // while (logMsgQId == nullptr) {
    //     logMsgQId = osMessageQueueNew(20, sizeof(LogMsgData), &logQueueAttr);
    // }

    distSensor = HC_SR04_DistSensor{
        NucleoPin{ GPIOB, 6, 2 },
        NucleoPin{ GPIOB, 8, 2 },
        TIM4
    };
    checkInit("Dist Sensor", distSensor.Setup(72, 100000, 100, 3, 1, 2));

    but_a = Button{
        NucleoPin{ GPIOC, 0, PinMode::digital_input_pullup },
        EXTI0_IRQn,
        btnMsgQId,
        btn0Short,
        btn0Long
        // [&]{ btn0Short(); },
        // [&]{ btn0Long(); }
    };
    but_b = Button{
        NucleoPin{ GPIOC, 1, PinMode::digital_input_pullup },
        EXTI1_IRQn,
        btnMsgQId,
        nullptr,
        nullptr
        // [&](void){ logger.Log("btn1 short press\n"); },
        // [&](void){ logger.Log("btn1 long press\n"); }
    };

    iBut_a = &but_a;
    iBut_b = &but_b;

    mcp = ManualControlPanel{
        btnMsgQId,
        but_a,
        but_b
    };

    checkInit("mcp", mcp.Setup());

    bool direction{ true };
    HardwareTimer servoDriveTim{ TIM15 };
    servoDriveTim.SetEnablePeripheralClock();
    servoDriveTim.SetPrescaler(72);
    servoDriveTim.SetAutoReload(20000);

    servoLeft = ServoMotor{
        NucleoPin{ GPIOB, 14, 1 },
        servoDriveTim,
        1,
        !direction
    };
    servoRight = ServoMotor{
        NucleoPin{ GPIOB, 15, 1 },
        servoDriveTim,
        2,
        direction
    };

    sensorLeft = FeedbackSensor{
        NucleoPin{ GPIOA, 6, 2 },
        HardwareTimer{ TIM2 }
    };
    sensorRight = FeedbackSensor{
        NucleoPin{ GPIOA, 15, 1 },
        HardwareTimer{ TIM3 }
    };

    controller = MotorController{
        distMsgQId,
        15,
        servoLeft,
        servoRight,
        sensorLeft,
        sensorRight
    };

    mcp.SetPid(controller.getPid());

    checkInit("motor controller", controller.Setup());
    servoDriveTim.SetTimerEnable();
    controller.SetSpeed(0);

    carSys = CarSystem{
        distMsgQId,
        distSensor,
        mcp,
        controller
    };

    checkInit("carSys", carSys.Setup());

    //-----------------------------------
    MX_FREERTOS_Init();
    osKernelStart(); /* Start scheduler */

    /* We should never get here as control is now taken by the scheduler */
    /* Infinite loop
    const int MSGBUFSIZE = 80;
    char msgBuf[MSGBUFSIZE];
    while (1) {
        snprintf(msgBuf, MSGBUFSIZE, "%s", "In loop!\r\n");
        HAL_UART_Transmit(&huart2, (uint8_t *)msgBuf, strlen(msgBuf), HAL_MAX_DELAY);
    } //*/
}

void checkInit(const char* name, bool setupVal) {
    logger.Logf("setting up %-40s ", name);

    if (!setupVal) {
        logger.Error("failed!\n");
        return;
    }

    logger.Log("done\n");
}

void btn0Short() {
    controller.SetSpeed(0);
    logger.Log("set speed to 0");
}

void btn0Long() {
    controller.SetSpeed(100);
    logger.Log("set speed to 100");
}

#if 1 //hidden
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
#endif // hidden
