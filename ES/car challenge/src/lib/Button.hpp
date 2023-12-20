#ifndef LIB_BUTTON_HPP_
#define LIB_BUTTON_HPP_

#include "Interfaces/IButton.hpp"
#include "NucleoPin.hpp"

#include <functional>

class Button : public IButton {
public:
    Button(NucleoPin inputPin, std::function<void()> actionShort, std::function<void()> actionLong);
    ~Button() override;

    void SetupIrq() override;
    void HandleIrq() override;
    void ShortPress() override;
    void LongPress() override;

private:
    const NucleoPin btnPin;
    std::function<void()> shortPressFunc;
    std::function<void()> longPressFunc;
};

#endif
