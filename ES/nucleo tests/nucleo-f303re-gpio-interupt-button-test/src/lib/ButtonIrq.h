#ifndef LIB_BUTTONIRQ_H_
#define LIB_BUTTONIRQ_H_

#include "gpio.h"

class ButtonIrq
{
public:
    ButtonIrq(GPIO_TypeDef* block, uint8_t pin, EXTI_TypeDef* exti);
    ~ButtonIrq();

private:
    GPIO_TypeDef* block{ nullptr };
    uint8_t pin{ 0 };
    uint32_t startTime{ 0 };
    bool logicEntered{ false };
};

#endif
