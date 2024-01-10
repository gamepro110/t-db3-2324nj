#ifndef LIB_MANUALCONTROLPANEL_HPP_
#define LIB_MANUALCONTROLPANEL_HPP_

#include "Interfaces/IButton.hpp"
#include "lib/MsgQueueData.hpp"

#include "cmsis_os2.h"

class ManualControlPanel {
public:
    ManualControlPanel() = default;
    ManualControlPanel(osMessageQueueId_t btnId, IButton& btn1, IButton& btn2);
    ManualControlPanel(const ManualControlPanel& other);
    ~ManualControlPanel();

    ManualControlPanel& operator=(const ManualControlPanel& other);

    bool Setup();
    void Loop();

private:
    void HandleButtonSelect(const BtnMsgData& data);
    void CallButtonAction(const BtnMsgData& data, IButton& btn);

    osMessageQueueId_t btnQueueId{ nullptr };
    IButton* button0{ nullptr };
    IButton* button1{ nullptr };
    BtnMsgData btnData{};
    //TODO LogMsgData logData{};
};

#endif
