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

// const uint16_t MsgSize{ 48 };
// struct LogMsgData {
//     char msg[MsgSize];
// };

#endif
