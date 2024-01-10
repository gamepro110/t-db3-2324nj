#ifndef LIB_PID_HPP_
#define LIB_PID_HPP_

#include "cstdint"

class PID {
public:
    PID(int16_t target);
    ~PID();

    int16_t GetError() const;
    void SetError(const int16_t value);
    int16_t CalculateError(const int16_t value);
    int16_t CalculateOutput();
    void ResetValues();
    void SetTarget(const int16_t target);
    void updateKP(float val);
    void updateKI(float val);
    void updateKD(float val);

private:
    int16_t targetVal;
    int16_t errorVal;
    int16_t prevErrorVal;
    int16_t integral;
    float kp{ 7.75f };
    float ki{ 0.03f };
    float kd{ 0.55f };

    const float defaultKp{ 7.75f };
    const float defaultKi{ 0.03f };
    const float defaultKd{ 0.55f };
};

#endif
