#include "Sender.h"

void Sender::Setup(osMessageQueueId_t id) {
    this->queueId = id;
}

void Sender::Loop() {
    while (1) {
        data.pressDuration++;
        osMessageQueuePut(queueId, (void*)&data, 0, 0);
        osDelay(100);
    }
}
