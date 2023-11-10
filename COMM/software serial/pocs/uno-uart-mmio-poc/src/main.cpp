#include <lib/Uart.h>

#include <Arduino.h>

Uart uart{ 8, 9, 9600 };

void setup() {
    uart.WriteByte('A');
    uart.WriteByte('\n');
    uart.WriteCStr("Hello World\n");
    Serial.begin(9600);
}

void loop() {
    static char c{ 0 };
    static char retval = 0;
    c = 0;
    retval = uart.ReadByte(c);
    if (retval == 0) {
        c++;
        uart.WriteByte(c);
    }
}
