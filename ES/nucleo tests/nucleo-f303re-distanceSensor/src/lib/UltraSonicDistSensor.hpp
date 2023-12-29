#ifndef LIB_ULTRASONICDISTSENSOR_HPP
#define LIB_ULTRASONICDISTSENSOR_HPP

#include "lib/IDistSensor.hpp"
#include "lib/HardwareTimer.hpp"
#include "lib/NucleoPin.hpp"

#include <cstdint>

class UltraSonicDistSensor : public IDistSensor {
public:
    UltraSonicDistSensor(HardwareTimer timer, NucleoPin pinEcho, NucleoPin pinTrigger);
    ~UltraSonicDistSensor();
    bool Setup(uint8_t prescaler, uint32_t arrValue, uint32_t outputCCValue, const uint8_t outputChannel, const uint8_t inputChannel1, const uint8_t intputChannel2);
    uint8_t GetDist() override;

private:
    HardwareTimer tim;
    NucleoPin echoPin;
    NucleoPin trigPin;
};

#endif