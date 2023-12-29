#ifndef LIB_BUTTON_HPP_
#define LIB_BUTTON_HPP_

#include "Interfaces/IButton.hpp"
#include "MsgQueueData.hpp"
#include "NucleoPin.hpp"

#include "cmsis_os2.h"

#include <functional>

class Button : public IButton {
public:
    Button(NucleoPin inputPin, IRQn_Type irq, osMessageQueueId_t id);//, std::function<void()> actionShort, std::function<void()> actionLong);
    ~Button() override;

    bool SetupIrq() override;
    void HandleIrq() override;
    void ShortPress() override;
    void LongPress() override;

private:
    const NucleoPin btnPin;
    IRQn_Type irq;
    volatile bool triggered{ false };
    uint32_t startTime{ 0 };
    const osMessageQueueId_t id;
    BtnMsgData data;
    // std::function<void()> shortPressFunc;
    // std::function<void()> longPressFunc;
};

#endif
