---
tags:
  - ES
  - nucleo
  - snippet
---
# nucleo-notes

## pinout

![pinout](<../Assets/nucleo-f303_pinout.png>)

---

### reserved pins

| pin  | reason               | reusable |
| ---- | -------------------- | -------- |
| PA2  | USART_TX             | ?        |
| PA3  | USART_RX             | ?        |
| PA5  | LD2(green led)       | yes      |
| PA13 | TMS                  | ?        |
| PA14 | TCK                  | ?        |
| PB3  | SWO                  | ?        |
| PC13 | B1 (blue pushbutton) | yes      |
| PC14 | RCC_OSC32_IN         | ?        |
| PC15 | RCC_OSC32_OUT        | ?        |
| PF0  | RCC_OSC_IN           | ?        |
| PF1  | RCC_OSC_OUT          | ?        |

## useful links

| Description            | Link                                                                           |
| ---------------------- | ------------------------------------------------------------------------------ |
| Reference manual       | <https://www.st.com/resource/en/reference_manual/DM00043574-.pdf>              |
| ST Timers presentation | <https://www.st.com/resource/en/product_training/STM32L4_WDG_TIMERS_GPTIM.pdf> |

## printing to serial (HAL)

```cpp
\#include <stdio.h> // required for snprintf
\#include <string.h> // required for strlen
\#include <usart.h> // required for HAL_UART_Transmit

const int MSGBUFSIZE = 80; // defining msg size
char msgBuf[MSGBUFSIZE]; // creating the buffer
snprintf(msgBuf, MSGBUFSIZE, "%s", "button pressed!\r\n"); // filling the buffer
HAL_UART_Transmit(&huart2, (uint8_t *)msgBuf, strlen(msgBuf), HAL_MAX_DELAY); // printing the buffer
```

## digital output

| name     | meaning                                                        | why?                              |
| -------- | -------------------------------------------------------------- | --------------------------------- |
| `GPIO*`  | general purpose IO, * is replaced with a letter from a till h. | `DMA` (Direct memory access) access to GPIO block        |
| `MODER`  | mode register                                                  | set the mode of the specified pin |
| `OTYPER` | output type register                                           | setting push-pull or open drain   |

> enables GPIO pin A5 as digital output

```cpp
// set pin to output
GPIOA->MODER = ((GPIOA->MODER & ~GPIO_MODER_MODER5) | (0b01 << GPIO_MODER_MODER5_Pos));

// set pin output type to push-pull
GPIOA->OTYPER &= ~GPIO_OTYPER_OT_5;
```

> setting or toggling the pin

```cpp
// set pin to high
GPIOA->ODR |= GPIO_ODR_5;

// toggling the pin
GPIOA->ODR ^= GPIO_ODR_5
```

### output function version

```cpp
void PinSetOutput(GPIO_TypeDef* block, uint8_t pin) {
    // set pin to output
    block->MODER = (
        (block->MODER & ~(0b11 << (pin * 2))) |
        ((0b01 << (pin * 2)))
    );
    // set pin output type to push-pull
    block->OTYPER &= ~(1 << pin);
}
```

> `pin * 2` is done because each pin has 2 bits in the 32 bit MODER (mode register)

## digital input

| name    | meaning                                                        | why?                              |
| ------- | -------------------------------------------------------------- | --------------------------------- |
| `GPIO*` | general purpose IO, * is replaced with a letter from a till h. | DMA access to GPIO block          |
| `MODER` | mode register                                                  | set the mode of the specified pin |
| `PUPDR` | pull up/down register                                          | enable pull up/down register      |

> enables GPIO pin A7 as digital input

```cpp
// set pin to input
GPIOA->MODER = ((GPIOA->MODER & ~GPIO_MODER_MODER7) | (0b00 << GPIO_MODER_MODER7_Pos));

// set pulup resistor. 0b01 == pullup resistor
GPIOA->PUPDR = ((GPIOA->PUPDR & ~GPIO_PUPDR_PUPDR7) | (0b01 << GPIO_PUPDR_PUPDR7_Pos));
```

> check if button is pressed

```cpp
if ((GPIOA->IDR & GPIO_IDR_7) == 0) {
  // button pressed
}
```

### input function version

```cpp
void PinSetToInput(GPIO_TypeDef* block, uint8_t pin) {
    // set pin to output
    block->MODER = (
        (block->MODER & ~(0b11 << (pin * 2))) |
        ((0b01 << (pin * 2)))
    );
    // set pin output type to push-pull
    block->OTYPER &= ~(1 << pin);
}
```

> `pin * 2` is done because each pin has 2 bits in the 32 bit MODER (mode register)

## timers

> default system clock speed is 7.2 MHz!!!

### calculate timer timing

