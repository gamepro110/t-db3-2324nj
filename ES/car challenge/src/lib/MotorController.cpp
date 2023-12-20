#include "MotorController.hpp"

MotorController::MotorController(IMotor& leftMotor, IMotor& rightMotor, IFeedbackSensor& leftSense, IFeedbackSensor& rightSense) :
    motorLeft(leftMotor), motorRight(rightMotor), senseLeft(leftSense), senseRight(rightSense)
{}

MotorController::~MotorController()
{
}

void MotorController::Setup() {
}

void MotorController::Loop() {
}
