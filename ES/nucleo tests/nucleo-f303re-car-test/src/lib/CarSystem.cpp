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

CarSystem::CarSystem(const CarSystem& other) :
    queueId(other.queueId),
    distSensor(other.distSensor),
    mcp(other.mcp),
    motorController(other.motorController)
{
}

CarSystem::~CarSystem() {
}

CarSystem &CarSystem::operator=(const CarSystem &other) {
    queueId = other.queueId;
    data = other.data;
    distSensor = other.distSensor;
    motorController = other.motorController;
    mcp = other.mcp;
    return *this;
}

bool CarSystem::Setup() {
    return queueId != nullptr;
}

void CarSystem::Update() {
    data.distance = distSensor->GetDistance();
    osMessageQueuePut(queueId, &data, 0, 0);
    osDelay(1);
}
