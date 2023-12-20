#include "ServoMotor.hpp"

ServoMotor::ServoMotor(NucleoPin pinMotor, bool reserved) :
    motorPin(pinMotor), isReversed(reserved)
{
    uint8_t mode = 1;
    AltModeValue altValue{ (uint64_t)mode << (4 * motorPin.GetPinNr()) };
    motorPin.SetAltMode(altValue);
}

ServoMotor::~ServoMotor() {
}

bool ServoMotor::IsReversed() const {
    return isReversed;
}

void ServoMotor::SetSpeed(uint8_t value) {
    //TODO
}
