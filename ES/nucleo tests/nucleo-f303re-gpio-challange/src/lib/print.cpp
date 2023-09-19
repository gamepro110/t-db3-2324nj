#include "print.h"

void voidPrint(const char *msg)
{
    const uint8_t MSGBUFSIZE{ 100 };
    char msgBuf[MSGBUFSIZE];
    snprintf(msgBuf, MSGBUFSIZE, "%s\n", msg);
    HAL_UART_Transmit(&huart2, (uint8_t *)msgBuf, strlen(msgBuf), HAL_MAX_DELAY);
}
