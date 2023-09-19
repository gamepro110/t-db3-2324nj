#include "Led.h"

#include "print.h"

Led::Led(GPIO_TypeDef* block, uint8_t pin)
    : block(block), pin(pin)
{
    // set pin to output
    block->MODER = (
        (block->MODER & ~(0b00 << (pin * 2))) |
        ((0b01 << (2 * pin)))
    );

    // set pin output type to push-pull
    block->OTYPER &= ~(1 << pin);
}

Led::~Led()
{}

void Led::Toggle()
{
    block->ODR ^= (1 << pin);
    voidPrint("toggle led");
}

void Led::On()
{
    block->ODR |= (1 << pin);
}

void Led::Off()
{
    block->ODR &= ~(1 << pin);
}
