#ifndef LIB_MOTORCONTROLLER_HPP_
#define LIB_MOTORCONTROLLER_HPP_

#include "lib/Interfaces/IFeedbackSensor.hpp"
#include "lib/Interfaces/IMotor.hpp"

#include "lib/Pid.hpp"
#include "lib/MsgQueueData.hpp"
#include "lib/Logger.hpp"

#include "cmsis_os2.h"

class MotorController {
public:
    MotorController() = default;
    MotorController(osMessageQueueId_t id, IMotor& leftMotor, IMotor& rightMotor, IFeedbackSensor& leftSense, IFeedbackSensor& rightSense);
    MotorController(const MotorController& other);
    ~MotorController();

    MotorController& operator=(const MotorController& other);

    bool Setup();
    void Loop();
    void SetSpeed(int16_t speed);

private:
    osMessageQueueId_t id{ nullptr };
    IMotor* motorLeft{ nullptr };
    IMotor* motorRight{ nullptr };
    IFeedbackSensor* senseLeft{ nullptr };
    IFeedbackSensor* senseRight{ nullptr };
    PID pid{ 5 };
    SensorMsgData data;
};

#endif
