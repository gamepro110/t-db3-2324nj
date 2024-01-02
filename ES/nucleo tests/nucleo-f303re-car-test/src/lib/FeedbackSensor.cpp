#include "FeedbackSensor.hpp"

FeedbackSensor::FeedbackSensor(NucleoPin pinSensor) :
    sensorPin(pinSensor)
{}

FeedbackSensor::~FeedbackSensor() {
}

float FeedbackSensor::GetSpeed() {
    return speed;
}
