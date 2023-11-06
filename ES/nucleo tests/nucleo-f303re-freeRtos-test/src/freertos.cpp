/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * File Name          : freertos.c
  * Description        : Code for freertos applications
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

#include "FreeRTOS.h"
#include "task.h"
#include "main.h"
#include "cmsis_os.h"
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
/* USER CODE BEGIN Variables */
extern UART_HandleTypeDef huart2;
/* USER CODE END Variables */
/* Definitions for defaultTask */
osThreadId_t defaultTaskHandle;
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

osThreadId_t ledTaskHandle;
const osThreadAttr_t ledTask_attributes = {
    .name = "LedTask",
    .attr_bits = osThreadDetached,
    .cb_mem = NULL,
    .cb_size = 0,
    .stack_mem = NULL,
    .stack_size = 128 * 4,
    .priority = (osPriority_t)osPriorityNormal,
    .tz_module = 0,
    .reserved = 0
};


/* Private function prototypes -----------------------------------------------*/
/* USER CODE BEGIN FunctionPrototypes */

/* USER CODE END FunctionPrototypes */

void StartDefaultTask(void *argument);
void StartLedTask(void *argument);

void MX_FREERTOS_Init(void); /* (MISRA C 2004 rule 8.1) */

/**
* @brief 
* 
* @param  None
* @retval None
*/
void MX_FREERTOS_Init(void) {

    ledTaskHandle = osThreadNew(StartLedTask, nullptr, &ledTask_attributes);
    defaultTaskHandle = osThreadNew(StartDefaultTask, NULL, &defaultTask_attributes);
}

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
void StartLedTask(void *argument) {
    Led led1{ GPIOA, 5 };
    Led led2{ GPIOA, 6 };

    buttonAction ba0{ buttonAction::pressShort };
    buttonAction ba1{ buttonAction::pressLong };

    uint32_t led1Timer{ 0 };
    uint32_t led2Timer{ 0 };
    
    for (;;) {
        LedLogic(ba0, led1, led1Timer, 300, 800);
        LedLogic(ba1, led2, led2Timer, 300, 800);
        osDelay(500);
    }
    
}

/* USER CODE BEGIN Header_StartDefaultTask */
/**
* @brief  Function implementing the defaultTask thread.
* @param  argument: Not used
* @retval None
*/
void StartDefaultTask(void *argument) {
    for (;;)
    {
        osDelay(1);
    }
}

/* Private application code --------------------------------------------------*/
/* USER CODE BEGIN Application */

/* USER CODE END Application */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
