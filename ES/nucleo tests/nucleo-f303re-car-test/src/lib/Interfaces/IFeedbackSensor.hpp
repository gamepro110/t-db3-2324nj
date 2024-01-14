#ifndef LIB_IFEEDBACKSENSOR_HPP_
#define LIB_IFEEDBACKSENSOR_HPP_

class IFeedbackSensor {
public:
    virtual bool Setup() = 0;
    virtual void Update() = 0;
    virtual float GetSpeed() const = 0;
};

#endif
