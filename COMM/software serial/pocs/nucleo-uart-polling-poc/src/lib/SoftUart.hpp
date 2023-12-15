#ifndef LIB_SOFTUART_H_
#define LIB_SOFTUART_H_

#include "Pin.hpp"

#include <stdint.h>
#include <string_view>

#define HIGH 1
#define LOW 0

template<typename DataType, uint8_t numDataBits, uint8_t numStopBits, uint8_t numParityBits>
class SoftUart final {
public:
    SoftUart(Pin rx, Pin tx, Pin debugRx, Pin debugTx, uint32_t baudrate = 9600) :
        rx(rx), tx(tx), debugRx(debugRx), debugTx(debugTx), baud(baudrate)
    {
        debugRx.SetOutput(0);
        debugTx.SetOutput(0);
    }
    ~SoftUart() {}

    bool ReadByte(uint8_t& outputValue) {
        uint64_t nextBitTime = HAL_GetTick();
        debugFreq.ToggleOutput();

        if (rx.GetInput() != BITSTART) {
            return false;
        }

        nextBitTime += ((BitDuration() / 10) * 3); // sets measuring point 30% into the bit
        updateTimerAndWait(nextBitTime);

        for (int i = 0; i < numDataBits; i++) {
            debugRx.SetOutput(HIGH);
            DataType value = rx.GetInput() ? 1 : 0;
            debugRx.SetOutput(LOW);
            outputValue |= (value << i);
            updateTimerAndWait(nextBitTime);
        }

        for (int i = 0; i < numStopBits; i++) {
            if (rx.GetInput() != BITSTOP) {
                return false;
            }
            updateTimerAndWait(nextBitTime);
        }

        return true;
    }

    void WriteByte(uint8_t byte) {
        uint64_t nextBitTime = HAL_GetTick();

        tx.SetOutput(BITSTART); // start bit
        updateTimerAndWait(nextBitTime);

        int i = 0;
        for (int bit = 0; bit < numDataBits; bit++) {
            i = byte & (1 << bit);

            i = ((i != 0) ? HIGH : LOW);

            debugTx.SetOutput(HIGH);
            tx.SetOutput(i);
            debugTx.SetOutput(LOW);

            updateTimerAndWait(nextBitTime);
        }

        for (int i = 0; i < numStopBits; i++) {
            tx.SetOutput(BITSTOP); // stop bit
            updateTimerAndWait(nextBitTime);
        }
    }

    bool Write(std::string_view text) {
        for (uint8_t c : text) {
            WriteByte(c);
        }

        return true;
    }

private:
    constexpr uint64_t BitDuration() const {
        return 1000000 / baud;
    }
    void updateTimerAndWait(uint64_t& duration) {
        duration += BitDuration();
        waitDuration(duration);
    }
    void waitDuration(const uint64_t& duration) const {
        uint64_t tick = 0;

        do
        {
            tick = HAL_GetTick();
        }
        while (tick < duration);
    }

    const Pin rx;
    const Pin tx;

    const Pin debugRx;
    const Pin debugTx;
    const Pin debugFreq{ GPIOA, 0, PinMode::output };

    const uint32_t baud;

    const uint8_t BITSTART = LOW;
    const uint8_t BITSTOP = HIGH;
    const uint8_t BITONE = HIGH;
    const uint8_t BITZERO = LOW;
    const uint8_t BITIDLE = HIGH;
};

#endif
