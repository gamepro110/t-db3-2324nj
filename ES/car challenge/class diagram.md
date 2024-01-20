# diagrams

## object

```mermaid
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

## pinout

check [pinout table](pinout.md#pins)

## class

> `<<active>>` has its own thread.  
> `Action` = std::function\<void()\> or void(*func)(void) depending on the memory impact  
> the rule of 3 applies to classes (ctor, dtor, asignment-operator)

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

    %% *.. == is a
    %% o-- == has a
    %% <|.. == implements interface

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

### notes

- IMotor::SetSpeed argument range: `0` - ±`100`
- `action` => `std::function<void()>`

## servo design posibilities

- todo
  - compare with S.O.L.I.D.
    - S - single responsability
    - O - open closed
    - L - liskov substitution
    - I - interface segregation
    - D - dependency inversion

### design 1

> my choice

```mermaid
classDiagram
class motorController
class IMotor
class IFeedbackSensor
class PID
class motor

motorController --> IMotor
motorController --> IFeedbackSensor
motorController --> PID

IMotor <|.. motor
IFeedbackSensor <|.. FeedbackSensor
```

pros

- lower nesting level
- easier overview

cons

- motorcontroller can be seen to have multiple responsabilities
  - required(?) for a closed loop system

---

### design 2

```mermaid
classDiagram
class motorController
class servo
class IMotor
class IFeedbackSensor
class PID

motorController --> servo
servo --> IMotor
servo --> IFeedbackSensor
servo --> PID

IMotor <|.. motor
IFeedbackSensor <|.. FeedbackSensor
```

pros

- can simplifies control

cons

- can obfuscate parts
- does not adhere to Solid L
- unnecasary class inserted

---

### design 3

```mermaid
classDiagram
class motorController
class IServo
class Servo
class IMotor
class IFeedbackSensor
class PID

motorController --> PID
motorController --> IServo

IServo --|> IMotor
IServo --|> IFeedbackSensor
IServo <|.. Servo

%%IMotor <|.. motor
%%IFeedbackSensor <|.. FeedbackSensor

```

pros

- ...

cons

- tightly coupled low level
- seperation of conserns
- merges 2 interfaces
- hard to extend (solid O)

---
