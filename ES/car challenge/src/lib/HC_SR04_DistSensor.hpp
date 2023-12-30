#ifndef LIB_HC_SR04_DISTSENSOR_HPP_
#define LIB_HC_SR04_DISTSENSOR_HPP_

#include "lib/HardwareTimer.hpp"
#include "lib/Interfaces/IDistanceSensor.hpp"
#include "lib/NucleoPin.hpp"

class HC_SR04_DistSensor : public IDistanceSensor {
public:
    HC_SR04_DistSensor(NucleoPin& pinEcho, NucleoPin& pinTrigger, const HardwareTimer tim);
    ~HC_SR04_DistSensor() override;

    bool Setup(uint8_t prescaler, uint32_t arrValue, uint32_t outputCCValue, const uint8_t outputChannel, const uint8_t inputChannel1, const uint8_t intputChannel2);
    uint8_t GetDistance() override;

private:
    NucleoPin& echoPin;
    NucleoPin& trigPin;
    HardwareTimer timer;
};

#endif
