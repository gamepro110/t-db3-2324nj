#include "ServoMotor.hpp"

ServoMotor::ServoMotor(NucleoPin pinMotor, HardwareTimer& timer, uint8_t ccChannelNum, bool reversed) :
    motorPin(pinMotor),
    tim(timer),
    isReversed(reversed),
    ccrChannel(ccChannelNum)
{
}

ServoMotor::ServoMotor(const ServoMotor &other) :
    motorPin(other.motorPin),
    tim(other.tim),
    isReversed(other.isReversed),
    ccrChannel(other.ccrChannel)
{}

ServoMotor::~ServoMotor() {
}

ServoMotor& ServoMotor::operator=(const ServoMotor &other) {
    motorPin = other.motorPin;
    tim = other.tim;
    isReversed = other.isReversed;
    ccrChannel = other.ccrChannel;
    return *this;
}

bool ServoMotor::Setup() {
    tim.SetEnableCCModex(ccrChannel, 0, 6);
    tim.SetCCRxRegister(servoIdleValue, ccrChannel);
    tim.SetEnableCCx(ccrChannel, 1, 0, 0);

    TIM15->BDTR |= TIM_BDTR_MOE;
    return motorPin.Setup();
}

bool ServoMotor::IsReversed() const {
    return isReversed;
}

void ServoMotor::SetSpeed(int8_t value) {
    value = (value < -maxSetSpeedValue) ? -maxSetSpeedValue : value; // clamp negative val
    value = (value > maxSetSpeedValue) ? maxSetSpeedValue : value; // clamp positive val

    value *= isReversed ? -1 : 1;
    tim.SetCCRxRegister(servoIdleValue + (2 * value), ccrChannel);
}
