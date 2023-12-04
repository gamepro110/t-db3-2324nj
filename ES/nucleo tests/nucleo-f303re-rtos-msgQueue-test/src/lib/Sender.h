#ifndef LIB_SENDER_H_
#define LIB_SENDER_H_

#include "QueueData.h"

#include "FreeRTOS.h"
#include "task.h"
#include "main.h"
#include "cmsis_os.h"

#include <queue.h>

class Sender {
public:
    Sender() = default;
    ~Sender() = default;

    void Setup(osMessageQueueId_t handle);
    void Loop();

    osMessageQueueId_t queueId{ };
    QueueData data{ 0, 0 };
};

#endif
