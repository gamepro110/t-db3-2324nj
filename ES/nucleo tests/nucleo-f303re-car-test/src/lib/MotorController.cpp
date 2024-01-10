#include "MotorController.hpp"

MotorController::MotorController(osMessageQueueId_t id, IMotor& leftMotor, IMotor& rightMotor, IFeedbackSensor& leftSense, IFeedbackSensor& rightSense) :
    id(id),
    motorLeft(&leftMotor),
    motorRight(&rightMotor),
    senseLeft(&leftSense),
    senseRight(&rightSense)
{}

MotorController::MotorController(const MotorController &other) :
    motorLeft(other.motorLeft),
    motorRight(other.motorRight),
    senseLeft(other.senseLeft),
    senseRight(other.senseRight)
{}

MotorController::~MotorController() {
}

MotorController &MotorController::operator=(const MotorController &other) {
    motorLeft = other.motorLeft;
    motorRight = other.motorRight;
    senseLeft = other.senseLeft;
    senseRight = other.senseRight;
    return *this;
}

bool MotorController::Setup() {
    return (motorLeft->Setup()
        && motorRight->Setup()
        && senseLeft->Setup()
        && senseRight->Setup()
    );
}

void MotorController::Loop() {
    uint8_t prio{ 0 };
    if (osMessageQueueGet(id, &data, &prio, 10) == osOK) {
        logger.Logf("^:% 3d --- \r", data.distance);
        pid.SetError(data.distance);
    }
}

void MotorController::SetSpeed(int16_t speed) {
    motorLeft->SetSpeed(speed);
    motorRight->SetSpeed(speed);
}
