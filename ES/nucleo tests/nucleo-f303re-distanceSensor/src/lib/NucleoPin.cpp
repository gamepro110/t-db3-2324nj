#include "NucleoPin.hpp"

NucleoPin::NucleoPin(GPIO_TypeDef* block, uint8_t pinNr, PinMode mode) :
    block(block), pin(pinNr), pinMode(mode)
{
}

NucleoPin::NucleoPin(GPIO_TypeDef* block, uint8_t pinNr, const AltModeValue& value) :
    block(block), pin(pinNr), pinMode(PinMode::altMode)
{
    SetAltMode(value);
}

void NucleoPin::SetAltMode(const AltModeValue& modeValue) const {
    block->AFR[0] |= modeValue.low;
    block->AFR[1] |= modeValue.high;
}

bool NucleoPin::Setup() const {
    const uint8_t digitalOutput{ 0b01 };
    const uint8_t digitalInput{ 0b00 };
    const uint8_t pullUp{ 0b01 };
    const uint8_t altMode{ 0b10 };

    switch (pinMode)
    {
    case PinMode::digital_input_pullup: {
        block->PUPDR |= (pullUp << PinModerLoc());
        }
    case PinMode::digital_input: {
        block->MODER &= ~(digitalInput << PinModerLoc());
        break;
        }
    case PinMode::digital_output: {
        block->MODER |= (digitalOutput << PinModerLoc());
        break;
        }
    case PinMode::altMode: {
        block->MODER |= (altMode << PinModerLoc());
        break;
        }
    default:
        return false;
    }

    return true;
}

void NucleoPin::Write(bool high) {
    if (high) {
        block->ODR |= (1 << pin);
    }
    else {
        block->ODR &= ~(1 << pin);
    }
}

void NucleoPin::Toggle() {
    block->ODR ^= (1 << pin);
}

bool NucleoPin::Read() {
    return (block->IDR & (1 << pin)) == 1;
}

const uint8_t& NucleoPin::GetPinNr() const {
    return pin;
}

const GPIO_TypeDef* const NucleoPin::GetPinBlock() const {
    return block;
}

constexpr uint8_t NucleoPin::PinModerLoc() const {
    return (pin * 2);
}
