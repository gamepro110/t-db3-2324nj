#include "Button.hpp"

#include "lib/Logger.hpp"

#include "stm32f3xx_hal.h"

Button::Button(NucleoPin inputPin, IRQn_Type irq, osMessageQueueId_t id, Action actionShort, Action actionLong) :
    btnPin(inputPin),
    id(id),
    irq(irq),
    shortPressCallback(actionShort),
    longPressCallback(actionLong)
{
}


Button::Button(const Button &other) :
    btnPin(other.btnPin),
    id(other.id),
    irq(other.irq),
    shortPressCallback(other.shortPressCallback),
    longPressCallback(other.longPressCallback)
{}

Button::~Button() {
}

Button &Button::operator=(const Button &other) {
    btnPin = other.btnPin;
    irq = other.irq;
    id = other.id;
    shortPressCallback = other.shortPressCallback;
    longPressCallback = other.longPressCallback;
    return *this;
}

bool Button::SetupIrq() {
    if (!btnPin.Setup() || irq == IRQn_Type::HardFault_IRQn) {
        return false;
    }

    const uint8_t& pinNr = btnPin.GetPinNr();
    uint32_t exti_idx = pinNr / 4;
    uint32_t exti_shift = (pinNr % 4) * 4;

    int irqPinBlock = 0;
    const GPIO_TypeDef* const block = btnPin.GetPinBlock();

    if (block == GPIOA) {
        irqPinBlock = 0b000;
    }
    else if (block == GPIOB) {
        irqPinBlock = 0b001;
    }
    else if (block == GPIOC) {
        irqPinBlock = 0b010;
    }
    else if (block == GPIOD) {
        irqPinBlock = 0b011;
    }
    else if (block == GPIOE) {
        irqPinBlock = 0b100;
    }
    else if (block == GPIOF) {
        irqPinBlock = 0b101;
    }
    else if (block == GPIOG) {
        irqPinBlock = 0b110;
    }
    else if (block == GPIOH) {
        irqPinBlock = 0b111;
    }
    else {
        return false;
    }

    SYSCFG->EXTICR[exti_idx] |= (irqPinBlock << exti_shift);

    // Configure EXTI to trigger on the rising and falling
    EXTI->RTSR |= (1 << pinNr);
    EXTI->FTSR |= (1 << pinNr);

    // Enable EXTI interrupt
    EXTI->IMR |= (1 << pinNr);

    NVIC_SetPriority(irq, 8);
    //! note down
    // 1 == 16
    // 2 == 32
    // 4 == 64
    // etc. priority should be above 80. this is a weird qwirk...

    // Enable the EXTI interrupt in NVIC
    NVIC_EnableIRQ(irq);

    return true;
}

//!TEMP
// #include "usart.h"
// #include <cstring>
//!TEMP

void Button::HandleIrq() {
    uint32_t tick = HAL_GetTick();
    uint32_t delta = 0;

    if (!triggered) {
        triggered = true;
        startTime = tick;
    }
    else {
        triggered = false;
        delta = tick - startTime;
    }

    if (delta > 20 && !triggered) {
        data.butNr = btnPin.GetPinNr();
        data.Duration = delta;

        const uint8_t msgPrio = 0;
        const uint32_t timeout = 0; //must be zero <https://www.keil.com/pack/doc/CMSIS/RTOS2/html/group__CMSIS__RTOS__Message.html#gaa515fc8b956f721a8f72b2c505813bfc>
        osMessageQueuePut(id, (void*)&data, msgPrio, timeout);
    }
    else if (!triggered) {
        startTime = 0;
        triggered = false;
    }
}

void Button::ShortPress() {
    shortPressCallback();
}

void Button::LongPress() {
    longPressCallback();
}
