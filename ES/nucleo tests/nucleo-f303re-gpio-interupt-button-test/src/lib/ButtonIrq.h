#ifndef LIB_BUTTONIRQ_H_
#define LIB_BUTTONIRQ_H_

#include "gpio.h"

enum class EdgeIRQType
{
    Rising,
    Falling,
    Both,
};

class ButtonIrq
{
public:
    ButtonIrq(GPIO_TypeDef* block, uint8_t pin, EdgeIRQType edgeType, IRQn_Type irqn, volatile uint32_t* exticr, uint32_t exticrMask);
    ~ButtonIrq();

private:
    GPIO_TypeDef* block{ nullptr };
    uint8_t pin{ 0 };
    uint32_t startTime{ 0 };
    bool logicEntered{ false };
};

#endif
