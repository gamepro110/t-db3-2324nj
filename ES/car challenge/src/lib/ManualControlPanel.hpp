#ifndef LIB_MANUALCONTROLPANEL_HPP_
#define LIB_MANUALCONTROLPANEL_HPP_

#include "Interfaces/IButton.hpp"

class ManualControlPanel {
public:
    ManualControlPanel() = default;
    ManualControlPanel(IButton& btn1, IButton& btn2);
    ~ManualControlPanel();

    ManualControlPanel& operator=(const ManualControlPanel& other);

    bool Setup();
    void Loop();

private:
    IButton* button1{ nullptr };
    IButton* button2{ nullptr };
};

#endif
