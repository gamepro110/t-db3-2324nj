#include "ManualControlPanel.hpp"

#include "lib/Logger.hpp"

#include "cmsis_os2.h"

#include <cstdio>
#include <cstring>

ManualControlPanel::ManualControlPanel(osMessageQueueId_t btnId, IButton& btn0, IButton& btn1) :
    btnQueueId(btnId),
    button0(&btn0),
    button1(&btn1)
{}

ManualControlPanel::ManualControlPanel(const ManualControlPanel& other) :
    btnQueueId(other.btnQueueId),
    button0(other.button0),
    button1(other.button1)
{}

ManualControlPanel::~ManualControlPanel()
{}

ManualControlPanel &ManualControlPanel::operator=(const ManualControlPanel &other) {
    btnQueueId = other.btnQueueId;
    button0 = other.button0;
    button1 = other.button1;
    return *this;
}

bool ManualControlPanel::Setup() {
    return (button0->SetupIrq()
        && button1->SetupIrq()
    );
}

//TODO add serial input options
void ManualControlPanel::Loop() {
    uint8_t prio{0};
    if (osMessageQueueGet(btnQueueId, &btnData, &prio, 0) == osOK) {
        HandleButtonSelect(btnData);
    }

    uint8_t byte{ 0 };
    if (HAL_UART_Receive(&huart2, &byte, 1, 0) == HAL_OK) {
        buffer[bufIdx] = byte;
        bufIdx++;

        if (bufIdx >= BUFSIZE) {
            bufIdx = 0;
        }

        if (byte == '\n') {
            buffer[bufIdx] = '\000';
            uint8_t letter{ 0 };
            float num{ 0 };
            if (pid != nullptr && sscanf((char*)buffer, "%c%f", &letter, &num) != -1) {
                switch (letter)
                {
                case 'p':
                    pid->updateKP(num);
                    break;
                case 'i':
                    pid->updateKI(num);
                    break;
                case 'd':
                    pid->updateKD(num);
                    break;
                case '?': {
                    printPID = true;
                    break;
                }
                default:
                    break;
                }
            }
            bufIdx = 0;
        }
    }

    if (printPID) {
        printPID = false;
        const uint8_t MSGBUFSIZE{ 18 };
        char msgBuf[MSGBUFSIZE];
        snprintf(msgBuf, MSGBUFSIZE, "p%-5.2f_ ", pid->GetKP());
        HAL_UART_Transmit(&huart2, (uint8_t *)msgBuf, strlen(msgBuf), HAL_MAX_DELAY);
        snprintf(msgBuf, MSGBUFSIZE, "i%-5.2f_ ", pid->GetKI());
        HAL_UART_Transmit(&huart2, (uint8_t *)msgBuf, strlen(msgBuf), HAL_MAX_DELAY);
        snprintf(msgBuf, MSGBUFSIZE, "d%-5.2f\n", pid->GetKD());
        HAL_UART_Transmit(&huart2, (uint8_t *)msgBuf, strlen(msgBuf), HAL_MAX_DELAY);
    }

    osDelay(1);
}

void ManualControlPanel::HandleButtonSelect(const BtnMsgData& data) {
    switch (data.butNr)
    {
    case 0:
        CallButtonAction(data, *button0);
        break;
    case 1:
        CallButtonAction(data, *button1);
        break;
    default:
        break;
    }
}

void ManualControlPanel::CallButtonAction(const BtnMsgData& data, IButton& btn) {
    if (data.Duration > 20 && data.Duration < 500) {
        btn.ShortPress();
    }
    else if (data.Duration > 500) {
        btn.LongPress();
    }
}
