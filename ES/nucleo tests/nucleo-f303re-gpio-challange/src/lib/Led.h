#ifndef LIB_LED_H_
#define LIB_LED_H_

#include "gpio.h"

class Led
{
public:
    Led(GPIO_TypeDef* block, uint8_t pin);
    ~Led();

    void Toggle();
    void On();
    void Off();

private:
    GPIO_TypeDef* block{ nullptr };
    uint8_t pin;
};

#endif
