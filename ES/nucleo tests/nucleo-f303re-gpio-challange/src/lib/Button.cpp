#include "Button.h"

#include "print.h"

#include <stdio.h>

Button::Button(GPIO_TypeDef *block, uint8_t pin, std::function<void()> shortPress, std::function<void()> longPress) :
    block(block),
    pin(pin),
    shortPressFunc(shortPress),
    longPressFunc(longPress)
{
}

Button::~Button()
{
}

void Button::init()
{
    //~GPIO_MODER_MODER0;
    //~GPIO_MODER_MODER0_Pos;
    block->MODER = (
        (block->MODER & ~(0b11 << (pin * 2))) |
        (0b00 << (2 * pin))
    );

    block->PUPDR = (
        (block->PUPDR & ~(0b11 << (pin * 2))) |
        (0b01 << (2 * pin))
    );
}

void Button::HandleButtonAction()
{
    if (triggered)
    {
        triggered = false;

        if (logicEntered)
        {
            logicEntered = false;
            uint32_t delta = HAL_GetTick() - startTime;

            if (delta > 500)
            {
                voidPrint("longFunc()");
                longPressFunc();
            }
            else if (delta > 20)
            {
                voidPrint("shortFunc()");
                shortPressFunc();
            }
        }
        else
        {
            logicEntered = true;
            startTime = HAL_GetTick();
        }
    }
}

void Button::HandleIrq() volatile
{
    triggered = true;
}

bool Button::IsButtonPressed() const
{
    return (block->IDR & (1 << pin)) == 0;
}
