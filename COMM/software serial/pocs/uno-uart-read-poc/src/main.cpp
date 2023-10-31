#include <lib/Uart.h>

#include <Arduino.h>

Uart uart{ 8, 9, 9600 };
const size_t StrLen{ 30 };
char c[StrLen];

void clearStr(char* str, size_t len);

void setup() {
    uart.WriteByte('A');
    uart.WriteByte('\n');
    uart.WriteCStr("hello world\n");

    clearStr(c, StrLen);
}

void loop() {
    if (uart.ReadCStr(c, StrLen) == 0) {
        for (auto& ch : c) {
            ch++;
        }

        uart.WriteCStr(c);
        uart.WriteByte('\n');

        clearStr(c, StrLen);
    }
}

void clearStr(char* str, size_t len) {
    for (size_t i = 0; i < len; i++) {
        c[i] = '0';
    }

}
