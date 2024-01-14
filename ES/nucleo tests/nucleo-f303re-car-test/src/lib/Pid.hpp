#ifndef LIB_PID_HPP_
#define LIB_PID_HPP_

#include "cstdint"

class PID {
public:
    PID(int16_t min, int16_t max, float kp, float ki, float kd);
    ~PID();

    int16_t Calculate(float target, float lastTarget);

    void ResetValues();
    void updateKP(float val);
    void updateKI(float val);
    void updateKD(float val);

private:
    int16_t min{ 0 };
    int16_t max{ 0 };
    float tau{ 0.001f };

    int16_t error{ 0 };
    int16_t prevError{ 0 };
    int16_t prevMeasurement{ 0 };
    float timeSec{ 0.001 };
    float derivative{ 0 };
    float integral{ 0 };

    float proportionalOut{ 0 };
    float integratorOut{ 0 };
    float differentiatorOut{ 0 };
    float output{ 0 };

    float kp{ 7.75f };
    float ki{ 0.03f };
    float kd{ 0.55f };

    const float defaultKp{ 7.75f };
    const float defaultKi{ 0.03f };
    const float defaultKd{ 0.55f };
};

#endif
