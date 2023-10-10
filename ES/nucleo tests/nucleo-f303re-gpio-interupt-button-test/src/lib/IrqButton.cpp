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

void IrqButton::handleIrq()
{
    uint32_t tick = HAL_GetTick();

    if (!startedPress)
    {
        startedPress = true;
        SetPressStart(tick);
    }
    else
    {
        startedPress = false;
        SetPressEnd(tick);

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

    // SYSCFG->EXTICR[exti_idx] |= (
    //     ~(0xF << exti_shift) &
    //     (0x0 << exti_shift)
    // );

    int irqPinBlock = 0;
    //...
    if (block == GPIOA)
    {
        irqPinBlock = 0b000;
    }
    else if (block == GPIOB)
    {
        irqPinBlock = 0b001;
    }
    else if (block == GPIOC)
    {
        irqPinBlock = 0b010;
    }
    else if (block == GPIOD)
    {
        irqPinBlock = 0b011;
    }
    else if (block == GPIOE)
    {
        irqPinBlock = 0b100;
    }
    else if (block == GPIOF)
    {
        irqPinBlock = 0b101;
    }
    else if (block == GPIOG)
    {
        irqPinBlock = 0b110;
    }
    else if (block == GPIOH)
    {
        irqPinBlock = 0b111;
    }

    SYSCFG->EXTICR[exti_idx] = ( //TODO check if 0xf and 0x0 are correct
        (SYSCFG->EXTICR[exti_idx] & ~(0xf << exti_shift)) |
        (irqPinBlock << exti_shift)
    );

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
    NVIC_EnableIRQ(irq);
}
