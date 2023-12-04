#include "Receiver.h"

#include <stm32f3xx_hal_uart.h>
#include <string.h>
#include <stdio.h>

extern UART_HandleTypeDef huart2;

void Receiver::Setup(osMessageQueueId_t id) {
    this->queueId = id;
}

void Receiver::Loop() {
    while(1) {
        QueueData data{ };
        const int MSGBUFSIZE = 80;
        char msgBuf[MSGBUFSIZE];

        if (osMessageQueueGet(queueId, (void*)&data, 0, 10) == osOK) {
            snprintf(msgBuf, MSGBUFSIZE, "button: 0x%x time: 0x%x\n", data.buttonId, data.pressDuration);
            HAL_UART_Transmit(&huart2, (uint8_t *)msgBuf, strlen(msgBuf), HAL_MAX_DELAY);
        }

        osDelay(10);
    }
}
