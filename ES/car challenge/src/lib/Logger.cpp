#include "Logger.hpp"

#include <cstdarg>
#include <cstring>
#include <cstdint>
#include <cstdio>

#if STM32
#include "usart.h"
#endif

#define LOGGER_ENABLE_COLOR 0

Logger logger;

void Logger::Log(const char *str) {
    const int MSGBUFSIZE = 40;
    char msgBuf[MSGBUFSIZE];
    snprintf(msgBuf, MSGBUFSIZE, "%s", str);

#if STM32
    if (osMutexAcquire(mux, 10) == osOK) {
        HAL_UART_Transmit(&huart2, (uint8_t *)msgBuf, strlen(msgBuf), HAL_MAX_DELAY);
        osMutexRelease(mux);
    }

#   else

    printf("%s", msgBuf);

#   endif
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
#   if LOGGER_ENABLE_COLOR
    Log("\n\033[31;41m[ERROR]:");
#   else
    Log("\n[ERROR]:");
#   endif

    Log(str);

#   if LOGGER_DISABLE_COLOR
    Log("\033[39;49m");
#   endif
}
