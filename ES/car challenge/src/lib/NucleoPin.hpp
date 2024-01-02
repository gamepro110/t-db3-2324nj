#ifndef LIB_NUCLEOPIN_HPP_
#define LIB_NUCLEOPIN_HPP_

#include "stm32f303xe.h"
#include <cstdint>

enum class PinMode {
    none,
    digital_input,
    digital_input_pullup,
    digital_output,
    altMode,
};

//NOTE: this might not survive the switch from little to big endian
union AltModeValue {
    uint64_t value;
    struct {
        uint32_t low;
        uint32_t high;
    };

    AltModeValue(uint64_t val) :
        value(val)
    {}
    void operator=(uint64_t val) {
        value = val;
    }
    AltModeValue operator<<(uint32_t val) {
        return { value << val };
    }
};

class NucleoPin {
public:
    NucleoPin(GPIO_TypeDef* block, uint8_t pinNr, PinMode mode = PinMode::none);
    NucleoPin(GPIO_TypeDef* block, uint8_t pinNr, AltModeValue value);
    void SetAltMode(const AltModeValue& modeValue) const;
    bool Setup() const;
    void Write(bool high) const;
    void Toggle() const;
    bool Read() const;

    const uint8_t& GetPinNr() const;
    const GPIO_TypeDef* const GetPinBlock() const;

private:
    constexpr uint8_t PinModerLoc() const;

    GPIO_TypeDef* block;
    uint8_t pin;
    PinMode pinMode;
    AltModeValue value;
};

#endif
