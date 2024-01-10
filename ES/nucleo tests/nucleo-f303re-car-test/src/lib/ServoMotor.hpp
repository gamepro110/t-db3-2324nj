#ifndef LIB_SERVOMOTOR_HPP_
#define LIB_SERVOMOTOR_HPP_

#include "lib/Interfaces/IMotor.hpp"
#include "lib/HardwareTimer.hpp"

#include "lib/NucleoPin.hpp"

//TODO add HardwareTim
class ServoMotor : public IMotor {
public:
    ServoMotor() = default;
    ServoMotor(NucleoPin pinMotor, HardwareTimer& timer, uint8_t ccChannelNum, bool reversed);
    ServoMotor(const ServoMotor& other);
    ~ServoMotor();

    ServoMotor& operator=(const ServoMotor& other);

    bool Setup() override;
    bool IsReversed() const override;
    void SetSpeed(int8_t value) override;

private:
    NucleoPin motorPin{};
    HardwareTimer tim{ nullptr };
    bool isReversed{ false };
    uint8_t ccrChannel{ 1 };
    const uint8_t maxSetSpeedValue{ 100 };
    const uint16_t servoIdleValue{ 1500 };
};

#endif
