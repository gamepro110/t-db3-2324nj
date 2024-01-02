#ifndef LIB_IDISTANCESENSOR_HPP_
#define LIB_IDISTANCESENSOR_HPP_

#include <cstdint>

class IDistanceSensor {
public:
    virtual ~IDistanceSensor() {}
    /// @return distance in cm
    virtual uint8_t GetDistance() = 0;
};

#endif
