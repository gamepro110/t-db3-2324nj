#include "IrqEncoder.h"

IrqEncoder::IrqEncoder(GPIO_TypeDef *blockClk, uint8_t clkPin, GPIO_TypeDef *blockDt, uint8_t dtPin, IRQn_Type irq) :
    blockClk(blockClk),
    pinClk(clkPin),
    blockDt(blockDt),
    pinDt(dtPin),
    irq(irq),
    position(0)
{
}

IrqEncoder::~IrqEncoder()
{
}

void IrqEncoder::Init()
{
    SetPinToInput(blockClk, pinClk);
    SetPinToInput(blockDt, pinDt);

    uint32_t exti_idx = pinClk / 4;
    uint32_t exti_shift = (pinClk % 4) * 4;

    int irqPinBlock = 0;

    if (blockClk == GPIOA)
    {
        irqPinBlock = 0b000;
    }
    else if (blockClk == GPIOB)
    {
        irqPinBlock = 0b001;
    }
    else if (blockClk == GPIOC)
    {
        irqPinBlock = 0b010;
    }
    else if (blockClk == GPIOD)
    {
        irqPinBlock = 0b011;
    }
    else if (blockClk == GPIOE)
    {
        irqPinBlock = 0b100;
    }
    else if (blockClk == GPIOF)
    {
        irqPinBlock = 0b101;
    }
    else if (blockClk == GPIOG)
    {
        irqPinBlock = 0b110;
    }
    else if (blockClk == GPIOH)
    {
        irqPinBlock = 0b111;
    }

    SYSCFG->EXTICR[exti_idx] = (
        (SYSCFG->EXTICR[exti_idx] & ~(0xf << exti_shift)) |
        (irqPinBlock << exti_shift)
    );

    // Configure EXTI to trigger on the specified edge
    EXTI->FTSR |= (1 << pinClk);

    // Enable EXTI interrupt
    EXTI->IMR |= (1 << pinClk);

    // Enable the EXTI interrupt in NVIC
    NVIC_EnableIRQ(irq);
}

void IrqEncoder::HandleIrq() volatile
{
    //TODO implement
    position += ((blockDt->IDR & (1 << pinDt)) == 0) ? 1 : -1;
}

const uint32_t &IrqEncoder::GetPosition() const
{
    return position;
}

void IrqEncoder::SetPinToInput(GPIO_TypeDef *block, uint8_t pin)
{
    block->MODER = (
        (block->MODER & ~(0b11 << (pin * 2))) |
        (0b00 << (2 * pin))
    );

    block->PUPDR = (
        (block->PUPDR & ~(0b11 << (pin * 2))) |
        (0b01 << (2 * pin))
    );
}
