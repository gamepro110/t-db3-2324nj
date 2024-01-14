#include "Logger.hpp"

#include <cstdarg>
#include <cstring>
#include <cstdint>
#include <cstdio>

#include "usart.h"

Logger logger;

void Logger::Log(const char *str) {
    const int MSGBUFSIZE = 40;
    char msgBuf[MSGBUFSIZE];
    snprintf(msgBuf, MSGBUFSIZE, "%s", str);

    if (osMutexAcquire(mux, 10) == osOK) {
        HAL_UART_Transmit(&huart2, (uint8_t *)msgBuf, strlen(msgBuf), HAL_MAX_DELAY);
        osMutexRelease(mux);
    }
}

void Logger::Logf(const char *str, ...) {
    const int MSGBUFSIZE = 80;
    char msgBuf[MSGBUFSIZE];

    std::va_list args;
    va_start(args, str);
    vsniprintf(msgBuf, MSGBUFSIZE, str, args);
    Logger::Log(msgBuf);
}

void Logger::Error(const char *str) {
    Log("\n[ERROR]:");
    Log(str);
}
