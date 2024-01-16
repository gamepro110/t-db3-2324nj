#ifndef LIB_PID_HPP_
#define LIB_PID_HPP_

#include "cstdint"

class PID {
public:
    PID(int16_t min, int16_t max, float kp = 8.1f, float ki = 10.71428571f, float kd = 1.5309f);
    ~PID();

    int16_t Calculate(float target, float lastTarget);

    void ResetValues();
    void updateKP(float val);
    void updateKI(float val);
    void updateKD(float val);

    const float& GetKP() const { return kp; }
    const float& GetKI() const { return ki; }
    const float& GetKD() const { return kd; }

private:
    int16_t min{ 0 };
    int16_t max{ 0 };
    float tau{ 0.01f };

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

    float kp{ 8.1f };
    float ki{ 10.71428571f };
    float kd{ 1.5309f };

    const float defaultKp{ 8.1f };
    const float defaultKi{ 10.71428571f };
    const float defaultKd{ 1.5309f };
};

#endif
