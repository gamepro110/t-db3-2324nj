#include "ManualControlPanel.hpp"

#include "lib/Logger.hpp"

#include "cmsis_os2.h"

ManualControlPanel::ManualControlPanel(IButton& btn1, IButton& btn2) :
    button1(&btn1),
    button2(&btn2)
{}

ManualControlPanel::ManualControlPanel(const ManualControlPanel& other) :
    button1(other.button1),
    button2(other.button2)
{}

ManualControlPanel::~ManualControlPanel()
{}

ManualControlPanel &ManualControlPanel::operator=(const ManualControlPanel &other) {
    button1 = other.button1;
    button2 = other.button2;
    return *this;
}

bool ManualControlPanel::Setup() {
    bool b1{ button1->SetupIrq() };
    bool b2{ button2->SetupIrq() };
    return (b1 && b2);
}

void ManualControlPanel::Loop() {
    osDelay(100);
    logger.Log("loop\r");
    //TODO add serial options
}
