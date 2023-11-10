#include "Uart.h"

void pinWrite(uint8_t pin, uint8_t value) {
    // decrement by 8 to negate the normal numbering so u start at portB pin 0
    pin -= 8;

    if (pin > 8) {
        return;
    }

    uint8_t pinVal = 1;

    pinVal <<= pin;

    uint8_t* port_b = (uint8_t*)0x25;

    switch (value) {
    case LOW: {
        (*port_b) &= ~pinVal;
        break;
    }
    default:
        (*port_b) |= pinVal;
        break;
    }
}

uint8_t pinRead(uint8_t pin) {
    // decrement by 8 to negate the normal numbering so u start at portB pin 0
    pin -= 8;

    if (pin > 8) {
        return false;
    }

    uint8_t pinVal = 1;

    pinVal <<= pin;

    uint8_t* port_b = (uint8_t*)0x25;

    return ((*port_b) & pinVal) >> pinVal;
}

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
{}

int8_t Uart::ReadByte(char& outputChar) {
    uint64_t nextBitTimeMicros = micros();

    if (pinRead(pinRx) != BITSTART) {
        return -1;
    }

    // adding a half bit delay to the reading to sample in the middle of the bit instead of at the beginning
    nextBitTimeMicros += (BitDurationMicros() / 2);
    updateTimerAndWait(nextBitTimeMicros);

    for (int i = 0; i < 8; i++) {
        int value = pinRead(pinRx);
        outputChar |= value << i;
        //Serial.println(outputChar, 2);
        updateTimerAndWait(nextBitTimeMicros);
    }

    if (pinRead(pinRx) != BITSTOP) {
        return -2;
    }

    updateTimerAndWait(nextBitTimeMicros);

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

    pinWrite(pinTx, BITSTART);
    updateTimerAndWait(nextBitTimeMicros);

    for (int bit = 0; bit < 8; bit++) {
        pinWrite(pinTx, bitRead(byte, bit) == 1 ? BITONE : BITZERO);
        updateTimerAndWait(nextBitTimeMicros);
    }

    pinWrite(pinTx, BITSTOP);

    updateTimerAndWait(nextBitTimeMicros);
    pinWrite(pinTx, BITIDLE);
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
