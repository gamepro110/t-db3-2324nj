#include "Button.h"

Button::Button(GPIO_TypeDef *block, uint8_t pin, IRQn_Type irq, EdgeTrigger edge, std::function<void()> pressShort, std::function<void()> pressLong) :
    block(block), pin(pin), irq(irq), edge(edge), pressShort(pressShort), pressLong(pressLong)
{
}

Button::~Button()
{
}

void Button::init()
{
    configureGPIO();

    if (edge != EdgeTrigger::none)
    {
        configureIRQ();
    }
}

void Button::handleIrq()
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

void Button::SetPressStart(uint32_t time)
{
    pressStart = time;
}

void Button::SetPressEnd(uint32_t time)
{
    pressEnd = time;
}

void Button::configureGPIO()
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

void Button::configureIRQ()
{
    uint32_t exti_idx = pin / 4;
    uint32_t exti_shift = (pin % 4) * 4;

    int irqPinBlock = 0;

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

    SYSCFG->EXTICR[exti_idx] = (
        (SYSCFG->EXTICR[exti_idx] & ~(0xf << exti_shift)) |
        (irqPinBlock << exti_shift)
    );

    // Configure EXTI to trigger on the specified edge
    switch (edge)
    {
    case EdgeTrigger::Rising:
        EXTI->RTSR |= (1 << pin);
        break;
    case EdgeTrigger::Falling:
        EXTI->FTSR |= (1 << pin);
        break;
    case EdgeTrigger::RisingAndFalling:
        EXTI->RTSR |= (1 << pin);
        EXTI->FTSR |= (1 << pin);
        break;
    case EdgeTrigger::none:
    default:
        break;
    }

    // Enable EXTI interrupt
    EXTI->IMR |= (1 << pin);

    // Enable the EXTI interrupt in NVIC
    NVIC_EnableIRQ(irq);
}
