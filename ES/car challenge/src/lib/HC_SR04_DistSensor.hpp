#ifndef LIB_HC_SR04_DISTSENSOR_HPP_
#define LIB_HC_SR04_DISTSENSOR_HPP_

#include "lib/Interfaces/IDistanceSensor.hpp"
#include "lib/NucleoPin.hpp"

class HC_SR04_DistSensor : public IDistanceSensor {
public:
    HC_SR04_DistSensor(NucleoPin pinEcho, NucleoPin pinTrigger);
    ~HC_SR04_DistSensor();

    float GetDistance() override;

private:
    const NucleoPin echoPin;
    const NucleoPin triggerPin;
};

#endif
