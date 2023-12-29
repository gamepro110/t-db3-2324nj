#include "HC_SR04_DistSensor.hpp"

#include "lib/Logger.hpp"

HC_SR04_DistSensor::HC_SR04_DistSensor(const NucleoPin pinEcho, const NucleoPin pinTrigger, const HardwareTimer tim) :
    echoPin(pinEcho), triggerPin(pinTrigger), timer(tim)
{
}

HC_SR04_DistSensor::~HC_SR04_DistSensor() {
}

bool HC_SR04_DistSensor::Setup() {
    const uint32_t prescalar{ 72 };
    const uint32_t resetValue{ 100000 };
    const uint8_t outputChannel{ 3 };
    const uint32_t outputCCR{ 100 };
    const uint8_t inputChannel1{ 1 };
    const uint8_t inputChannel2{ 2 };

    logger.Log("setup dist sensor\n");

    return (
        echoPin.Setup() &&
        triggerPin.Setup() &&
        SetupTimer(prescalar, resetValue, outputChannel, outputCCR, inputChannel1, inputChannel2)
    );
}

bool HC_SR04_DistSensor::SetupTimer(
    const uint16_t prescaler, const uint32_t resetValue, const uint8_t outputChannel, const uint32_t outputCCR,
    const uint8_t inputChannel1, const uint8_t inputChannel2
) {
    if (!(echoPin.Setup() && triggerPin.Setup())) {
        return false;
    }

    TIM_TypeDef* tim = timer.GetTimPtr();

    if (tim == TIM16 || tim == TIM17) {
        return false;
    }

    //setup output
    timer.SetEnablePeripheralClock();
    timer.SetPrescaler(prescaler);
    timer.SetAutoReload(resetValue);
    timer.SetEnableCCModex(outputChannel, 0, 6);
    timer.SetCCRxRegister(outputCCR, outputChannel);
    timer.SetEnableCCx(outputChannel, 1, 0, 0);

    if (tim == TIM15 || tim == TIM16 || tim == TIM17) {
        tim->BDTR |= TIM_BDTR_MOE;
    }
    //setup output

    //setup input
    timer.SetPrescaler(prescaler);
    timer.SetEnableCCModex(inputChannel1, 1, 0);
    timer.SetEnableCCModex(inputChannel2, 2, 0);
    timer.SetEnableCCx(inputChannel1, 1, 0, 0);
    timer.SetEnableCCx(inputChannel2, 1, 1, 0);
    timer.SetSlaveModeResetFP1();
    //setup input

    timer.SetTimerEnable();
    return true;
}

/// @return distance in cm
uint8_t HC_SR04_DistSensor::GetDistance() {
    return (timer.GetCaptureCompareRegister2() / 58) & 0xFF;
}
