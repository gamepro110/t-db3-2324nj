#include "IrqButton.h"

IrqButton::IrqButton(GPIO_TypeDef *block, uint8_t pin, IRQn_Type irq, uint32_t edge, std::function<void()> pressShort, std::function<void()> pressLong) :
    block(block), pin(pin), irq(irq), edge(edge), pressShort(pressShort), pressLong(pressLong)
{
}

IrqButton::~IrqButton()
{
}

void IrqButton::init()
{
    configureGPIO();
    configureIRQ();
}

void IrqButton::handle()
{
    if(pressHandled)
    {
        return;
    }

    uint32_t delta = pressEnd - pressStart;
    if (delta > 20 && delta < 500)
    {
        pressShort();
    }
    else if (delta > 500)
    {
        pressLong();
    }
}

void IrqButton::SetPressStart(uint32_t time)
{
    pressStart = time;
}

void IrqButton::SetPressEnd(uint32_t time)
{
    pressEnd = time;
}

void IrqButton::configureGPIO()
{
    block->MODER &= ~(1 << (pin * 2));
    block->PUPDR |= (1 << (pin * 2));
}

void IrqButton::configureIRQ()
{
    uint32_t exti_idx = pin / 4;
    uint32_t exti_shift = (pin % 4) * 4;

    SYSCFG->EXTICR[exti_idx] &= ~(0xF << exti_shift);
    SYSCFG->EXTICR[exti_idx] |= (0x0 << exti_shift);

    // Configure EXTI to trigger on the specified edge
    if (edge == EXTI_TRIGGER_RISING)
    {
        EXTI->RTSR |= (1 << pin);
    }
    else if (edge == EXTI_TRIGGER_FALLING)
    {
        EXTI->FTSR |= (1 << pin);
    }
    //TODO update to enum
    else if (edge == (EXTI_TRIGGER_RISING | EXTI_TRIGGER_FALLING))
    {
        EXTI->RTSR |= (1 << pin);
        EXTI->FTSR |= (1 << pin);
    }

    // Enable EXTI interrupt
    EXTI->IMR |= (1 << pin);

    // Enable the EXTI interrupt in NVIC
    //TODO fix hardcoded variant
    NVIC_EnableIRQ(EXTI1_IRQn);
}
