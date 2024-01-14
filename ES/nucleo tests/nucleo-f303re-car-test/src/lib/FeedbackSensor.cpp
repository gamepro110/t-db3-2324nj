#include "FeedbackSensor.hpp"

FeedbackSensor::FeedbackSensor(NucleoPin pinSensor, HardwareTimer timer) :
    sensorPin(pinSensor),
    tim(timer)
{}

FeedbackSensor::FeedbackSensor(const FeedbackSensor &other) :
    sensorPin(other.sensorPin),
    tim(other.tim),
    speed(other.speed)
{}

FeedbackSensor::~FeedbackSensor() {
}

FeedbackSensor &FeedbackSensor::operator=(const FeedbackSensor &other) {
    sensorPin = other.sensorPin;
    speed = other.speed;
    tim = other.tim;
    return *this;
}

bool FeedbackSensor::Setup() {
    tim.SetEnablePeripheralClock();
    tim.SetPrescaler(79);

    tim.SetEnableCCModex(1, 1, 0);
    tim.SetEnableCCModex(2, 2, 0);

    tim.SetEnableCCx(1, 1, 0, 0);
    tim.SetEnableCCx(2, 1, 1, 0);

    tim.SetSlaveModeResetFP1();
    tim.SetTimerEnable();

    return sensorPin.Setup();
}

void FeedbackSensor::Update() {
    curTime = static_cast<int32_t>(tim.GetCaptureCompareRegister1());
    curDuty = static_cast<int32_t>(tim.GetCaptureCompareRegister2());

    angleLast = angleCur;
    angleCur = CalcDeg(curDuty);

    delta = angleCur - angleLast;
    speed = CalcRpm(delta, curTime);
}

float FeedbackSensor::GetSpeed() const {
    return speed;
}

int32_t FeedbackSensor::CalcDeg(const int32_t curDuty) {
    const int32_t dutyCycleMin{ 26 };
    const int32_t dutyCycleMax{ 972 };
    return ((curDuty - dutyCycleMin) * 360)/(dutyCycleMax - dutyCycleMin + 1);
}

float FeedbackSensor::CalcRpm(const float delta, const int32_t time) {
    return (((delta * 60000) / 2) / 360 * time);
}
