#include <lib/Uart.h>

#include <Arduino.h>

Uart uart{ 8, 9, 4800 };

void setup() {
    uart.WriteByte('A');
    uart.WriteCStr("\nhello world\n");
    Serial.begin(9600);
}

void loop() {
    char c{ 0 };

    if (uart.ReadByte(c) == 0) {
        Serial.print(c);
        Serial.print(" 0x");
        Serial.println(c, 16);
        Serial.print(" '");
        Serial.print(c);
        Serial.println(" '");
        uart.WriteByte(c);
    }
}
