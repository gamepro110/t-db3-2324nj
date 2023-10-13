#ifndef LIB_IRQBUTTON_H_
#define LIB_IRQBUTTON_H_

#include "gpio.h"

#include <functional>

enum class EdgeTrigger
{
    none = 0,
    Rising = 1,
    Falling = 2,
    RisingAndFalling = 3,
};

class Button
{
public:
    /// @brief init button class
    /// @param block gpio block (example: GPIOA, GPIOB)
    /// @param pin pin number
    /// @param irq exti interrupt line
    /// @param edge edge detection, set to none to not set up irq
    /// @param pressShort function to run on short press
    /// @param pressLong function to run on long press
    Button(GPIO_TypeDef* block, uint8_t pin, IRQn_Type irq, EdgeTrigger edge, std::function<void()> pressShort = [](){}, std::function<void()> pressLong = [](){});
    ~Button();

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
    EdgeTrigger edge;

    uint32_t pressStart{ 0 };
    uint32_t pressEnd{ 0 };
    bool startedPress{ false };
    std::function<void()> pressShort;
    std::function<void()> pressLong;
};

#endif
