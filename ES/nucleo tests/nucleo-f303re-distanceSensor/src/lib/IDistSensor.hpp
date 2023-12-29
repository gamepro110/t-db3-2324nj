#ifndef LIB_IDISTSENSOR_HPP
#define LIB_IDISTSENSOR_HPP

#include <cstdint>

class IDistSensor {
public:
    virtual ~IDistSensor() {}
    virtual uint8_t GetDist() = 0;
};

#endif
