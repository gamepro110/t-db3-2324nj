#ifndef LIB_LOGGER_HPP_
#define LIB_LOGGER_HPP_

#if STM32
#   include "cmsis_os2.h"
#endif

class Logger final {
public:
    ~Logger() = default;                                 // dtor
    Logger() = default;                                  // ctor
    Logger(const Logger&) = delete;                     // copy ctor
    Logger(const Logger&&) = delete;                    // move ctor
    Logger& operator=(const Logger&) = delete;          // copy assignment
    Logger& operator=(const Logger&&) = delete;         // move assignment

    void Log(const char* str);
    void Logf(const char* str, ...);
    void Error(const char* str);

private:
#if STM32
    osMutexId_t mux{ osMutexNew(nullptr) };
#endif
};

extern Logger logger;

#endif
