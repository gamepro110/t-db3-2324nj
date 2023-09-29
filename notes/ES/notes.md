---
tags: 
  - ES 
  - research
  - nucleo
  - snippet
---

# main question

- how do i get the nucleo car driving and avoiding obstacles using low level hardware control?

## sub question

- how do i control the actuators?
	- which actuators?
- how do i detect obstacles? -> ultra sonic sensor
- how do i control the ultra sonic sensor?
	- how does it work?
	- what inputs does it take?
		- how do i control the pins on the nucleo
	- what outputs does it have?
- how do interrupts work?
	- can u call c++ class functions in an `extern "C"` function?
		- expert interview
			- Peter, Richard
				- "i have no idea, but i don't expect it to work."
		- experiment ([godbolt.org](https://godbolt.org/))
			-  (SEE SNIPPET BELOW)
			- using `x86-64 gcc 8.5` on godbolt.org
			- ![test](godbolt_test.png)
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