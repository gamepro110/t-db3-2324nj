#ifndef LIB_IRQBUTTON_H_
#define LIB_IRQBUTTON_H_

#include "gpio.h"

#include <functional>

class IrqButton
{
public:
    IrqButton(GPIO_TypeDef* block, uint8_t pin, IRQn_Type irq, uint32_t edge, std::function<void()> pressShort, std::function<void()> pressLong);
    ~IrqButton();

    void init();
    void handle();
    void SetPressStart(uint32_t time);
    void SetPressEnd(uint32_t time);

private:
    void configureGPIO();
    void configureIRQ();

    GPIO_TypeDef* block;
    uint8_t pin;
    IRQn_Type irq;
    uint32_t edge;

    uint32_t pressStart{ 0 };
    uint32_t pressEnd{ 0 };
    bool pressHandled{ false };
    std::function<void()> pressShort;
    std::function<void()> pressLong;
};

#endif
