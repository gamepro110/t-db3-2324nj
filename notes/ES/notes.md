---
tags:
  - ES
  - research
  - nucleo
  - snippet
---

# main question

- how do I get the Nucleo car driving and avoiding obstacles using low level hardware control?

## sub questions

- [ ] how do I control the actuators?
  - [x] which actuators? -> parallax inc. feedback 360 servo
    - [ ] how do I control them?
      - [x] input -> [pwm signal](<../../ES/nucleo tests/nucleo-f303re-2x-pwm/src/main.cpp>)
      - [ ] output
- [x] how do I detect obstacles? -> ultra sonic sensor
- [ ] how do I control the ultra sonic sensor?
  - [ ] how does it work?
  - [ ] what inputs does it take?
    - [x] [how do I control the pins on the Nucleo](<./nucleo-notes.md#digital-output>)
    - trigger pin
  - [ ] what outputs does it have?
    - echo pin
- [x] how do interrupts work? -> view `gitroot/ES/nucleo-gpio-interrupt-test`
  - [x] can u call c++ class functions in an `extern "C"` function?
    - [x] expert interview
      - Peter, Richard
        - "I have no idea, but I don't expect it to work."
    - [x] experiment ([godbolt.org](<https://godbolt.org/>))
      - (SEE SNIPPET BELOW)
      - using `x86-64 gcc 8.5` on godbolt.org
      - ![test](<../Assets/godbolt_test.png>)
- [ ] how do timers work?
  - [x] what is a timer?
    - a timer is a register that counts up or down on clock signals from the system clock.
  - [x] how do I configure one? -> [timers](<../ES/nucleo-notes.md#example>)
  - [x] what registers do I need to know? -> [registers](<../ES/nucleo-notes.md#registers>)
  - [x] [how do u calculate the timing?](<./nucleo-notes.md#calculate timer timing>)
- what is a control panel? -> physical user interface (consists of buttons encoders etc. for the user to interact with)

### extern "c" test code

```cpp
#include <iostream>

class Button {
public:
  Button(int pin) :
    pin(pin)
  {}

  void print() {
    std::cout << "pin: " << pin << "\n";
  }

private:
  int pin;
};

Button but{5};

extern "C" void func(void) {
  but.print();
}

int main() {
  func();
  return 0;
}
```
