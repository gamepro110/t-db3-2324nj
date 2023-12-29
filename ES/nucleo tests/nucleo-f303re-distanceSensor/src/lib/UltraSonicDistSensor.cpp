#include "UltraSonicDistSensor.hpp"

UltraSonicDistSensor::UltraSonicDistSensor(HardwareTimer timer, NucleoPin pinEcho, NucleoPin pinTrigger) :
    tim(timer),
    echoPin(pinEcho),
    trigPin(pinTrigger)
{}

UltraSonicDistSensor::~UltraSonicDistSensor() {
}

bool UltraSonicDistSensor::Setup(uint8_t prescaler, uint32_t arrValue, uint32_t outputCCValue, const uint8_t outputChannel, const uint8_t inputChannel1, const uint8_t inputChannel2) {
    return 
        echoPin.Setup() && 
        trigPin.Setup() && 
        tim.Init(prescaler, arrValue, outputCCValue, outputChannel, inputChannel1, inputChannel2);
}

uint8_t UltraSonicDistSensor::GetDist() {
    return tim.GetCaptureCompareRegister2() / 58;
}
