#include "Pid.hpp"

PID::PID(uint32_t Kp, uint32_t Ki, uint32_t Kd) :
    kp(Kd), ki(Ki), kd(Kd)
{
}

void PID::SetKP(uint32_t value) {
    kp = value;
}

void PID::SetKI(uint32_t value) {
    ki = value;
}

void PID::SetKD(uint32_t value) {
    kd = value;
}
