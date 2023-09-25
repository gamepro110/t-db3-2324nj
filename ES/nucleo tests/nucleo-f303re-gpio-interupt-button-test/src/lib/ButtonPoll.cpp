#include "ButtonPoll.h"

#include <stdio.h>

ButtonPoll::ButtonPoll(GPIO_TypeDef *block, uint8_t pin)
    : block(block), pin(pin)
{
    block->MODER = (
        (block->MODER & ~(0b00 << (2 * pin))) |
        (0b00 << (2 * pin))
    );

    block->PUPDR = (
        (block->PUPDR & (0b00 << (2* pin))) |
        (0b01 << (2 * pin))
    );
}

ButtonPoll::~ButtonPoll()
{
}

void ButtonPoll::GetButtonAction(buttonAction &action)
{
    bool isPressed = IsButtonPressed();

    if (isPressed && !logicEntered) { // btn press start
        logicEntered = true;
        startTime = HAL_GetTick();
    }
    else if (!isPressed && logicEntered) { // btn press end
        logicEntered = false;
        uint32_t delta = HAL_GetTick() - startTime;

        if (delta > 20 && delta < 500) {
            action = buttonAction::pressShort;
        }
        else if (delta > 500) {
            action = buttonAction::pressLong;
        }
    }
}

bool ButtonPoll::IsButtonPressed() const
{
    return (block->IDR & (1 << pin)) == 0;
}
