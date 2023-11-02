#include "Uart.h"

Uart::Uart(const uint8_t pinRX, const uint8_t pinTX, const uint32_t baudrate) :
    pinRx(pinRX),
    pinTx(pinTX),
    baudrate(baudrate)
{
    pinMode(pinTx, OUTPUT);
    pinMode(pinRX, INPUT);
    digitalWrite(pinTx, BITIDLE);
}

Uart::~Uart()
{
}

int8_t Uart::ReadCStr(char *str, size_t strLength) {
    if (str == nullptr) {
        return -1;
    }

    char c{ 0 };
    int8_t retVal = 0;
    size_t strIdx = 0;

    while ((retVal == 0 || retVal == 1) || strIdx < strLength) {
        retVal = ReadByte(&c);

        if (!retVal) {
            str[strIdx] = c;
        }

        strIdx++;
    }

    str[strIdx] = '\0';

    return retVal;
}

int8_t Uart::ReadByte(char* outputChar) {
    uint64_t nextBitTimeMicros = micros();
    if (!outputChar) {
        return -1;
    }

    if (digitalRead(pinRx) != BITSTART) {
        return -1;
    }

    // adding a half bit delay to the reading to sample in the middle of the bit instead of at the beginning
    nextBitTimeMicros += (BitDurationMicros() / 2);
    updateTimerAndWait(nextBitTimeMicros);

    for (int i = 0; i < 8; i++) {
        int value = digitalRead(pinRx);
        (*outputChar) |= value << i;
        //Serial.println(outputChar, 2);
        updateTimerAndWait(nextBitTimeMicros);
    }

    if (digitalRead(pinRx) != BITSTOP) {
        return -1;
    }

    updateTimerAndWait(nextBitTimeMicros);

    // if (digitalRead(pinRx) == BITIDLE) {
    //     return 1;
    // }

    return 0;
}

void Uart::WriteCStr(const char *str) {
    while (*str)
    {
        WriteByte(*str);
        str++;
    }
}

void Uart::WriteByte(char byte) {
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

const uint64_t Uart::BitDurationMicros() const {
    return 1000000 / baudrate;
}

void Uart::updateTimerAndWait(uint64_t& duration) {
    duration += BitDurationMicros();
    waitMicrosDuration(duration);
}

void Uart::waitMicrosDuration(const uint64_t &duration) const {
    while (micros() < duration);
}
