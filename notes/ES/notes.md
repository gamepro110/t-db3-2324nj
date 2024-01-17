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

- [x] what parts does the car have?
  - [x] [object diagram](<./../../ES/car challenge/class diagram.md#object>)
  - [x] [class diagram](<./../../ES/car challenge/class diagram.md#class>)
- [x] how do i control the actuators?
  - [x] servo
    - [x] pwm
    - [x] pwm + pid
  - [x] distance sensor
    - [x] gpio control
- [x] how do i control the sensors?
  - [x] servo
    - [x] [pwm](<./../../ES/nucleo tests/nucleo-f303re-2x-pwm/>)
  - [x] button
    - [x] [interrupts](<./../../ES/nucleo tests/nucleo-f303re-gpio-challange/>)
  - [x] ultra sonic distance
    - [x] pwm
      - [x] [reading servo pwm](<./../../ES/nucleo tests/nucleo-f303re-pwm-input/>)
- [x] how do i control the car while its running?
  - [x] serial communication
    - sotfware serial
  - [x] mcp (manual control panel)
    - [example](./../../ES/nucleo%20tests/nucleo-f303re-gpio-challange/)
- [x] what is an obstacle?
  - an obstacle is anything the distance sensor can sense within N cm for longer than a few measurements
- [x] how do i communicate between threads while keeping it in real time?
  - [x] [freeRtos](<./../../ES/nucleo tests/nucleo-f303re-freeRtos-test/>)
    - [x] [message queue example](./../../ES/nucleo%20tests/nucleo-f303re-rtos-msgQueue-test/)

## old subquestions

- how do I control the actuators?
  - which actuators? -> parallax inc. feedback 360 servo
    - how do I control them?
      - input -> [pwm signal](<../../ES/nucleo tests/nucleo-f303re-2x-pwm/src/main.cpp>)
      - output
- how do I detect obstacles? -> ultra sonic sensor
- how do I control the ultra sonic sensor?
  - how does it work?
  - what inputs does it take?
    - [how do I control the pins on the Nucleo](<./nucleo-notes.md#digital-output>)
    - trigger pin
  - what outputs does it have?
    - echo pin
- how do interrupts work? -> view `gitroot/ES/nucleo-gpio-interrupt-test`
  - can u call c++ class functions in an `extern "C"` function?
    - expert interview
      - Peter, Richard
        - "I have no idea, but I don't expect it to work."
    - experiment ([godbolt.org](<https://godbolt.org/>))
      - (SEE SNIPPET BELOW)
      - using `x86-64 gcc 8.5` on godbolt.org
      - ![test](<../Assets/godbolt_test.png>)
- how do timers work?
  - what is a timer?
    - a timer is a register that counts up or down on clock signals from the system clock.
  - how do I configure one? -> [timers](<../ES/nucleo-notes.md#example>)
  - what registers do I need to know? -> [registers](<../ES/nucleo-notes.md#registers>)
  - [how do u calculate the timing?](<./nucleo-notes.md#calculate timer timing>)
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
