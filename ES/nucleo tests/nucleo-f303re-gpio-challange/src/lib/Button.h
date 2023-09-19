#ifndef LIB_BUTTON_H_
#define LIB_BUTTON_H_

#include "gpio.h"

enum class buttonAction {
    none = 0,
    pressShort,
    pressLong,
};

class Button
{
public:
    Button(GPIO_TypeDef* block, uint8_t pin);
    ~Button();

    void GetButtonAction(buttonAction& action);

private:
    bool IsButtonPressed() const;

    GPIO_TypeDef* block;
    uint8_t pin;
    bool logicEntered = false;
    uint32_t startTime = 0;
};

#endif
