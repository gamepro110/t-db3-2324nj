#include "Pin.hpp"

Pin::Pin(GPIO_TypeDef* block, uint8_t pin, PinMode mode) :
    block(block), pin(pin)
{
    const uint8_t Input{ 0b00 };
    const uint8_t Output{ 0b01 };
    const uint8_t altMode{ 0 }; // unfinished
    const uint8_t pullupR{ 0b01 };

    switch (mode) {
    case PinMode::input_pullup:
        block->PUPDR |= (pullupR << OutPinValue());
    case PinMode::input:
        block->MODER |= (Input << OutPinValue()); //TODO change to mask
        break;
    case PinMode::output:
        block->MODER |= (Output << OutPinValue());
        block->OTYPER &= ~(1 << pin);
        break;
    case PinMode::alt_mode:
        static_assert(altMode == 0, "unimplemented");
        block->MODER |= (altMode << OutPinValue());
        break;
    default:
        break;
    }
}

Pin::~Pin()
{}

Pin::Pin(const Pin& o) :
    block(o.block), pin(o.pin)
{}

Pin::Pin(Pin&& other) {
    block = other.block;
    pin = other.pin;
}

Pin Pin::operator=(const Pin p) {
    return Pin(p);
}

void Pin::ToggleOutput() const {
    block->ODR ^= OutPinValue();
}

void Pin::SetOutput(bool high) const {
    if (high) {
        block->ODR |= OutPinValue();
    }
    else {
        block->ODR &= ~OutPinValue();
    }
}

bool Pin::GetInput() const {
    return ((block->IDR & InPinValue()) != 0);
}

constexpr uint8_t Pin::InPinValue() const {
    return (1 << pin);
}

constexpr uint8_t Pin::OutPinValue() const {
    return (1 << (2 * pin));
}
