#include "ButtonIrq.h"

#include "usart.h"
#include "string.h"
#include "stdio.h"

ButtonIrq::ButtonIrq(GPIO_TypeDef *block, uint8_t pin, EXTI_TypeDef* exti) :
    block(block), pin(pin)
{
    block->MODER = (
        (block->MODER & ~(0b00 << (2* pin))) |
        (0b00 << (2 * pin))
    );

    block->PUPDR = (
        (block->PUPDR & (0b00 << (2* pin))) |
        (0b01 << (2 * pin))
    );

    int interuptLine = 0;
    switch (pin)
    {
    case 1:
        interuptLine = 7;
        break;
    case 2:
        interuptLine = 8;
        break;
    case 3:
        interuptLine = 9;
        break;
    case 4:
        interuptLine = 10;
        break;

    // line 5-9 are one line 23
    case 5:
    case 6:
    case 7:
    case 8:
    case 9:
        interuptLine = 23;
        break;
    // line 10-15 are one line 40
    case 10:
    case 11:
    case 12:
    case 13:
    case 14:
    case 15:
        interuptLine = 40;
        break;
    case 0:
    default:
        interuptLine = 6;
        break;
    }

    //NVIC_EnableIRQ((IRQn_Type)interuptLine);
}

ButtonIrq::~ButtonIrq()
{
}
