#include "SerialWriter.h"

SerialWriter::SerialWriter(const uint8_t pinTX, const uint32_t baudrate) :
    pinTx(pinTX), baudrate(baudrate)
{
    pinMode(pinTx, OUTPUT);
    digitalWrite(pinTx, BITIDLE);
}

SerialWriter::~SerialWriter() {}

void SerialWriter::WriteCStr(const char *str) {
    while (*str)
    {
        WriteByte(*str);
        str++;
    }
}

void SerialWriter::WriteByte(uint8_t byte) {
    uint64_t nextBitTimeMicros = micros();

    digitalWrite(pinTx, BITSTART);
    updateTimerAndWait(nextBitTimeMicros);

    for (int bit = 0; bit < 8; bit++) {
        digitalWrite(pinTx, bitRead(byte, bit) == 1 ? BITONE : BITZERO);
        updateTimerAndWait(nextBitTimeMicros);
    }

    digitalWrite(pinTx, BITSTOP);
    updateTimerAndWait(nextBitTimeMicros);

    digitalWrite(pinTx, BITIDLE);
}

const uint64_t SerialWriter::BitDurationMicros() const {
    return 1000000 / baudrate;
}

void SerialWriter::updateTimerAndWait(uint64_t& duration) {
    duration += BitDurationMicros();
    waitMicrosDuration(duration);
}

void SerialWriter::waitMicrosDuration(const uint64_t &duration) const {
    while (micros() < duration);
}
