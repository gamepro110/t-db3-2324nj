#ifndef LIB_MANUALCONTROLPANEL_HPP_
#define LIB_MANUALCONTROLPANEL_HPP_

#include "Interfaces/IButton.hpp"

class ManualControlPanel {
public:
    ManualControlPanel(IButton& btn1, IButton& btn2);
    ~ManualControlPanel();

    bool Setup();
    void Loop();

private:
    IButton& button1;
    IButton& button2;
};

#endif
