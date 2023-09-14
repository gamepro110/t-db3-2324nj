## printing to serial (HAL)

```cpp
const int MSGBUFSIZE = 80; // defining msg size
char msgBuf[MSGBUFSIZE]; // creating the buffer
snprintf(msgBuf, MSGBUFSIZE, "%s", "button pressed!\r\n"); // filling the buffer
HAL_UART_Transmit(&huart2, (uint8_t *)msgBuf, strlen(msgBuf), HAL_MAX_DELAY); // printing the buffer
```

## digital output

> enables gpio pin A5 as digital output

```cpp
// set pin to output
GPIOA->MODER = (GPIOA->MODER & ~GPIO_MODER_MODER5) | (0b01 << GPIO_MODER_MODER5_Pos));

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

## digital input

> enables gpio pin A7 as digital input

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
