#include "CarSystem.hpp"

#include "lib/Logger.hpp"

#include "stm32f303xe.h"

CarSystem::CarSystem(osMessageQueueId_t id, IDistanceSensor& sensor, ManualControlPanel& MCP) :
    queueId(id),
    distSensor(&sensor),
    mcp(&MCP)
{
}

CarSystem::~CarSystem() {
}

CarSystem &CarSystem::operator=(const CarSystem &other) {
    queueId = other.queueId;
    data = other.data;
    distSensor = other.distSensor;
    return *this;
}

bool CarSystem::Setup() {
    return queueId != nullptr;
}

void CarSystem::Update() {
    uint8_t dist{ distSensor->GetDistance() };
    data.distance = dist;
    osMessageQueuePut(queueId, &data, 0, osWaitForever);
    osDelay(10);
}
