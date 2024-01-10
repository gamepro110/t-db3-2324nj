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
    .name = "MCP"
};

osThreadId_t carSysTaskHandle;
const osThreadAttr_t carSysTask_attr {
    .name = "CarSys"
};

osThreadId_t motorCtlTaskHandle;
const osThreadAttr_t motorCtlTask_attr {
    .name = "motor controller",
};

void StartMcpTask(void* argument);
void StartCarSysTask(void *argument);
void StartMotorCtlTask(void *argument);
void MX_FREERTOS_Init(void); /* (MISRA C 2004 rule 8.1) */

//! temp
osThreadId_t dbTask;
void dbLoop(void*) {
    const int MSGBUFSIZE = 80;
    char msgBuf[MSGBUFSIZE];

    osDelay(10);
    snprintf(
        msgBuf,
        MSGBUFSIZE,
        "tim15\nccer:% 5ld _ cr1:% 5ld _ cr2:% 5ld \n",
        TIM15->CCER, TIM15->CR1, TIM15->CR2
    );
    HAL_UART_Transmit(&huart2, (uint8_t *)msgBuf, strlen(msgBuf), HAL_MAX_DELAY);

    while (1) {
        // logger.Logf("tim15: % 6ld _ ccr1: % 3d", TIM15->CNT, TIM15->CCR1);
        snprintf(msgBuf, MSGBUFSIZE, "tim15:% 6ld _ ccer:% 5ld _ ccr1:% 5ld _ ccr2:% 3ld\r", TIM15->CNT, TIM15->CCER, TIM15->CCR1, TIM15->CCR2);
        HAL_UART_Transmit(&huart2, (uint8_t *)msgBuf, strlen(msgBuf), HAL_MAX_DELAY);
        osDelay(10);
    }
}
//! temp

void MX_FREERTOS_Init(void) {
    mcpTaskHandle =         osThreadNew(StartMcpTask, nullptr, &mcpTask_attr);
    carSysTaskHandle =      osThreadNew(StartCarSysTask, nullptr, &carSysTask_attr);
    motorCtlTaskHandle =    osThreadNew(StartMotorCtlTask, nullptr, &motorCtlTask_attr);
    dbTask =                osThreadNew(dbLoop, nullptr, nullptr);
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