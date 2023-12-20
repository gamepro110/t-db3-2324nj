#ifndef LIB_PID_HPP_
#define LIB_PID_HPP_

#include "cstdint"

class PID {
public:
    PID(uint32_t Kp, uint32_t Ki, uint32_t Kd);
    ~PID();

    void SetKP(uint32_t value);
    void SetKI(uint32_t value);
    void SetKD(uint32_t value);

private:
    uint32_t kp{ 0 };
    uint32_t ki{ 0 };
    uint32_t kd{ 0 };
};

#endif
