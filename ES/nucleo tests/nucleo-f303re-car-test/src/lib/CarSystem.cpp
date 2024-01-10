#include "CarSystem.hpp"

#include "lib/Logger.hpp"

#include "stm32f303xe.h"

CarSystem::CarSystem(osMessageQueueId_t id, IDistanceSensor& sensor, ManualControlPanel& MCP, MotorController& controller) :
    queueId(id),
    distSensor(&sensor),
    mcp(&MCP),
    motorController(&controller)
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
    data.distance = distSensor->GetDistance();
    osMessageQueuePut(queueId, &data, 0, osWaitForever);
    osDelay(10);
}
