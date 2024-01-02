#include "HC_SR04_DistSensor.hpp"

#include "lib/Logger.hpp"

HC_SR04_DistSensor::HC_SR04_DistSensor(NucleoPin &pinEcho, NucleoPin &pinTrigger, const HardwareTimer tim) : echoPin(pinEcho), trigPin(pinTrigger), timer(tim)
{
}

HC_SR04_DistSensor::HC_SR04_DistSensor(const HC_SR04_DistSensor &other) :
    echoPin(other.echoPin),
    trigPin(other.trigPin),
    timer(other.timer)
{
}

HC_SR04_DistSensor::~HC_SR04_DistSensor() {
}

HC_SR04_DistSensor &HC_SR04_DistSensor::operator=(const HC_SR04_DistSensor &other) {
    echoPin = other.echoPin;
    trigPin = other.trigPin;
    timer = other.timer;

    return *this;
}

bool HC_SR04_DistSensor::Setup(uint8_t prescaler, uint32_t arrValue, uint32_t outputCCValue, const uint8_t outputChannel, const uint8_t inputChannel1, const uint8_t inputChannel2) {
    return (
        timer.Init(prescaler, arrValue, outputCCValue, outputChannel, inputChannel1, inputChannel2) &&
        echoPin.Setup() &&
        trigPin.Setup()
    );
}

uint8_t HC_SR04_DistSensor::GetDistance() {
    return timer.GetCaptureCompareRegister2() / 58;
}
