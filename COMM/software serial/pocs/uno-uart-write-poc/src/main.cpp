#include <lib/SerialWriter.h>

#include <Arduino.h>

void setup() {
    SerialWriter writer{ 9 };
    writer.WriteByte('A');
    writer.WriteCStr("\nhello world\n");
}

void loop() {
}
