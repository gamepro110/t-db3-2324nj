#ifndef LIB_SERVOMOTOR_HPP_
#define LIB_SERVOMOTOR_HPP_

#include "lib/Interfaces/IMotor.hpp"

#include "lib/NucleoPin.hpp"

class ServoMotor : public IMotor {
public:
    ServoMotor(NucleoPin pinMotor, bool reserved);
    ~ServoMotor();

    bool IsReversed() const override;
    void SetSpeed(uint8_t value) override;

private:
    NucleoPin motorPin;
    const bool isReversed;
};

#endif
