#include "FeedbackSensor.hpp"

FeedbackSensor::FeedbackSensor(NucleoPin pinSensor) :
    sensorPin(pinSensor)
{}

FeedbackSensor::~FeedbackSensor() {
}

FeedbackSensor& FeedbackSensor::operator=(const FeedbackSensor &other) {
    speed = other.speed;
    sensorPin = other.sensorPin;
    return *this;
}

float FeedbackSensor::GetSpeed() {
    return speed;
}
