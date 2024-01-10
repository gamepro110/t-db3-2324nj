#include "Pid.hpp"

PID::PID(int16_t target) :
    targetVal(target),
    errorVal(0)
{}

PID::~PID() {
}

int16_t PID::GetError() const {
    return errorVal;
}

void PID::SetError(const int16_t value) {
    prevErrorVal = errorVal;
    errorVal = value;
}

int16_t PID::CalculateError(const int16_t value) {
    prevErrorVal = errorVal;
    errorVal = targetVal - value;
    return errorVal;
}

int16_t PID::CalculateOutput() {
    integral = (errorVal >= 0) ? 0 : (integral + errorVal);
    return errorVal * kp + ki * integral + (errorVal - prevErrorVal) * kd;
}

void PID::ResetValues() {
    kp = defaultKp;
    ki = defaultKi;
    kd = defaultKd;
}

void PID::SetTarget(const int16_t target) {
    targetVal = target;
}

void PID::updateKP(float val) {
    ki = val;
}

void PID::updateKI(float val) {
    ki = val;
}

void PID::updateKD(float val) {
    ki = val;
}
