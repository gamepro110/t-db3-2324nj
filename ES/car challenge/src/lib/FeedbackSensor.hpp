#ifndef LIB_FEEDBACKSENSOR_HPP_
#define LIB_FEEDBACKSENSOR_HPP_

#include "Interfaces/IFeedbackSensor.hpp"
#include "NucleoPin.hpp"

class FeedbackSensor : public IFeedbackSensor {
public:
    FeedbackSensor(NucleoPin pinSensor);
    ~FeedbackSensor();
    float GetSpeed() override;

private:
    const NucleoPin sensorPin;
    float speed{ 0.0f };
};

#endif
