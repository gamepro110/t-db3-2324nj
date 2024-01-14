#ifndef LIB_BUTTON_HPP_
#define LIB_BUTTON_HPP_

#include "Interfaces/IButton.hpp"
#include "MsgQueueData.hpp"
#include "NucleoPin.hpp"

#include "cmsis_os2.h"

#include <functional>

typedef void(*Action)(void);
// using Action = std::function<void()>;

class Button : public IButton {
public:
    Button() = default;
    Button(NucleoPin inputPin, IRQn_Type irq, osMessageQueueId_t id, Action actionShort, Action actionLong);
    Button(const Button& other);
    ~Button() override;

    Button& operator=(const Button& other);

    bool SetupIrq() override;
    void HandleIrq() override;
    void ShortPress() override;
    void LongPress() override;

private:
    NucleoPin btnPin;
    osMessageQueueId_t id{ nullptr };
    IRQn_Type irq{ IRQn_Type::HardFault_IRQn };
    volatile bool triggered{ false };
    volatile uint32_t startTime{ 0 };
    volatile BtnMsgData data{};
    // Action shortPressCallback{ []{} };
    // Action longPressCallback{ []{} };
    Action shortPressCallback{ nullptr };
    Action longPressCallback{ nullptr };
};

#endif
