#include "Button.hpp"

Button::Button(NucleoPin inputPin, std::function<void()> actionShort, std::function<void()> actionLong) :
    btnPin(inputPin), shortPressFunc(actionShort), longPressFunc(actionLong)
{
}

Button::~Button() {
}

void Button::SetupIrq() {
    //TODO
}

void Button::HandleIrq() {
    //TODO
}

void Button::ShortPress() {
    shortPressFunc();
}

void Button::LongPress() {
    longPressFunc();
}
