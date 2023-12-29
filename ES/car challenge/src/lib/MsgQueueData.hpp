#ifndef LIB_MSGQUEUEDATA_HPP_
#define LIB_MSGQUEUEDATA_HPP_

#include <cstdint>

struct BtnMsgData {
    int butNr;
    int Duration;
};

struct SensorMsgData {
    uint8_t distance;
};

#endif
