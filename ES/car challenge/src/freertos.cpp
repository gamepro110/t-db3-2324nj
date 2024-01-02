#include "lib/MsgQueueData.hpp"
#include "lib/Logger.hpp"
#include "lib/Watchdog.hpp"
#include "lib/CarSystem.hpp"
#include "lib/Interfaces/IDistanceSensor.hpp"
#include "lib/ManualControlPanel.hpp"

#include "FreeRTOS.h"
#include "task.h"
#include "main.h"
#include "cmsis_os.h"
#include <string.h>
#include <stdio.h>

extern UART_HandleTypeDef huart2;

extern osMessageQueueId_t sensorQueueId;
extern Watchdog watchdog;
extern CarSystem carSystem;

osThreadId_t threadWatchdog;
osThreadId_t threadCarSys;
osThreadId_t threadTempReceiver;
osThreadId_t threadMCP;
osThreadId_t threadThing;
osThreadId_t defaultTaskHandle;

const osThreadAttr_t CarSysTask_attributes = {
    .name = "carSysTask",
};
const osThreadAttr_t watchdogTask_attributes = {
    .name = "watchdogTask"
};

void MX_FREERTOS_Init(void); /* (MISRA C 2004 rule 8.1) */

void carSysThreadFunc(void* arg);
void mcpThreadFunc(void* arg);
void watchdogTaskFunc(void* arg);
void receiveSensorFunc(void* arg) {
    if (sensorQueueId == nullptr) {
        osThreadExit();
        return;
    }

    SensorMsgData data{ };
    uint8_t priority{ 0 };

    while (1) {
        if (osMessageQueueGet(sensorQueueId, &data, &priority, osWaitForever) == osOK) {
            logger.Logf("dist:% 3d", data.distance);
        }
    }
}

void MX_FREERTOS_Init(void) {
    threadWatchdog =        osThreadNew(watchdogTaskFunc, nullptr, &watchdogTask_attributes);
    threadCarSys =          osThreadNew(carSysThreadFunc, nullptr, &CarSysTask_attributes);
    threadTempReceiver =    osThreadNew(receiveSensorFunc, nullptr, nullptr);
}

void carSysThreadFunc(void* arg) {
    if (!carSystem.Setup()) {
        logger.Error("failed to setup CarSys");
        osThreadExit();
    }

    while (1) {
        carSystem.Update();
    }

    osThreadExit();
}

void watchdogTaskFunc(void* arg) {
    while (1) {
        watchdog.Reset();
    }

    osThreadExit();
}
