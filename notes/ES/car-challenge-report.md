# car challenge report

2024-01-17
Karlo Koelewijn

## history

| date | version | author | notes |
| :---: | :---: | :---: | --- |
| 2024-01-17 | 0.1 | Karlo | added layout + started research |
| 2024-01-20 | 0.2 | Karlo | fleshed out the subquestions, added class diagram, added todo list |
<!-- |  |  |  |  | -->

## content

- [car challenge report](#car-challenge-report)
  - [history](#history)
  - [content](#content)
  - [introduction](#introduction)
  - [research](#research)
    - [main question](#main-question)
    - [subquestions](#subquestions)
      - [what parts does the car have?](#what-parts-does-the-car-have)
      - [how do i control the actuators? / how do i control the sensors?](#how-do-i-control-the-actuators--how-do-i-control-the-sensors)
      - [how do i control the car while its running?](#how-do-i-control-the-car-while-its-running)
      - [what is an obstacle?](#what-is-an-obstacle)
      - [how do i communicate between threads while keeping it in real time?](#how-do-i-communicate-between-threads-while-keeping-it-in-real-time)
    - [deepdive](#deepdive)
  - [design](#design)
    - [class diagram](#class-diagram)
  - [advice](#advice)
  - [conclusion](#conclusion)
  - [TODO](#todo)

## introduction

## research

### main question

how do I get the Nucleo car driving and avoiding obstacles using low level hardware control in real-time?

### subquestions

#### what parts does the car have?

![robohub](<./../Assets/robohub.jpg>)
*robohub*

```mermaid
%%{init: {'flowchart' : {'curve' : 'linear'}}}%%
graph
  c([car])
  d([distance Sensor])
  s1([servo 1])
  ss1([servo 1 FeedbackSensor])
  sm1([servo 1 motor])
  s2([servo 2])
  ss2([servo 2 FeedbackSensor])
  sm2([servo 2 motor])
  b1([button 1])
  b2([button 2])

  c ---> d
  c ---> b1
  c ---> b2
  c --> s1
  s1 --> ss1
  s1 --> sm1
  c --> s2
  s2 --> ss2
  s2 --> sm2
```

#### how do i control the actuators? / how do i control the sensors?

the servos used are the `parallax inc. feedback 360 highspeed`, which are controlled using a 100 KHz pwm signal.  
by using the ccr (Capture Compare registers) you are able to manipulate the width of the duty cycle of the pwm signal.  
the servo responds to a signal between 1280 and 1720, which are the values that we put into the ccr.  
to controll them in a closed loop you can either:

1) choose to read the 910 hz pwm output signal, or
2) use a distance sensor

either option could be used as part of the pid controller.

as for controlling the distance sensor, this can be controlled using pwm pulse mode.  
that means u only send a pulse at the begining of the pwm signal on the trigger pin and read the resulting pwm signal from the echo pin.  
then after a calculation you get the distance from an obstacle.

the buttons on the other hand use interrupts, so when the button is pressed an interrupt is triggerd in the cpu.  
the cpu then executes its interupt handler (corosponding to the correct interrupt) and after which return to where it was before.  
it is essential that interrupts are short as to not loose track of other time sensitive tasks/threads.  
to keep mine short i only set a bool to true and save how long it has been pressed for on letting the button go.  
after which it can handle the button press whenever it has 'time' outside of the interrupt.

#### how do i control the car while its running?

while the assignment said that we needed to make our own software-serial, because the nucleo did not have enough pin,
i was able to allocate all the pins without needing to use the software-serial i had writen.  
i did use serial to set the individual Kp, Ki, and Kd values while the car was running so i did not have to recompile every time i had to change a value.  
another method to control the car was by adding a MCP (Manual Control Panel), for that i added 2 buttons where each button had a short and a long press action.  
they utilize a combination of interrupts and a messageQueue to decide what action gets executed.

#### what is an obstacle?

an obstacle is anything the distance sensor can sense within N cm for longer than a few measurements

#### how do i communicate between threads while keeping it in real time?

the nucleo f303re has a single ARM Cortex M4 core, so if we want to use multiple threads we are going to need an os.
thats where FreeRtos steps in, FreeRtos (or Free Real time operating system) provides a cross-platfrom operating system with threading capabilities.
which allowes us too make multiple threads while the kernal keeps the system running at 'real-time'.

to communicate between threads we can use one of freeRtos' features called a messageQueue,
you are able to push messages to the queue from one thread while another thread is able to pop them while the kernal keeps everything running.

### deepdive

## design

<!-- TODO finish design-->
<!-- TODO explain design choices (for example: why motorcontroller takes 2 motors)-->

### class diagram

`<<active>>` means that it has a separate thread.  
`Action` = std::function\<void()\> or void(*func)(void) depending on the memory impact.  
the rule of 3 applies to classes (ctor, dtor, asignment-operator).  
IMotor::SetSpeed argument range: `-100` to `100`.

```mermaid
classDiagram
  class CarSystem {
    <<active>>
    +CarSystem(osMessageQueueId_t id, IDistanceSensor& sensor, ManualControlPanel& MCP, MotorController& controller)
    +Setup() bool
    +Update()
    -osMessageQueueId_t queueId //distance queueId
    -SensorMsgData data
  }
  class MotorController {
    <<active>>
    +MotorController(osMessageQueueId_t id, uint8_t minDist, IMotor& leftMotor, IMotor& rightMotor, IFeedbackSensor& leftSense, IFeedbackSensor& rightSense)
    +Setup()
    +Loop()
    +SetSpeed(uint16_t speed)
    +SetDistance(uint8_t distance)
    -osMessageQueueId_t queueId
    -uint8_t minDetectDistance
    -IMotor* motorLeft
    -IMotor* motorRight
    -IFeedbackSensor* senseLeft
    -IFeedbackSensor* senseRight
    -Pid pid
  }
  class IMotor {
    +Setup() bool
    +IsReversed() bool
    +SetSpeed(int8_t value)
  }
  class ServoMotor {
    +ServoMotor(NucleoPin pinMotor, HardwareTimer& timer, uint8_t ccChannelNum, bool reversed)
    -NucleoPin motorInputPin
    -HardwareTimer tim
    -bool isReversed
    -uint8_t ccrChannel
    -uint8_t maxSetSpeed = 100
    -uint8_t servoIdleValue = 1500
  }
  class ManualControlPanel {
    <<active>>
    +ManualControlPanel(osMessageQueueId_t btnId, IButton& btn0, IButton& btn1)
    +Setup()
    +Loop()
    +SetPid(Pid& p)
    -HandleSelectedBtn(BtnMsgData data)
    -CallBtnAction(BtnMsgData data, IButton btn)
    -osMessageQueueId_t queueId
    -IButton but1
    -IButton but2
    -Pid* pid
  }
  class IBtnIRQ {
    +HandleIRQ()
    +SetupIrq()
  }
  class IButton {
    +shortPress() action
    +LongPress() action
  }
  class Button {
    +Button(NucleoPin inputPin, IRQn_Type irq, osMessageQueueId_t id, Action actionShort, Action actionLong)
    -NucleoPin btnPin
    -osMessageQueueId_t id
    -IRQn_Type irq
    -volatile bool triggered
    -volatile uint32_t startTime
    -volatile BtnMsgData data
    -Action shortPressCallback
    -Action longPressCallback
  }
  class IDistanceSensor {
    +GetDistance() uint8_t
  }
  class HC_SR04_DistSensor {
    +HC_SR04_DistSensor(NucleoPin& echo, NucleoPin& trigger, HardwareTimer tim)
    +Setup(uint32_t prescaler, uint32_t arrValue, uint32_t outputCCValue, const uint8_t outputChannel, const uint8_t inputChannel1, const uint8_t intputChannel2) bool
    -NucleoPin* echoPin
    -NucleoPin* triggerPin
    -HardwareTimer timer
  }
  class Pid {
    +PID(int16_t min, int16_t max, float kp = 8.1f, float ki = 10.71428571f, float kd = 1.5309f)
    +Calculate(float target, float lastTarget) int16_t
    +ResetValues() void
    +updateKP(float val) void
    +updateKI(float val) void
    +updateKD(float val) void
    +GetKP() float
    +GetKI() float
    +GetKD() float
    -int16_t min
    -int16_t max
    -float tau
    -int16_t error
    -int16_t prevError
    -int16_t prevMeasurement
    -float timeSec
    -float proportionalOut
    -float integratorOut
    -float differentiatorOut
    -float output
    -float kp
    -float ki
    -float kd
    -float defaultKp
    -float defaultKi
    -float defaultKd
  }
  class IFeedbackSensor {
    +Setup() bool
    +Update()
    +GetSpeed() float
  }
  class FeedbackSensor {
    +FeedbackSensor(NucleoPin& inputSignal, HardwareTimer timer)
    -CalcDeg(int32_t curDuty) int32_t
    -CalcRpm(float delta, int32_t time) float
    -NucleoPin InputSignalPin
    -float speed
    -float delta
    -uint32_t curTime
    -uint32_t curDuty
    -uint32_t angleCur
    -uint32_t angleLast
  }
  class PinMode {
    <<enum>>
    digital_input
    digital_input_pullup
    digital_output
    altMode
  }
  class NucleoPin {
    +NucleoPin(GpioTypedef* block, uint8_t pinNr, PinMode mode)
    +NucleoPin(GPIO_TypeDef* block, uint8_t pinNr, AltModeValue val)
    +SetAltMode(AltModeValue value)
    +Setup() bool
    +Write()
    +Read() bool
    +GetPinNr() uint8_t
    +GetPinBlock() GPIO_TypeDef*
    -GpioTypedef block
    -uint8_t pin
    -PinMode mode
  }
  class AltModeValue {
    uint64_t value;
    uint32_t low;
    uint32_t high;
  }
  class HardwareTimer {
    +HardwareTimer(TIM_TypeDef* timer);
    +Init(uint32_t prescaler, uint32_t arrValue, uint32_t outputCCValue, const uint8_t outputChannel, const uint8_t inputChannel1, const uint8_t intputChannel2) bool
    +SetTimerEnable() void
    +SetPrescaler(const uint8_t prescalerDivider) void
    +SetEnablePeripheralClock() void
    +SetEnableCCModex(const uint8_t channel, const uint8_t ccxs, const uint8_t ocxm) void
    +SetEnableCCx(const uint8_t channel, const uint8_t ccxe, const uint8_t ccxp, const uint8_t ccxnp) void
    +SetCCRxRegister(const uint32_t CCRvalue, const uint8_t registerNo) void
    +SetAutoReload(const uint32_t ARRvalue) void
    +SetSlaveModeResetFP1() void
    +GetCaptureCompareRegister1() uint32_t
    +GetCaptureCompareRegister2() uint32_t
    +GetCaptureCompareRegister3() uint32_t
    +GetCaptureCompareRegister4() uint32_t
    +GetTimerCount() uint32_t
    -TIM_TypeDef* timer;
  }
  class BtnMsgData {
    +int butNr
    +int duration
  }
  class SensorMsgData {
    +uint8_t distance
  }

  CarSystem o-- MotorController
  NucleoPin o-- AltModeValue
  CarSystem o-- ManualControlPanel
  ManualControlPanel o-- "2" IButton
  IBtnIRQ <-- IButton
  IButton <|.. Button
  CarSystem o-- SensorMsgData
  MotorController o-- "2" IMotor
  MotorController o-- "2" IFeedbackSensor
  MotorController o-- Pid
  MotorController o-- SensorMsgData
  IMotor <|.. ServoMotor
  CarSystem o-- IDistanceSensor
  IDistanceSensor <|.. HC_SR04_DistSensor
  IFeedbackSensor <|.. FeedbackSensor
  HC_SR04_DistSensor o-- NucleoPin
  FeedbackSensor o-- NucleoPin
  ServoMotor o-- NucleoPin
  Button o-- NucleoPin
  NucleoPin o-- PinMode
  FeedbackSensor o-- HardwareTimer
  HC_SR04_DistSensor o-- HardwareTimer
  ServoMotor o-- HardwareTimer
```

## advice

<!-- TODO -->

## conclusion

<!-- TODOf -->

## TODO

- intro
- finish research
- add subjects to deepdive
  - peek into [nucleo-notes](<nucleo-notes.md>)
- continue design
- advice
- conclusion
