#ifndef LIB_IDISTANCESENSOR_HPP_
#define LIB_IDISTANCESENSOR_HPP_

#include <cstdint>

class IDistanceSensor {
public:
    virtual ~IDistanceSensor() {}
    virtual uint8_t GetDistance() = 0;
};

#endif
