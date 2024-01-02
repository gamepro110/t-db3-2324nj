#ifndef LIB_FEEDBACKSENSOR_HPP_
#define LIB_FEEDBACKSENSOR_HPP_

#include "Interfaces/IFeedbackSensor.hpp"
#include "NucleoPin.hpp"

class FeedbackSensor : public IFeedbackSensor {
public:
    FeedbackSensor() = default;
    FeedbackSensor(NucleoPin pinSensor);
    ~FeedbackSensor();

    FeedbackSensor& operator=(const FeedbackSensor& other);

    float GetSpeed() override;

private:
    NucleoPin sensorPin{ GPIOA, 0 };
    float speed{ 0.0f };
};

#endif
