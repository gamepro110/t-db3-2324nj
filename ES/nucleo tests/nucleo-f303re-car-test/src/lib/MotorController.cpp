#include "MotorController.hpp"

#include "stm32f3xx_hal.h"
#include "usart.h"

#include <cstring>
#include <random>

MotorController::MotorController(osMessageQueueId_t id, uint8_t minDist, IMotor& leftMotor, IMotor& rightMotor, IFeedbackSensor& leftSense, IFeedbackSensor& rightSense) :
    id(id),
    minDetectDistance(minDist),
    motorLeft(&leftMotor),
    motorRight(&rightMotor),
    senseLeft(&leftSense),
    senseRight(&rightSense)
{
    SetDistance(minDist);
}

MotorController::MotorController(const MotorController &other) :
    id(other.id),
    minDetectDistance(other.minDetectDistance),
    motorLeft(other.motorLeft),
    motorRight(other.motorRight),
    senseLeft(other.senseLeft),
    senseRight(other.senseRight)
{
    SetDistance(other.minDetectDistance);
}

MotorController::~MotorController() {
}

MotorController &MotorController::operator=(const MotorController &other) {
    id = other.id;
    minDetectDistance = other.minDetectDistance;
    motorLeft = other.motorLeft;
    motorRight = other.motorRight;
    senseLeft = other.senseLeft;
    senseRight = other.senseRight;
    SetDistance(other.minDetectDistance);
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
    senseLeft->Update();
    senseRight->Update();

    uint8_t prio{ 0 };
    if (osMessageQueueGet(id, &data, &prio, 0) == osOK) {
        int16_t outputL = pidLeft.Calculate(minDetectDistance, data.distance);
        // int16_t outputR = pidRight.Calculate(data.distance, prevData.distance, TIM2->CNT);

        // const int MSGBUFSIZE = 80;
        // char msgBuf[MSGBUFSIZE];
        // snprintf(msgBuf, MSGBUFSIZE, "minDist: % 6d _ dist:% 6d _ ", minDetectDistance, data.distance);
        // HAL_UART_Transmit(&huart2, (uint8_t *)msgBuf, strlen(msgBuf), HAL_MAX_DELAY);
        // snprintf(msgBuf, MSGBUFSIZE, "outputL:% 6d  _ outputR:% 6d\r", outputL, outputR);
        // HAL_UART_Transmit(&huart2, (uint8_t *)msgBuf, strlen(msgBuf), HAL_MAX_DELAY);

        prevData = data;

        if (data.distance <= minDetectDistance) {
            SetSpeed(0);

            /*
            uint16_t r1{ rand() & 0xFFFF };
            uint16_t r2{ rand() & 0xFFFF };
            
            if ((r1 * r2) % 2 == 0) {
                TurnLeft(90);
            }
            else {
                TurnRight(90);
            } //*/
        }
        else {
            // SetSpeed(0);
            motorLeft->SetSpeed(outputL);
        }
    }

    osDelay(10);
}

void MotorController::SetSpeed(int16_t speed) {
    motorLeft->SetSpeed(speed);
    motorRight->SetSpeed(speed);
}

void MotorController::SetDistance(uint8_t dist) {
    minDetectDistance = dist;
}

void MotorController::TurnLeft(uint8_t deg) {
    motorRight->SetSpeed(deg);
    motorLeft->SetSpeed(-deg);
    uint64_t delay = HAL_GetTick();
    while (delay + 500 > HAL_GetTick());
    SetSpeed(0);
}

void MotorController::TurnRight(uint8_t deg) {
    motorRight->SetSpeed(-deg);
    motorLeft->SetSpeed(deg);
    uint64_t delay = HAL_GetTick();
    while (delay + (deg * 7.2f) > HAL_GetTick());
    SetSpeed(0);
}
