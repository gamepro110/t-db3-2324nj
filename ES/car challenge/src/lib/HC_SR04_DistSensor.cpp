#include "HC_SR04_DistSensor.hpp"

HC_SR04_DistSensor::HC_SR04_DistSensor(NucleoPin pinEcho, NucleoPin pinTrigger) :
    echoPin(pinEcho), triggerPin(pinTrigger)
{
}

HC_SR04_DistSensor::~HC_SR04_DistSensor() {
}

float HC_SR04_DistSensor::GetDistance() {
    return 0.0f;
}
