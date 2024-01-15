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
#include <usart.h>
#include <cstring>
#include <stdio.h>
//! the more i work on this the more i feel i don't know anything....
int16_t PID::Calculate(float setpoint, float measurement) {
    // <https://youtu.be/zOByx3Izf5U>
    error = measurement - setpoint;

    proportionalOut = kp * error;

    integratorOut = integratorOut + ki * tau * error;

    differentiatorOut = kd * (error - prevError);

    output = proportionalOut + integratorOut + differentiatorOut;

    // const int MSGBUFSIZE = 60;
    // char msgBuf[MSGBUFSIZE];
    // snprintf(msgBuf, MSGBUFSIZE, "set:% -4.0f_ meas:% -4.0f_ ", setpoint, measurement);
    // HAL_UART_Transmit(&huart2, (uint8_t *)msgBuf, strlen(msgBuf), HAL_MAX_DELAY);
    // snprintf(msgBuf, MSGBUFSIZE, "e:% -4d_ pout:% -10.0f_ ", error, proportionalOut);
    // HAL_UART_Transmit(&huart2, (uint8_t *)msgBuf, strlen(msgBuf), HAL_MAX_DELAY);
    // snprintf(msgBuf, MSGBUFSIZE, "iout:% -10.0f_ dout:% -10.0f _ ", integratorOut, differentiatorOut);
    // HAL_UART_Transmit(&huart2, (uint8_t *)msgBuf, strlen(msgBuf), HAL_MAX_DELAY);
    // snprintf(msgBuf, MSGBUFSIZE, "out: %-10f_ \r", output);
    // HAL_UART_Transmit(&huart2, (uint8_t *)msgBuf, strlen(msgBuf), HAL_MAX_DELAY);

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
