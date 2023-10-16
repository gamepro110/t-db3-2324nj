/* USER CODE BEGIN Header */
/**
 ******************************************************************************
* @file           : main.c
* @brief          : Main program body
******************************************************************************
* @attention
*
* <h2><center>&copy; Copyright (c) 2021 STMicroelectronics.
* All rights reserved.</center></h2>
*
* This software component is licensed by ST under Ultimate Liberty license
* SLA0044, the "License"; You may not use this file except in compliance with
* the License. You may obtain a copy of the License at:
*                             www.st.com/SLA0044
*
******************************************************************************
*/
/* USER CODE END Header */
/* Includes ------------------------------------------------------------------*/
#include "lib/Led.h"
#include "lib/Button.h"
#include "lib/print.h"

#include "main.h"
#include "cmsis_os.h"
#include "usart.h"
#include "gpio.h"
#include <string.h>
#include <stdio.h>

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */
/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/

/* USER CODE BEGIN PV */

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
void MX_FREERTOS_Init(void);
/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */

void ledBlinkTimed(Led* led, const uint32_t delay, uint32_t& timer) {
    uint32_t ledNow = HAL_GetTick();
    if ((ledNow - timer) > delay) {
        timer = ledNow;
        led->Toggle();
    }
}

void LedLogic(buttonAction btnAction, Led& led, uint32_t& ledTimer, const uint32_t ledToggleTimeShort, const uint32_t ledToggleTimeLong) {
    switch (btnAction)
    {
    case buttonAction::pressShort: {
        ledBlinkTimed(&led, ledToggleTimeShort, ledTimer);
        break;
    }
    case buttonAction::pressLong: {
        ledBlinkTimed(&led, ledToggleTimeLong, ledTimer);
        break;
    }
    case buttonAction::none:
    default: {
        break;
    }
    }
}

volatile buttonAction btn1Action = (buttonAction)0;
volatile buttonAction btn2Action = (buttonAction)0;

void but1ShortPress()
{
    btn1Action = buttonAction::pressShort;
}

void but1LongPress()
{
    btn1Action = buttonAction::pressLong;
}

void but2ShortPress()
{
    btn2Action = buttonAction::pressShort;
}

void but2LongPress()
{
    btn2Action = buttonAction::pressLong;
}

Button but1(
    GPIOA, 0,
    but1ShortPress,
    but1LongPress
);
Button but2(
    GPIOA, 1,
    but2ShortPress,
    but2LongPress
);
/* USER CODE END 0 */

/**
* @brief  The application entry point.
* @retval int
*/
int main(void) {
    HAL_Init();
    SystemClock_Config();
    MX_GPIO_Init();
    MX_USART2_UART_Init();

    but1.init();
    but2.init();

    //setup irq
    // connect exti0 line to PA0
    SYSCFG->EXTICR[0] |= SYSCFG_EXTICR1_EXTI0_PA;
    // config extio to trigger on rising and falling edge edge
    EXTI->RTSR |= EXTI_RTSR_TR0;
    EXTI->FTSR |= EXTI_FTSR_TR0;
    // enable exti0 interrupt
    EXTI->IMR |= EXTI_IMR_MR0;
    NVIC_EnableIRQ(EXTI0_IRQn);

    //-----------------

    // connect exti0 line to PA1
    SYSCFG->EXTICR[0] |= SYSCFG_EXTICR1_EXTI1_PA;
    // config extio to trigger on rising and falling edge edge
    EXTI->RTSR |= EXTI_RTSR_TR1;
    EXTI->FTSR |= EXTI_FTSR_TR1;
    // enable exti1 interrupt
    EXTI->IMR |= EXTI_IMR_MR1;
    NVIC_EnableIRQ(EXTI1_IRQn);

    //

    Led led1{ GPIOA, 5 };
    Led led2{ GPIOA, 12 };

    uint32_t led1Timer = 0;
    uint32_t led2Timer = 0;
    const uint32_t ledToggleTimeShort = 200;
    const uint32_t ledToggleTimeLong = 800;

    /*
    Init scheduler
    ES Course Comments: Uncomment the three lines below to enable FreeRTOS.
    */
    //osKernelInitialize(); /* Call init function for freertos objects (in freertos.c) */
    //MX_FREERTOS_Init();
    //osKernelStart(); /* Start scheduler */

    /* We should never get here as control is now taken by the scheduler */
    /* Infinite loop */

    voidPrint("hello world\n");

    while (1) {
        but1.HandleButtonAction();
        but2.HandleButtonAction();

        LedLogic(
            btn1Action,
            led1,
            led1Timer,
            ledToggleTimeShort,
            ledToggleTimeLong
        );
        LedLogic(
            btn2Action,
            led2,
            led2Timer,
            ledToggleTimeShort,
            ledToggleTimeLong
        );
    }
}

extern "C" void EXTI0_IRQHandler(void)
{
    if (EXTI->PR & EXTI_PR_PR0)
    {
        EXTI->PR = EXTI_PR_PR0;
        but1.HandleIrq();
        voidPrint("irq 0");
    }
}

extern "C" void EXTI1_IRQHandler(void)
{
    if (EXTI->PR & EXTI_PR_PR1)
    {
        EXTI->PR = EXTI_PR_PR1;
        but2.HandleIrq();
        voidPrint("irq 1");
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
void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim) {
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
void Error_Handler(void) {
    /* USER CODE BEGIN Error_Handler_Debug */
    /* User can add his own implementation to report the HAL error return state */
    __disable_irq();
    while (1)
    {}
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
