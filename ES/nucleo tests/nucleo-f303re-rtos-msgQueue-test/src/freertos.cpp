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

#include <queue.h>

QueueHandle_t qh;

osThreadId_t senderThreadHandle;
osThreadId_t receiverThreadHandle;

struct queueData {
    uint16_t buttonId;
    uint16_t pressDuration;
};

class Sender {
public:
    Sender(QueueHandle_t& handle) :
        handleRef(handle)
    {}
    ~Sender() = default;

    void Loop() {
        while (1) {
            queueData data{ 0, 50 };
            xQueueSendToBack(handleRef, (void*)&data, 10);
            osDelay(5);
        }
    }

    QueueHandle_t& handleRef;
};

extern UART_HandleTypeDef huart2;

class Receiver {
public:
    Receiver(QueueHandle_t& handle) :
        handleRef(handle)
    {}
    ~Receiver() = default;

    void Loop() {
        while(1) {
            uint64_t val = uxQueueMessagesWaiting(handleRef); // xQueueReceive
            if (val == 0) {
                osDelay(10);
                return;
            }

            queueData data{ };
            if (xQueueReceive(handleRef,(void*)&data, 10) == pdTRUE) {
                const int MSGBUFSIZE = 80;
                char msgBuf[MSGBUFSIZE];
                snprintf(msgBuf, MSGBUFSIZE, "button: 0x%x time: 0x%x", data.buttonId, data.pressDuration);
                HAL_UART_Transmit(&huart2, (uint8_t *)msgBuf, strlen(msgBuf), HAL_MAX_DELAY);
            }

            osDelay(10);
        }
    }

    QueueHandle_t& handleRef;
};

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/
/* USER CODE BEGIN Variables */
// extern UART_HandleTypeDef huart2;
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

void ReceiverThread(void* arg) {
    Receiver* reciever = reinterpret_cast<Receiver*>(arg);
    reciever->Loop();
}

void SenderThread(void* arg) {
    Sender* sender = reinterpret_cast<Sender*>(arg);
    sender->Loop();
}

/* Private function prototypes -----------------------------------------------*/
/* USER CODE BEGIN FunctionPrototypes */

/* USER CODE END FunctionPrototypes */

void StartDefaultTask(void *argument);

void MX_FREERTOS_Init(void); /* (MISRA C 2004 rule 8.1) */

/**
 * @brief  FreeRTOS initialization
 * @param  None
 * @retval None
 */
void MX_FREERTOS_Init(void) {
    /* USER CODE BEGIN Init */
    do
    {
        const int MSGBUFSIZE = 80;
        char msgBuf[MSGBUFSIZE];
        snprintf(msgBuf, MSGBUFSIZE, "%s", "setting up queue\n");
        HAL_UART_Transmit(&huart2, (uint8_t *)msgBuf, strlen(msgBuf), HAL_MAX_DELAY);

        qh = xQueueCreate(15, sizeof(queueData)); //TODO infinite loop...
    } while (qh == NULL);

    Receiver rec{ qh };
    receiverThreadHandle = osThreadNew(ReceiverThread, (void*)&rec, &defaultTask_attributes);

    Sender sen{ qh };
    receiverThreadHandle = osThreadNew(SenderThread, (void*)&sen, &defaultTask_attributes);

    defaultTaskHandle = osThreadNew(StartDefaultTask, NULL, &defaultTask_attributes);
}

/* USER CODE BEGIN Header_StartDefaultTask */
/**
 * @brief  Function implementing the defaultTask thread.
 * @param  argument: Not used
 * @retval None
 */
/* USER CODE END Header_StartDefaultTask */
void StartDefaultTask(void *argument)
{
    /* USER CODE BEGIN StartDefaultTask */
    /* Infinite loop */
    for (;;)
    {
        osDelay(1);
    }
    /* USER CODE END StartDefaultTask */
}

/* Private application code --------------------------------------------------*/
/* USER CODE BEGIN Application */

/* USER CODE END Application */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
