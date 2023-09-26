#include "ButtonIrq.h"

#include "usart.h"
#include "string.h"
#include "stdio.h"

ButtonIrq::ButtonIrq(GPIO_TypeDef *block, uint8_t pin, EdgeIRQType edgeType, IRQn_Type irqn, volatile uint32_t* exticr, uint32_t exticrMask) :
    block(block), pin(pin)
{
    block->MODER = (
        (block->MODER & ~(0b00 << (2* pin))) |
        (0b00 << (2 * pin))
    );

    block->PUPDR = (
        (block->PUPDR & (0b00 << (2 * pin))) |
        (0b01 << (2 * pin))
    );

    (*exticr) |= exticrMask;

    if (edgeType == EdgeIRQType::Rising || edgeType == EdgeIRQType::Both)
    {
        EXTI->RTSR |= (1 << pin);
    }

    if (edgeType == EdgeIRQType::Falling || edgeType == EdgeIRQType::Both)
    {
        EXTI->FTSR |= (1 << pin);
    }

    NVIC_EnableIRQ(irqn);
}

ButtonIrq::~ButtonIrq()
{
}
