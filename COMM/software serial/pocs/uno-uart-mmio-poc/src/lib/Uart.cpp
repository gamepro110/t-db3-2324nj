#include "Uart.h"

void pinWrite(uint8_t pin, uint8_t value, bool track = false) {
    if (pin >= 8) {
        pin -= 8;
    }

    uint8_t pinVal{ 1 };
    pinVal <<= pin;

    if (track) {
        PORTB ^= 8;
        switch (value) {
            case LOW: {
                PORTB &= ~pinVal;
                break;
            }
            default: {
                PORTB |= pinVal;
                break;
            }
        }
        PORTB ^= 8;
    }
    else {
        switch (value) {
            case LOW: {
                PORTB &= ~pinVal;
                break;
            }
            default: {
                PORTB |= pinVal;
                break;
            }
        }
    }
}

// <https://docs.arduino.cc/hacking/software/PortManipulation>
uint8_t pinRead(uint8_t pin, bool track = false) {
    uint8_t mask{ 1 };
    uint8_t value{ 0 };

    if (track) {
        PORTB ^= 4;
        value = PINB;
        PORTB ^= 4;
    }
    else {
        value = PINB;
    }

    return (value & mask);
}

Uart::Uart(const uint8_t pinRX, const uint8_t pinTX, const uint32_t baudrate) :
    pinRx(pinRX),
    pinTx(pinTX),
    baudrate(baudrate)
{
    digitalWrite(10, LOW);
    digitalWrite(11, LOW);
    pinMode(10, OUTPUT);
    pinMode(11, OUTPUT);

    digitalWrite(pinTx, BITIDLE);
    pinMode(pinTx, OUTPUT);
    pinMode(pinRX, INPUT_PULLUP);
}

Uart::~Uart()
{}

uint8_t Uart::ReadByte(uint8_t* outputChar) {
    uint64_t nextBitTimeMicros = micros();

    if (pinRead(pinRx) != BITSTART) {
        return -1;
    }

    // adding a half bit delay to the reading to sample in the middle of the bit instead of at the beginning
    nextBitTimeMicros += (BitDurationMicros() / 4);
    updateTimerAndWait(nextBitTimeMicros);

    for (uint8_t i = 0; i < 8; i++) {
        uint8_t value = pinRead(pinRx, true);
        (*outputChar) |= value << i;
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
        pinWrite(pinTx, (bitRead(byte, bit) == 1 ? BITONE : BITZERO), true);
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
