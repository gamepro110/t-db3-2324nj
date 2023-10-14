#ifndef LIB_ENCODER_H_
#define LIB_ENCODER_H_

#include "gpio.h"

enum class EncoderOutput {
    NoChange = 0,
    rotatedLeft,
    rotatedRight,
};

class PollingEncoder final {
public:
    PollingEncoder(GPIO_TypeDef* blockPinClk, uint8_t pinClk, GPIO_TypeDef* blockPinDt, uint8_t pinDt/*, GPIO_TypeDef* blockPinBtn, uint8_t pinBtn*/);
    ~PollingEncoder();

    EncoderOutput Poll();

private:
    GPIO_TypeDef* blockPinClk{ nullptr };
    uint8_t pinClk{ 0 };
    GPIO_TypeDef* blockPinDt{ nullptr };
    uint8_t pinDt{ 0 };
    uint8_t position{ 0 };
    uint8_t lastState{ 0 };
    uint8_t sigClk{ 0 };
    uint8_t sigDt{ 0 };
    uint32_t lastTrigger{ 0 };
    const uint32_t debouncTime{ 80 };
};

#endif
