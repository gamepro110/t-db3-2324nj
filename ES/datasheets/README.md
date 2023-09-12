# Important Reference manuals parts with highlights

In the [reference-manual-parts](reference-manual-parts) directory you can find reference manual parts to make working with the stm32 [reference manual - en.DM00043574.pdf](en.DM00043574.pdf) a bit more relaxed and to get you started.

You will find separate pdf files for the following subjects. Without any guarantees, or claims to be complete, some interesting sections of the manuals are highlighted. 

+ [gpio](cheat-materials/gpio-reference-manual-en.DM0004357 - STMICROELECTRONICS.pdf)
+ [	interrupts](cheat-materials/interrupts-reference-manual-en.DM00043574 - STMICROELECTRONICS.pdf)
+ [syscfg](cheat-materials/syscfg-reference-manual-en.DM00043574 - STMICROELECTRONICS.pdf)
+ [timers](cheat-materials/timers-reference-manual-en.DM00043574 - STMICROELECTRONICS.pdf)

# Pinout of Nucleo board

+ [Nucleo-f303_pinout](https://raw.githubusercontent.com/wiki/RIOT-OS/RIOT/images/nucleo-f303_pinout.png)
    + Buildin:
        + Blue user button = PC13
        + Green LED = PA5
        + Blue LED = PC8

# Register abbreviations overview

It might be useful for you if you know what all the abbreviations mean so your code becomes more readable. 
	
## GPIO

Section | Name | Meaning 
---|---|---
GPIO[ABCD] | MODER | Mode register -> determines if input, output or alternate function (pinMode)
. | OTYPE | Output type (push-pull , open-drain) 
. | PUPDR | Pull-up/pull-down register
. | ODR | Output data register (digitalWrite)
. | IDR | Input data register (digitalRead)
. | BSSR | Bit set reset register (only update individual pin)

## Interrupts

Section | Name | Meaning 
---|---|---
SYSCFG | EXTICR[...] | External Interrupt Configuration Register (selecting a pin)
EXTI | IMR | Interrupt Mask Register (selecting a line)
. | RTSR | Rising Trigger Selection Register
. | FTSR | Falling Trigger Selection Register
. | PR | Pending Register
. |
. | EMR | Event Mask Register
. | SWIER | Software Interrupt Event Register 

## Timers

Section | Name | Meaning 
---|---|---
RCC | APB1ENR | Peripheral clock enable register  
GPIO | AFR | Alternate Function Register
TIM[234] | CR | Control Register |
. | PSC | Prescaler
. | ARR | Auto Reload Register
. | DIER | ~~DMA /~~ Interrupt Enable Register
. | EGR | Event Generation Register | 
. | SR | Status register

### Timer capture Compare Registers

Section | Name | Meaning 
---|---|---
. | CCMR | Capture/Compare Mode register
. | CCR | Capture Compare Register
. | CCER | Capture Compare Enable Register


### Prescaler example (PSC)

The STM32 (nucleo-f303RE) has a default internal clock speed frequency of 72 MHz. This meaning that 72.000.000 clock pulses are generated every second. With the prescaler register we can scale the frequency of the timer clock frequency:

Note: the following values are valid for a nucleo-f303RE. please check your datasheet/hardware for other processors.

Prescaler (PSC) | Frequency of the timer clock | Period of timer clock
---|---|---
1-1 (0) | 72 MHz | - 
10-1 (9) | 7.2 MHz | -
72-1 (71)| 1 Mhz | 1 us
72000-1 (71999) | 1 kHz | 1 ms


### Auto reload examples (ARR)

Let's say we will use a PSC value of 84. This means that the timer clock will have a speed of 1 MHz. This means that the time between an increase of the counter is 1 / 1 MHz = 1 us.

Auto Reload (ARR) | Period of timer interrupt | Frequency of timer interrupt
---|---|---
100 | 100 x 1 us = 100 us | 10 kHz
1000 |  1000 x 1 us = 1000 us = 1 ms | 1 kHz
1.000.000 | 1.000.000 x 1 us = 1 s | 1 Hz

(Note that you will need a 32-bit timer for using a ARR value of 1.000.000)

### Timer Interrupts that occur too soon

From the presentation on timers (see slides notes)

It may happen that right after enabling the counter the timer interrupt handler is called. This happens because normally the new prescaler value is loaded only after an update event which occurs after the first interrupt. So until then the default prescaler value is used which is 0 (which means effectively a prescaler of 1). This will cause the first interrupt to occur too soon. It can be prevented by adding the two lines of code below right after setting the prescaler register. This is hard to extract from the data sheet and we do not expect this from students.

`TIM2->EGR |= TIM_EGR_UG; // Set the UG (Update Event Generator) bit which forces the new prescaler value to be loaded.

TIM2->SR = ~TIM_SR_UIF; // Reset the Update Interrupt flag to prevent the IRQ handler to be called after enabling the counter.`


