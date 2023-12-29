#include "CarSystem.hpp"

#include "lib/Logger.hpp"

#include "stm32f303xe.h"

CarSystem::CarSystem(osMessageQueueId_t id, IDistanceSensor& sensor) :
    queueId(id),
    distSensor(sensor)
{
}

CarSystem::~CarSystem() {
}

bool CarSystem::Setup() {
    return queueId != nullptr;
}

void CarSystem::Update() {
    uint8_t dist{ distSensor.GetDistance() };
    data.butNr = 0;
    data.Duration = dist;
    osMessageQueuePut(queueId, &data, 0, osWaitForever);
    osDelay(1);
}
