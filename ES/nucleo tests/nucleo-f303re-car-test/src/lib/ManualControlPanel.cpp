#include "ManualControlPanel.hpp"

#include "lib/Logger.hpp"

#include "cmsis_os2.h"

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
    if (osMessageQueueGet(btnQueueId, &btnData, nullptr, 0) == osOK) {
        HandleButtonSelect(btnData);
    }
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
