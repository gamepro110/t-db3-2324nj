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
  - [ ] which actuators?
- [ ] how do I detect obstacles? -> ultra sonic sensor
- [ ] how do I control the ultra sonic sensor?
  - [ ] how does it work?
  - [ ] what inputs does it take?
    - [ ] how do I control the pins on the Nucleo
  - [ ] what outputs does it have?
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
  - [ ] what is a timer?
  - [x] how do I configure one? -> [timers](<../ES/nucleo-notes.md#example>)
  - [x] what registers do I need to know? -> [registers](<../ES/nucleo-notes.md#registers>)
  - [ ] how do u calculate the timing?
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
