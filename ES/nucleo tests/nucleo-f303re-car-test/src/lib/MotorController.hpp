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
    MotorController(osMessageQueueId_t id, uint8_t minDist, IMotor& leftMotor, IMotor& rightMotor, IFeedbackSensor& leftSense, IFeedbackSensor& rightSense);
    MotorController(const MotorController& other);
    ~MotorController();

    MotorController& operator=(const MotorController& other);

    bool Setup();
    void Loop();
    /// @param speed absolute max value = 100
    void SetSpeed(int16_t speed);
    void SetDistance(uint8_t dist);

private:
    void TurnLeft(uint8_t deg);
    void TurnRight(uint8_t deg);

    osMessageQueueId_t id{ nullptr };
    uint8_t minDetectDistance{ 10 };
    IMotor* motorLeft{ nullptr };
    IMotor* motorRight{ nullptr };
    IFeedbackSensor* senseLeft{ nullptr };
    IFeedbackSensor* senseRight{ nullptr };
    PID pidLeft{ -100, 100, 7.75f, 0.03f, 0.55f };
    // PID pidRight{ -100, 100, 7.75f, 0.03f, 0.55f };
    SensorMsgData data{ };
    SensorMsgData prevData{ };
};

#endif
