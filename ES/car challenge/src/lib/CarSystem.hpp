#ifndef LIB_CARSYSTEM_HPP_
#define LIB_CARSYSTEM_HPP_

#include "cmsis_os2.h"

class CarSystem {
public:
    CarSystem(osMessageQueueId_t id);
    ~CarSystem();

private:
    osMessageQueueId_t queueId;
};

#endif
