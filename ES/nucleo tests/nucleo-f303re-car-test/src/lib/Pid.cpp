#include "Pid.hpp"

PID::PID(int16_t min, int16_t max, float kp, float ki, float kd) :
    min(min),
    max(max),
    error(0),
    prevError(0),
    kp(kp),
    ki(ki),
    kd(kd)
{
}

PID::~PID() {
}

int16_t PID::Calculate(float setpoint, float measurement) {
    error = measurement - setpoint;

    proportionalOut = kp * error;

    integratorOut = integratorOut + ki * tau * error;

    if (error == 0 || integratorOut > setpoint || integratorOut > (1 << 15)) {
        integratorOut = 0;
    }

    differentiatorOut = kd * (error - prevError);

    output = proportionalOut + integratorOut + differentiatorOut;

    if (output > max) {
        output = max;
    }
    else if (output < min) {
        output = min;
    }
    prevError = error;
    prevMeasurement = measurement;

    return (int16_t)output;
}

void PID::ResetValues() {
    kp = defaultKp;
    ki = defaultKi;
    kd = defaultKd;
}

void PID::updateKP(float val) {
    kp = val;
}

void PID::updateKI(float val) {
    ki = val;
}

void PID::updateKD(float val) {
    kd = val;
}
