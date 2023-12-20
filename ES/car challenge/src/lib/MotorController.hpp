#ifndef LIB_MOTORCONTROLLER_HPP_
#define LIB_MOTORCONTROLLER_HPP_

#include "lib/Interfaces/IFeedbackSensor.hpp"
#include "lib/Interfaces/IMotor.hpp"

#include "lib/Pid.hpp"

class MotorController {
public:
    MotorController(IMotor& leftMotor, IMotor& rightMotor, IFeedbackSensor& leftSense, IFeedbackSensor& rightSense);
    ~MotorController();

    void Setup();
    void Loop();

private:
    const IMotor& motorLeft;
    const IMotor& motorRight;
    const IFeedbackSensor& senseLeft;
    const IFeedbackSensor& senseRight;
    PID pidLeft{ 0, 0, 0 };
    PID pidRight{ 0, 0, 0 };
};

#endif
