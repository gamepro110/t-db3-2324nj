#ifndef LIB_SOFTUART_H_
#define LIB_SOFTUART_H_

#include "NucleoPin.hpp"

#include "stm32f3xx_hal.h"

#include <stdint.h>
#include <string_view>

#define HIGH 1
#define LOW 0

template<typename DataType, uint8_t numDataBits, uint8_t numStopBits, uint8_t numParityBits>
class SoftUart final {
public:
    SoftUart(NucleoPin& rx, NucleoPin& tx, NucleoPin& debugRx, NucleoPin& debugTx, uint32_t baudrate = 9600) :
        rx(rx), tx(tx), debugRx(debugRx), debugTx(debugTx), baud(baudrate)
    {
        static_assert(numDataBits >= 5);
        static_assert(numDataBits <= 8);

        static_assert(numStopBits >= 1);
        static_assert(numStopBits <= 2);

        static_assert(numParityBits >= 0);
        static_assert(numParityBits <= 2);
    }
    ~SoftUart() {}

    bool Setup() {
        rx.Write(true);
        tx.Write(true);
        debugRx.Write(true);
        debugTx.Write(true);

        return (
            rx.Setup() &&
            tx.Setup() &&
            debugRx.Setup() &&
            debugTx.Setup()
        );
    }

    bool ReadByte(uint8_t& outputValue) {
        uint64_t nextBitTime = HAL_GetTick();

        if (rx.Read() != BITSTART) {
            return false;
        }

        nextBitTime += ((BitDuration() / 10) * 3); // sets measuring point 30% into the bit
        updateTimerAndWait(nextBitTime);

        for (int i = 0; i < numDataBits; i++) {
            debugRx.Write(HIGH);
            DataType value = rx.Read() ? 1 : 0;
            debugRx.Write(LOW);
            outputValue |= (value << i);
            updateTimerAndWait(nextBitTime);
        }

        for (int i = 0; i < numStopBits; i++) {
            if (rx.Read() != BITSTOP) {
                return false;
            }
            updateTimerAndWait(nextBitTime);
        }

        return true;
    }

    void WriteByte(uint8_t byte) {
        uint64_t nextBitTime = HAL_GetTick();

        tx.Write(BITSTART); // start bit
        updateTimerAndWait(nextBitTime);

        int i = 0;
        for (int bit = 0; bit < numDataBits; bit++) {
            i = byte & (1 << bit);

            i = ((i != 0) ? HIGH : LOW);

            debugTx.Write(HIGH);
            tx.Write(i);
            debugTx.Write(LOW);

            updateTimerAndWait(nextBitTime);
        }

        for (int i = 0; i < numStopBits; i++) {
            tx.Write(BITSTOP); // stop bit
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
        return 1000000U / baud;
    }

    void updateTimerAndWait(uint64_t& duration) {
        duration += BitDuration();
        waitDuration(duration);
    }

    void waitDuration(const uint64_t& duration) const {
        uint64_t tick = 0;

        do
        {
            tick = HAL_GetTick(); //TODO change to custom timer
        }
        while (tick < duration);
    }

    const NucleoPin& rx;
    const NucleoPin& tx;
    const NucleoPin& debugRx;
    const NucleoPin& debugTx;

    const uint32_t baud;

    const bool BITSTART =       LOW;
    const bool BITSTOP =        HIGH;
    const bool BITONE =         HIGH;
    const bool BITZERO =        LOW;
    const bool BITIDLE =        HIGH;
};

#endif
