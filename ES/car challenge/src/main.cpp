#include "lib/Interfaces/IBtnIRQ.hpp"
#include "lib/Interfaces/IButton.hpp"
#include "lib/Interfaces/IDistanceSensor.hpp"
#include "lib/Interfaces/IFeedbackSensor.hpp"

#include "lib/CarSystem.hpp"
#include "lib/ManualControlPanel.hpp"
#include "lib/FeedbackSensor.hpp"
#include "lib/MotorController.hpp"
#include "lib/Button.hpp"
#include "lib/NucleoPin.hpp"
#include "lib/Pid.hpp"
#include "lib/ServoMotor.hpp"
#include "lib/HC_SR04_DistSensor.hpp"

#include "main.h"
#include "cmsis_os.h"
#include "usart.h"
#include "gpio.h"
#include <string.h>
#include <stdio.h>

#define USE_FREERTOS 0

void SystemClock_Config(void);
void MX_FREERTOS_Init(void);

struct MsgQueueData {
    int butNr;
    int Duration;
};

void vprint(const char* text) {
    const int MSGBUFSIZE = 80;
    char msgBuf[MSGBUFSIZE];
    snprintf(msgBuf, MSGBUFSIZE, "%s", text);
    HAL_UART_Transmit(&huart2, (uint8_t *)msgBuf, strlen(msgBuf), HAL_MAX_DELAY);
}

int main(void) {
    const int MSGBUFSIZE = 80;
    char msgBuf[MSGBUFSIZE];
    HAL_Init();
    SystemClock_Config();
    MX_GPIO_Init();
    MX_USART2_UART_Init();

    osMessageQueueId_t queueId = nullptr;

    while(queueId == NULL) {
        vprint("setting up queue");
        queueId = osMessageQueueNew(20, sizeof(MsgQueueData), nullptr);
    }

    CarSystem system{ queueId };

    Button button1 = Button({
        NucleoPin{ GPIOA, 0, PinMode::digital_input_pullup },
        []{},
        []{}
    });
    Button button2 = Button({
        NucleoPin{ GPIOA, 0, PinMode::digital_input_pullup },
        []{},
        []{}
    });
    Button button3 = Button({
        NucleoPin{ GPIOA, 0, PinMode::digital_input_pullup },
        []{},
        []{}
    });
    Button button4 = Button({
        NucleoPin{ GPIOA, 0, PinMode::digital_input_pullup },
        []{},
        []{}
    });

    ManualControlPanel controlPanel{ button1, button2, button3, button4 };

    NucleoPin pinMotorLeft = NucleoPin{ GPIOA, 0, PinMode::altMode };
    AltModeValue v{ 0U };
    pinMotorLeft.SetAltMode(v);
    ServoMotor motorLeft{ pinMotorLeft, false };

    NucleoPin pinMotorRight = NucleoPin{ GPIOA, 0, PinMode::altMode };
    pinMotorRight.SetAltMode(v);
    ServoMotor motorRight{ pinMotorRight, false };

    NucleoPin pinSensorLeft{ GPIOA, 0, PinMode::altMode };
    FeedbackSensor sensorLeft{
        pinSensorLeft,
    };

    NucleoPin pinSensorRight{ GPIOA, 0, PinMode::altMode };
    FeedbackSensor sensorRight{
        pinSensorRight,
    };

    MotorController motorController{
        motorLeft,
        motorRight,
        sensorLeft,
        sensorRight
    };//*/

    HC_SR04_DistSensor distSensor{
        NucleoPin{ GPIOA, 0, PinMode::altMode },
        NucleoPin{ GPIOA, 0, PinMode::altMode }
    };

#   if USE_FREERTOS
    const osThreadAttr_t defaultTask_attributes = {
        .name = "defaultTask",
        .attr_bits = osThreadDetached,
        .cb_mem = NULL,
        .cb_size = 0,
        .stack_mem = NULL,
        .stack_size = 128 * 4,
        .priority = (osPriority_t)osPriorityNormal,
        .tz_module = 0,
        .reserved = 0
    };


    /* Init scheduler */
    // ES Course Comments: Uncomment the three lines below to enable FreeRTOS.
    osKernelInitialize(); /* Call init function for freertos objects (in freertos.c) */

    // add threads

    osKernelStart(); /* Start scheduler */
#   endif

    /* We should never get here as control is now taken by the scheduler */
    /* Infinite loop */
    snprintf(msgBuf, MSGBUFSIZE, "%s", "Hello World!\r\n");
    HAL_UART_Transmit(&huart2, (uint8_t *)msgBuf, strlen(msgBuf), HAL_MAX_DELAY);

    while (1) {
        snprintf(msgBuf, MSGBUFSIZE, "%s", "In loop!\n");
        HAL_UART_Transmit(&huart2, (uint8_t *)msgBuf, strlen(msgBuf), HAL_MAX_DELAY);
        GPIOA->ODR ^= (1 << 5); // Toggle GPIO pin PA5 (onboard green LED).
        HAL_Delay(1000);
    }
}

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