| var name | full name |
| --- | --- |
| `c` | pwm clock cycle |
| `m` | main system clock |
| `p` | timer prescaler |
| `d` | pwm duty cycle |
| `a` | auto reset register (turns duty cycle on/off) |

> $$ c = \frac{p}{m} $$

### registers

| name          | meaning                                                            | why?                                                                                                                                                                        |
| ------------- | ------------------------------------------------------------------ | --------------------------------------------------------------------------------------------------------------------------------------------------------------------------- |
| `RCC`         | Reset and Clock Control                                            | handle system reset and clock controls.                                                                                                                                     |
| `RCC_APB1ENR` | `RCC` for `APB1` bus                                               | `RCC` responsible for enabling peripheral clocks in the `APB1` bus.                                                                                                         |
| `TIMx`        | timer (x is replaced with a number)                                | refers to a timer.                                                                                                                                                          |
| `PSC`         | pre-scaler                                                         | a timer register that divides the input clock frequency to the timer</br> allowing you to control the timers clock frequency.                                               |
| `ARR`         | auto-reload register                                               | specifying when a timer will overflow or reset.                                                                                                                             |
| `DIER`        | DMA/interrupt enable register                                      | timer register used to enable or disable timer-related interrupts, such as update events.                                                                                   |
| `UIE`         | update interrupt enable                                            | `UIE` is a bit within the `DIER` register that enables or disables the update event interrupt for the timer.                                                                |
| `NVIC`        | nested vector interrupt controller                                 | part of the processor responsible for managing and prioritizing interrupts in the micro-controller.                                                                         |
| `TIM2_IRQn`   | timer 2 interrupt number                                           | the interrupt function being called when it is triggered. important: mark the function with `extern "C"` when using C++.                                                    |
| `CR1`         | control register 1                                                 | a control register for timer 2 that contains various control bits, including the one to enable the timer.                                                                   |
| `CEN`         | counter enable                                                     | a bit within `CR1` register that enables or disables the timer.                                                                                                             |
| `CNT`         | Timer Count Register                                               |                                                                                                                                                                             |
| `CCRx`        | timer Capture/Compare Register channel x                           | contains the captured `TIMx_CNT` value when channel x is in input capture mode: contains the value `TIMx_CNT` is compared against when channel x is in output compare mode* |
| `CCMRx`       | timer Capture/Compare (channel) Mode Register                      | all the mode settings for the timers channels, spread across X registers                                                                                                    |
| `CCx`         | Capture/Compare (channel) x                                        | used to designate a channel, regardless of the mode                                                                                                                         |
| `ICx`         | Input Capture (channel) x                                          | used to designate a channel that is in input mode                                                                                                                           |
| `OCx`         | Output Capture (channel) x                                         | used to designate a channel that is in output mode                                                                                                                          |
| `CCxS`        | Capture/Compare channel x selection but (in `TIMx_CCMRy` register) | channels can be set in input or output mode. </br> channels in input mode can be directed to `TI1`, `TI2` or `TRC`                                                          |
| `OCxREF`      | Output channel reference signal                                    | actual channel output; if bound to a pin, this is the value that is sent to the pin                                                                                         |
| `TIx`         | timer input x                                                      | a signal an input channel can be mapped onto*                                                                                                                               |
| `UEV`         | Update EVent                                                       | an event that is emitted by default. this can trigger, for instance the `ARR` value to be reloaded, so the value doesn't update while the timer is counting                 |

### example

```cpp
// enable timer 2
RCC->APB1ENR |= RCC_APB1ENR_TIM2EN;

// set prescaler to 1 MHz (desired freq -1) assuming 8 MHz system clock
TIM2->PSC = 1000 - 1;

// set auto-reload value for desired time period
// 1/10 of 1 MHz == 1 KHz (assuming 1 MHz timer clock)
TIM2->ARR = 10000 - 1;

// enable the update event interrupt for tim2
TIM2->DIER |= TIM_DIER_UIE;

// set timer interrupt priority and enable it in the NVIC
NVIC_SetPriority(TIM2_IRQn, 0);
NVIC_EnableIRQ(TIM2_IRQn);

// start timer
// timer_ControlRegister_ClockENable
TIM2->CR1 |= TIM_CR1_CEN;
```

### clock diagram

> reference manual, page 602

![timer diagram](<../Assets/figure-197.png>)

---

### Input capture clarification

ST timers presentation, page 16

%%
![timers presentation screenshot 1](docs/slideshow-input-capture.png)
%%

### Capture/Compare channel clarification

Reference manual, section 21.3.4

### Rotary encoder timer mode

ST timers presentation, page 12

Might be useful for a rotary encoder POC

%%
![timers presentation screenshot 2](docs/slideshow-counting-mode.png)
%%
