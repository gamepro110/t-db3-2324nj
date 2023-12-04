#ifndef LIB_QUEUEDATA_H_
#define LIB_QUEUEDATA_H_

#include <cstdint>

typedef struct QueueData {
    uint16_t buttonId;
    uint16_t pressDuration;
} QueueData;

#endif
