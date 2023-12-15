#ifndef LIB_PIN_H_
#define LIB_PIN_H_

#include <stdint.h>
#include <gpio.h>

enum class PinMode : uint8_t {
    input = 0,
    input_pullup,
    output,
    alt_mode
};

class Pin{
public:
    Pin(GPIO_TypeDef* block, uint8_t pin, PinMode mode);
    ~Pin();
    Pin(const Pin& o);
    Pin(Pin&& other);
    Pin operator=(const Pin p);

    void ToggleOutput() const;
    void SetOutput(bool high) const;
    bool GetInput() const;

private:
    constexpr uint8_t InPinValue() const;
    constexpr uint8_t OutPinValue() const;

    GPIO_TypeDef* block;
    uint8_t pin;
};

#endif
