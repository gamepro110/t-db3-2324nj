#ifndef LIB_FEEDBACKSENSOR_HPP_
#define LIB_FEEDBACKSENSOR_HPP_

#include "Interfaces/IFeedbackSensor.hpp"
#include "NucleoPin.hpp"

//TODO implement
//TODO add hardware timere
class FeedbackSensor : public IFeedbackSensor {
public:
    FeedbackSensor() = default;
    FeedbackSensor(NucleoPin pinSensor);
    FeedbackSensor(const FeedbackSensor& other);
    ~FeedbackSensor();

    FeedbackSensor& operator=(const FeedbackSensor& other);

    bool Setup() override;
    float GetSpeed() override;

private:
    NucleoPin sensorPin{};
    float speed{ 0.0f };
};

#endif
