#include "FeedbackSensor.hpp"

FeedbackSensor::FeedbackSensor(NucleoPin pinSensor) :
    sensorPin(pinSensor)
{}

FeedbackSensor::FeedbackSensor(const FeedbackSensor &other) :
    sensorPin(other.sensorPin),
    speed(other.speed)
{}

FeedbackSensor::~FeedbackSensor() {
}

FeedbackSensor &FeedbackSensor::operator=(const FeedbackSensor &other) {
    sensorPin = other.sensorPin;
    speed = other.speed;

    return *this;
}

bool FeedbackSensor::Setup() {
    return sensorPin.Setup();
}

float FeedbackSensor::GetSpeed() {
    return speed;
}
