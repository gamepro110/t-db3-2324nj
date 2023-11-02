#include <lib/Uart.h>

#include <Arduino.h>

Uart uart{ 8, 9, 9600 };

void setup() {
    uart.WriteByte('A');
    uart.WriteByte('\n');
    uart.WriteCStr("hello world\n");
}

void loop() {
    char c{ 0 };
    if (uart.ReadByte(&c) == 0) {
        c++;
        uart.WriteByte(c);
    }
}
