#ifndef LIB_IRQBUTTON_H_
#define LIB_IRQBUTTON_H_

#include "gpio.h"

#include <functional>

// incomplete. configIrq not working!!
class IrqButton
{
public:
    IrqButton(GPIO_TypeDef* block, uint8_t pin, IRQn_Type irq, uint32_t edge, std::function<void()> pressShort, std::function<void()> pressLong);
    ~IrqButton();

    void init();
    void handleIrq();

private:
    void SetPressStart(uint32_t time);
    void SetPressEnd(uint32_t time);
    void configureGPIO();
    void configureIRQ();

    GPIO_TypeDef* block;
    uint8_t pin;
    IRQn_Type irq;
    uint32_t edge;

    uint32_t pressStart{ 0 };
    uint32_t pressEnd{ 0 };
    bool startedPress{ false };
    std::function<void()> pressShort;
    std::function<void()> pressLong;
};

#endif
