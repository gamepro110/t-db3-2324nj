#ifndef LIB_IMOTOR_HPP_
#define LIB_IMOTOR_HPP_

#include <cstdint>

class IMotor {
public:
    virtual ~IMotor() {}
    virtual bool IsReversed() const = 0;
    /// @param value 0-100
    virtual void SetSpeed(uint8_t value) = 0;
};

#endif
