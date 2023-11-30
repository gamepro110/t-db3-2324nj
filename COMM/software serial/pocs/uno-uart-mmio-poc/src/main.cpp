#include <lib/Uart.h>

#include <Arduino.h>

Uart uart{ 8, 9, 115200 };

void setup() {
    char txt[50];
    sprintf(txt, "soft uart at %d\nHello World!\n", (const int)uart.GetBaudrate());
    uart.WriteCStr(txt);
}

void loop() {
    static uint8_t c{ 0 };
    static int8_t retval = 0;
    c = 0;
    retval = uart.ReadByte(&c);

    if (retval == 0) {
        c++;
        uart.WriteByte(c);
    }
}
