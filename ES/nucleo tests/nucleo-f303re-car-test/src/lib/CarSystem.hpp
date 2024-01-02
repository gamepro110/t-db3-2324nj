#ifndef LIB_CARSYSTEM_HPP_
#define LIB_CARSYSTEM_HPP_

#include "lib/Interfaces/IDistanceSensor.hpp"
#include "lib/ManualControlPanel.hpp"
#include "lib/MsgQueueData.hpp"

#include "cmsis_os2.h"

class CarSystem {
public:
    CarSystem() = default;
    CarSystem(osMessageQueueId_t id, IDistanceSensor& sensor, ManualControlPanel& MCP);
    ~CarSystem();

    CarSystem& operator=(const CarSystem& other);

    bool Setup();
    void Update();

private:
    osMessageQueueId_t queueId{ nullptr };
    IDistanceSensor* distSensor{ nullptr };
    ManualControlPanel* mcp{ nullptr };
    SensorMsgData data{};
};

#endif
