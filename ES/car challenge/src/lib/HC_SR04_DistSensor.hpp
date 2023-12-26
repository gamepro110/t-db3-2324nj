#ifndef LIB_HC_SR04_DISTSENSOR_HPP_
#define LIB_HC_SR04_DISTSENSOR_HPP_

#include "lib/HardwareTimer.hpp"
#include "lib/Interfaces/IDistanceSensor.hpp"
#include "lib/NucleoPin.hpp"

class HC_SR04_DistSensor : public IDistanceSensor {
public:
    HC_SR04_DistSensor(const NucleoPin pinEcho, const NucleoPin pinTrigger, const HardwareTimer tim);
    ~HC_SR04_DistSensor() override;

    int Setup(const uint16_t prescaler, const uint32_t resetValue, const uint8_t outputChannel, const uint32_t outputCCR, const uint8_t inputChannel1, const uint8_t inputChannel2);
    uint8_t GetDistance() override;

private:
    NucleoPin echoPin;
    NucleoPin triggerPin;
    HardwareTimer timer;
};

#endif
