#include "ManualControlPanel.hpp"

#include "lib/Logger.hpp"
#include "lib/Watchdog.hpp"

#include "cmsis_os2.h"

extern Watchdog watchdog;

ManualControlPanel::ManualControlPanel(IButton& btn1, IButton& btn2) :
    button1(btn1), button2(btn2)
{}

ManualControlPanel::~ManualControlPanel()
{}

bool ManualControlPanel::Setup() {
    watchdog.Reset();
    bool b1{ button1.SetupIrq() };
    watchdog.Reset();
    bool b2{ button2.SetupIrq() };
    watchdog.Reset();
    return (b1 && b2);
}

void ManualControlPanel::Loop() {
    osDelay(100);
    logger.Log("loop\r");
    //TODO add serial options
}
