#ifndef LIB_RECEIVER_H_
#define LIB_RECEIVER_H_

#include "QueueData.h"

#include "FreeRTOS.h"
#include "task.h"
#include "main.h"
#include "cmsis_os.h"

#include <queue.h>

class Receiver {
public:
    Receiver() = default;
    ~Receiver() = default;

    void Setup(osMessageQueueId_t handle);
    void Loop();

    osMessageQueueId_t queueId;
};

#endif
