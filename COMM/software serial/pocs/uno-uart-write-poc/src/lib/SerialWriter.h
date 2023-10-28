#pragma once

#include <Arduino.h>

class SerialWriter {
public:
    SerialWriter(const uint8_t pinTX, const uint32_t baudrate = 9600);
    ~SerialWriter();

public:
    void WriteCStr(const char* str);
    void WriteByte(uint8_t byte);
    const uint64_t BitDurationMicros() const;

private:
    void updateTimerAndWait(uint64_t& duration);
    void waitMicrosDuration(const uint64_t& duration) const;

private:
    const uint8_t pinTx;
    const uint32_t baudrate;

    const uint8_t BITSTART = LOW;
    const uint8_t BITSTOP = HIGH;
    const uint8_t BITONE = HIGH;
    const uint8_t BITZERO = LOW;
    const uint8_t BITIDLE = HIGH;
};
