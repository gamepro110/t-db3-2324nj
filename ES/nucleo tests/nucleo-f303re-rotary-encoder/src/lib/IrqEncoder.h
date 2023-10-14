#ifndef IRQ_ENCODER_H_
#define IRQ_ENCODER_H_

#include <gpio.h>

class IrqEncoder
{
public:
    IrqEncoder(GPIO_TypeDef* blockClk, uint8_t clkPin, GPIO_TypeDef* blockDt, uint8_t dtPin, IRQn_Type irq);
    ~IrqEncoder();

    void Init();
    void HandleIrq() volatile;
    const uint32_t& GetPosition() const;

private:
    void SetPinToInput(GPIO_TypeDef* block, uint8_t pin);

    GPIO_TypeDef* blockClk{ nullptr };
    uint8_t pinClk{ 0 };
    GPIO_TypeDef* blockDt{ nullptr };
    uint8_t pinDt{ 0 };
    IRQn_Type irq;
    uint32_t position{ 0 };
};

#endif
