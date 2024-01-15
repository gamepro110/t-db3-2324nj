#include "lib/Logger.hpp"
#include "lib/MsgQueueData.hpp"
#include "lib/CarSystem.hpp"
#include "lib/MotorController.hpp"
#include "lib/Watchdog.hpp"

#include "FreeRTOS.h"
#include "task.h"
#include "main.h"
#include "cmsis_os.h"
#include <string.h>
#include <stdio.h>

extern UART_HandleTypeDef huart2;

extern osMessageQueueId_t distMsgQId;
extern osMessageQueueId_t btnMsgQId;
extern osMessageQueueId_t logMsgQId;

extern ManualControlPanel mcp;
extern MotorController controller;
extern CarSystem carSys;

extern Watchdog wd;

extern IButton* iBut_a;
extern IButton* iBut_b;

osThreadId_t mcpTaskHandle;
const osThreadAttr_t mcpTask_attr {
    .name = "MCP",
    .attr_bits = 0,
    .cb_mem = nullptr,
    .cb_size = 0,
    .stack_mem = nullptr,
    .stack_size = 512 * 4,
    .priority = (osPriority_t)osPriorityNormal,
    .tz_module = 0,
    .reserved = 0,
};

osThreadId_t carSysTaskHandle;
const osThreadAttr_t carSysTask_attr {
    .name = "CarSys"
};

osThreadId_t motorCtlTaskHandle;
const osThreadAttr_t motorCtlTask_attr {
    .name = "motor controller",
    .attr_bits = 0,
    .cb_mem = nullptr,
    .cb_size = 0,
    .stack_mem = nullptr,
    .stack_size = 512 * 4,
    .priority = (osPriority_t)osPriorityNormal,
    .tz_module = 0,
    .reserved = 0,
};

void StartMcpTask(void* argument);
void StartCarSysTask(void *argument);
void StartMotorCtlTask(void *argument);
void MX_FREERTOS_Init(void); /* (MISRA C 2004 rule 8.1) */

void MX_FREERTOS_Init(void) {
    mcpTaskHandle =         osThreadNew(StartMcpTask, nullptr, &mcpTask_attr);
    carSysTaskHandle =      osThreadNew(StartCarSysTask, nullptr, &carSysTask_attr);

    // disabling this thread stops triggering the hardfault
    motorCtlTaskHandle =    osThreadNew(StartMotorCtlTask, nullptr, &motorCtlTask_attr);
}

void StartMcpTask(void* argument) {
    while (1) {
        mcp.Loop();
    }
}

void StartCarSysTask(void *argument) {
    while (1) {
        carSys.Update();
    }
}

void StartMotorCtlTask(void* argument) {
    while (1) {
        controller.Loop();
    }
}

extern "C" void EXTI0_IRQHandler(void) {
    if (EXTI->PR & EXTI_PR_PR0) {
        EXTI->PR |= EXTI_PR_PR0;

        if (iBut_a != nullptr) {
            iBut_a->HandleIrq();
        }
    }
}

extern "C" void EXTI1_IRQHandler(void) {
    if (EXTI->PR & EXTI_PR_PR1) {
        EXTI->PR |= EXTI_PR_PR1;

        if (iBut_b != nullptr) {
            iBut_b->HandleIrq();
        }
    }
}
