#ifndef LIB_BUTTON_H_
#define LIB_BUTTON_H_

#include "gpio.h"

#include <functional>

enum class buttonAction {
    none = 0,
    pressShort,
    pressLong,
};

class Button
{
public:
    Button(GPIO_TypeDef* block, uint8_t pin, std::function<void()> shortPress, std::function<void()> longPress);
    ~Button();

    void init();
    void HandleButtonAction();
    void HandleIrq();

private:
    bool IsButtonPressed() const;

    GPIO_TypeDef* block{ nullptr };
    uint8_t pin{ 0 };
    volatile bool triggered{ false };
    bool logicEntered{ false };
    uint32_t startTime{ 0 };
    std::function<void()> shortPressFunc;
    std::function<void()> longPressFunc;
};

#endif
