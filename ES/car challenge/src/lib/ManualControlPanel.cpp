#include "ManualControlPanel.hpp"

ManualControlPanel::ManualControlPanel(IButton& btn1, IButton& btn2, IButton& btn3, IButton& btn4) :
    button1(btn1), button2(btn2), button3(btn3), button4(btn4)
{}

ManualControlPanel::~ManualControlPanel()
{}

void ManualControlPanel::Setup() {
    button1.SetupIrq();
    button2.SetupIrq();
    button3.SetupIrq();
    button4.SetupIrq();
}

void ManualControlPanel::Loop() {
    button1.HandleIrq();
    button2.HandleIrq();
    button3.HandleIrq();
    button4.HandleIrq();
}
