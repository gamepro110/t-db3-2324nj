#include "lib/print.h"

#include "main.h"
#include "cmsis_os.h"
#include "usart.h"
#include "gpio.h"
#include <string.h>
#include <stdio.h>

void SystemClock_Config(void);
void MX_FREERTOS_Init(void);

int main(void)
{
    HAL_Init();
    SystemClock_Config();
    MX_GPIO_Init();
    MX_USART2_UART_Init();

    // enable timer 2
    RCC->APB1ENR |= RCC_APB1ENR_TIM2EN;

    // set prescaler
    // 7.2 MHz / 72 = 100 KHz
    TIM2->PSC = 72 - 1;
    
    // set auto-reload register for desired time period
    // 100 KHz / 2000 = 50 Hz
    TIM2->ARR = 20000 - 1;

    // TIM2->CCMR1 (capture/compare mode register)
    // Set CCMR to output mode
    TIM2->CCMR1 = (
        (TIM2->CCMR1 & ~0b11) |
        (0b00 << 0)
    );

    // const uint32_t outputCM1Offset = 4;
    // const uint32_t outputCM1ResetValue = 0b1111;
    // const uint32_t outputModeCM1 = 0b0110;
    // // set output mode to pwm
    // TIM2->CCMR1 = (
    //     (TIM2->CCMR1 & ~(outputCM1ResetValue << outputCM1Offset)) |
    //     (outputModeCM1 << outputCM1Offset)
    // );

    TIM2->CCMR1 |= TIM_CCMR1_OC1M_1 | TIM_CCMR1_OC1M_2;

    //TIM_CCER_CC1E
    // enable CCR1 as output
    TIM2->CCER = (
        (TIM2->CCER & ~(0b1UL << 0U)) |
        (0b1 << 0)
    );

    // set capture/compare 1 output polarity to active high
    TIM2->CCER = (
        (TIM2->CCER & ~(0b1UL << 1U)) |
        (0b0 << 1)
    );
    
    TIM2->CCR1 = 1280;

    // start timer (timer_ControlRegister_ClockENable)
    TIM2->CR1 |= TIM_CR1_CEN;

    // set pin 5 to alternate function mode
    GPIOA->MODER = (
        (GPIOA->MODER & ~GPIO_MODER_MODER5) |
        (0b10 << GPIO_MODER_MODER5_Pos)
    );

    // set alt func mode AF1
    GPIOA->AFR[0] = (
        (GPIOA->AFR[0] & ~(GPIO_AFRL_AFRL5)) |
        (0b0001 << GPIO_AFRL_AFRL5_Pos)
    );
    //GPIO_AF1_TIM2;

    vprint("Hello World!\n");
    const int MSGBUFSIZE = 100;
    char msgBuf[MSGBUFSIZE];

    while (1) {
        snprintf(msgBuf, MSGBUFSIZE, "TIM2: %lu\n", TIM2->CNT);
        vprint(msgBuf);
    }
}

#if 1 // hiding

/**
* @brief System Clock Configuration
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

/**
 * @brief  Period elapsed callback in non blocking mode
 * @note   This function is called  when TIM17 interrupt took place, inside
 * HAL_TIM_IRQHandler(). It makes a direct call to HAL_IncTick() to increment
 * a global variable "uwTick" used as application time base.
 * @param  htim : TIM handle
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
#endif
