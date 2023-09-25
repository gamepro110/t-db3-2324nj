#ifndef LIB_BUTTONPOLL_H_
#define LIB_BUTTONPOLL_H_

#include "gpio.h"

enum class buttonAction {
    none = 0,
    pressShort,
    pressLong,
};

class ButtonPoll
{
public:
    //Button(GPIO_TypeDef* block, )

    /// @brief polling ctor
    /// @param block gpio block
    ButtonPoll(GPIO_TypeDef* block, uint8_t pin);
    ~ButtonPoll();

    void GetButtonAction(buttonAction& action);

private:
    bool IsButtonPressed() const;

    GPIO_TypeDef* block;
    uint8_t pin;
    bool logicEntered = false;
    uint32_t startTime = 0;
};

#endif
