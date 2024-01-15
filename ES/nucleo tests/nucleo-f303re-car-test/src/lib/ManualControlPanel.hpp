#ifndef LIB_MANUALCONTROLPANEL_HPP_
#define LIB_MANUALCONTROLPANEL_HPP_

#include "Interfaces/IButton.hpp"
#include "lib/MsgQueueData.hpp"
#include "Pid.hpp"

#include "cmsis_os2.h"
#include "usart.h"

const uint8_t BUFSIZE{ 50 };

class ManualControlPanel {
public:
    ManualControlPanel() = default;
    ManualControlPanel(osMessageQueueId_t btnId, IButton& btn1, IButton& btn2);
    ManualControlPanel(const ManualControlPanel& other);
    ~ManualControlPanel();

    ManualControlPanel& operator=(const ManualControlPanel& other);

    bool Setup();
    void Loop();
    void SetPid(PID& p) {
        pid = &p;
    }

private:
    void HandleButtonSelect(const BtnMsgData& data);
    void CallButtonAction(const BtnMsgData& data, IButton& btn);

    osMessageQueueId_t btnQueueId{ nullptr };
    IButton* button0{ nullptr };
    IButton* button1{ nullptr };
    BtnMsgData btnData{};
    uint8_t buffer[BUFSIZE];
    uint8_t bufIdx{ 0 };
    PID* pid;
    bool printPID{ false };
    //TODO LogMsgData logData{};
};

#endif
