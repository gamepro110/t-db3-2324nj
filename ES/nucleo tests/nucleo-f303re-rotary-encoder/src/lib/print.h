#ifndef LIB_PRINT_H_
#define LIB_PRINT_H_

#include <stdio.h>
#include <string.h>
#include <usart.h>

void vprint(const char* txt) {
    const int MSGBUFSIZE = 80;
    char msgBuf[MSGBUFSIZE];
    snprintf(msgBuf, MSGBUFSIZE, "%s", txt);
    HAL_UART_Transmit(&huart2, (uint8_t *)msgBuf, strlen(msgBuf), HAL_MAX_DELAY);
}

#endif
