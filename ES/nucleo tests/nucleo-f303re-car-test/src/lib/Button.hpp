#ifndef LIB_BUTTON_HPP_
#define LIB_BUTTON_HPP_

#include "Interfaces/IButton.hpp"
#include "MsgQueueData.hpp"
#include "NucleoPin.hpp"

#include "cmsis_os2.h"

#include <functional>

class Button : public IButton {
public:
    Button() = default;
    Button(NucleoPin inputPin, IRQn_Type irq, osMessageQueueId_t id);//, std::function<void()> actionShort, std::function<void()> actionLong);
    Button(const Button& other);
    ~Button() override;

    Button& operator=(const Button& other);

    bool SetupIrq() override;
    void HandleIrq() override;
    void ShortPress() override;
    void LongPress() override;

private:
    NucleoPin btnPin;
    IRQn_Type irq{ IRQn_Type::HardFault_IRQn };
    volatile bool triggered{ false };
    uint32_t startTime{ 0 };
    osMessageQueueId_t id{ nullptr };
    BtnMsgData data{};
    // std::function<void()> shortPressFunc;
    // std::function<void()> longPressFunc;
};

#endif
