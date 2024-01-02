#include "lib/Logger.hpp"
#include "lib/MsgQueueData.hpp"
#include "lib/Watchdog.hpp"
#include "lib/CarSystem.hpp"

#include "FreeRTOS.h"
#include "task.h"
#include "main.h"
#include "cmsis_os.h"
#include <string.h>
#include <stdio.h>

extern UART_HandleTypeDef huart2;

extern osMessageQueueId_t distMsgQId;
extern osMessageQueueId_t btnMsgQId;
extern ManualControlPanel mcp;
extern CarSystem carSys;
extern Watchdog wd;

extern IButton* iBut_a;
extern IButton* iBut_b;

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

osThreadId_t mcpTaskHandle;
const osThreadAttr_t mcpTask_attr {
    .name = "MCP"
};

osThreadId_t carSysTaskHandle;
const osThreadAttr_t carSysTask_attr {
    .name = "CarSys"
};

osThreadId_t tmpReceiveTaskHandle;
const osThreadAttr_t tmpReceiveTask_attr {
    .name = "tmpReceive"
};

void TmpReveiveTask(void* argument);
void StartMcpTask(void* argument);
void StartCarSysTask(void *argument);
void StartDefaultTask(void *argument);
void MX_FREERTOS_Init(void); /* (MISRA C 2004 rule 8.1) */

void MX_FREERTOS_Init(void) {
    defaultTaskHandle =     osThreadNew(StartDefaultTask, nullptr, &defaultTask_attributes);
    mcpTaskHandle =         osThreadNew(StartMcpTask, nullptr, &mcpTask_attr);
    carSysTaskHandle =      osThreadNew(StartCarSysTask, nullptr, &carSysTask_attr);
    tmpReceiveTaskHandle =  osThreadNew(TmpReveiveTask, nullptr, &tmpReceiveTask_attr);
}

void TmpReveiveTask(void* argument) {
    SensorMsgData dataSensor{};
    BtnMsgData dataBtn{};
    uint8_t prio{};
    const int MSGBUFSIZE = 40;
    char msgBuf[MSGBUFSIZE];

    while (1) {
        // snprintf(msgBuf, MSGBUFSIZE, "active irq: 0x%06x---\t", NVIC_GetActive(EXTI1_IRQn));
        // HAL_UART_Transmit(&huart2, (uint8_t *)msgBuf, strlen(msgBuf), HAL_MAX_DELAY);

        if (osMessageQueueGet(distMsgQId, &dataSensor, &prio, 0) == osOK) {
            snprintf(msgBuf, MSGBUFSIZE, "^:% 3d---\r", dataSensor.distance);
            HAL_UART_Transmit(&huart2, (uint8_t *)msgBuf, strlen(msgBuf), HAL_MAX_DELAY);
        }
        if (osMessageQueueGet(btnMsgQId, &dataBtn, &prio, 0) == osOK) {
            snprintf(msgBuf, MSGBUFSIZE, "\n% 1d:% 4d---\n", dataBtn.butNr, dataBtn.Duration);
            HAL_UART_Transmit(&huart2, (uint8_t *)msgBuf, strlen(msgBuf), HAL_MAX_DELAY);
        }
        osDelay(1);
    }
}

void StartMcpTask(void* argument) {
    if (!mcp.Setup()) {
        logger.Log("failed setting up MCP");
        osThreadExit();
        return;
    }

    while (1) {
        mcp.Loop();
    }
}

void StartCarSysTask(void *argument) {
    if (!carSys.Setup()) {
        const int MSGBUFSIZE = 40;
        char msgBuf[MSGBUFSIZE];
        snprintf(msgBuf, MSGBUFSIZE, "%s", "failed carSys setup!\n");
        HAL_UART_Transmit(&huart2, (uint8_t *)msgBuf, strlen(msgBuf), HAL_MAX_DELAY);
        osThreadExit();
    }

    while (1) {
        carSys.Update();
    }
}

void StartDefaultTask(void *argument) {
    while (1) {
        osDelay(1);
    }
}

//! irq' are broken inside freeRtos??
extern "C" void EXTI0_IRQHandler(void) {
    // if (EXTI->PR & EXTI_PR_PR0) {
        EXTI->PR |= EXTI_PR_PR0;

        if (iBut_a != nullptr) {
            iBut_a->HandleIrq();
        }
    // }
}

extern "C" void EXTI1_IRQHandler(void) {
    // if (EXTI->PR & EXTI_PR_PR1) {
        EXTI->PR |= EXTI_PR_PR1;

        if (iBut_b != nullptr) {
            iBut_b->HandleIrq();
        }
    // }
}