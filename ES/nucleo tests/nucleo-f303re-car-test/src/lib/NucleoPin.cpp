#include "NucleoPin.hpp"

NucleoPin::NucleoPin() :
    block(GPIOH),
    pin(0),
    pinMode(PinMode::none),
    altModeVal(0)
{}

NucleoPin::NucleoPin(GPIO_TypeDef *block, uint8_t pinNr, PinMode mode) : block(block),
                                                                         pin(pinNr),
                                                                         pinMode(mode),
                                                                         altModeVal(0)
{}

NucleoPin::NucleoPin(GPIO_TypeDef* block, uint8_t pinNr, AltModeValue val) :
    block(block),
    pin(pinNr),
    pinMode(PinMode::altMode),
    altModeVal((val << (4 * pinNr)))
{}

NucleoPin::NucleoPin(const NucleoPin &other) :
    block(other.block),
    pin(other.pin),
    pinMode(other.pinMode),
    altModeVal(other.altModeVal)
{}

NucleoPin &NucleoPin::operator=(const NucleoPin &other) {
    block = other.block;
    pin = other.pin;
    pinMode = other.pinMode;
    altModeVal = other.altModeVal;
    return *this;
}

void NucleoPin::SetAltMode(const AltModeValue& modeValue) const {
    block->AFR[0] |= modeValue.low;
    block->AFR[1] |= modeValue.high;
}

bool NucleoPin::Setup() const {
    if (pinMode == PinMode::none) {
        return false;
    }

    const uint8_t digitalOutput     { 0b01 };
    const uint8_t digitalInput      { 0b11 }; // inverse of 0b00
    const uint8_t pullUp            { 0b01 };
    const uint8_t altMode           { 0b10 };

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
            SetAltMode(altModeVal);
        break;
        }
    default:
        return false;
    }

    return true;
}

void NucleoPin::Write(bool high) const {
    if (high) {
        block->ODR |= (1 << pin);
    }
    else {
        block->ODR &= ~(1 << pin);
    }
}

void NucleoPin::Toggle() const {
    block->ODR ^= (1 << pin);
}

bool NucleoPin::Read() const {
    return block->IDR & (1 << pin);
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