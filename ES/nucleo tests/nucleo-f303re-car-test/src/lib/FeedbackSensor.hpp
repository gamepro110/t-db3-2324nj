#ifndef LIB_FEEDBACKSENSOR_HPP_
#define LIB_FEEDBACKSENSOR_HPP_

#include "lib/Interfaces/IFeedbackSensor.hpp"
#include "lib/NucleoPin.hpp"
#include "lib/HardwareTimer.hpp"

//TODO implement
//TODO add hardware timere
class FeedbackSensor : public IFeedbackSensor {
public:
    FeedbackSensor() = default;
    FeedbackSensor(NucleoPin pinSensor, HardwareTimer timer);
    FeedbackSensor(const FeedbackSensor& other);
    ~FeedbackSensor();

    FeedbackSensor& operator=(const FeedbackSensor& other);

    bool Setup() override;
    void Update() override;
    float GetSpeed() const override;

private:
    int32_t CalcDeg(const int32_t curDuty);
    float CalcRpm(const float delta, const int32_t time);

    NucleoPin sensorPin{};
    HardwareTimer tim{ nullptr };
    float speed{ 0.0f };

    // rpm calc
    float delta{};
    int32_t curTime{};
    int32_t curDuty{};
    int32_t angleCur{};
    int32_t angleLast{};
};

#endif
