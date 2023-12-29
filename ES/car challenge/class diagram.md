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
b3([button 3])
b4([button 4])

c ---> d

c ---> b1
c ---> b2
c ---> b3
c ---> b4

c --> s1
s1 --> ss1
s1 --> sm1

c --> s2
s2 --> ss2
s2 --> sm2
```

| component | amount | input | output |
| :---: | :---: | :---: | :---: |
| servo | 2 | pwm in (50hz) | 1: motor movement, 2: pwm out (910hz) |
| distance FeedbackSensor | 1 | pin trigger pulse | pwm timing |
| button | 4 | physical interaction | interrupt |
<!-- |  |  |  | -->

## class

> `<<active>>` has its own thread. `TSQueue` = freeRtos messageQueue

```mermaid
classDiagram
    class TSQueue {
        +Read()
        +Write()
    }
    class CarSystem {
        <<active>>
        -osMessageQueueId_t queueId
    }
    class MotorController {
        <<active>>
        -osMessageQueueId_t queueId
        +Setup()
        +Loop()
    }
    class IMotor {
        -IsReversed() bool
        +SetSpeed(int8_t value)
    }
    class ServoMotor {
        -NucleoPin motorInputPin
    }
    class ManualControlPanel {
        <<active>>
        -osMessageQueueId_t queueId
        -IButton but1
        -IButton but2
        -IButton but3
        -IButton but4
        +Setup()
        +Loop()
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
        -NucleoPin btnPin
    }
    class IDistanceSensor {
        +GetDistance() float
    }
    class HC_SR04_DistSensor {
        +HC_SR04_DistSensor( NucleoPin echo, NucleoPin trigger)
        -NucleoPin echoPin
        -NucleoPin triggerPin
    }
    class Pid {
        -int kp
        -int ki
        -int kd
    }
    class IFeedbackSensor {
        +GetSpeed() float
    }
    class FeedbackSensor {
        +FeedbackSensor(NucleoPin inputSignal)
        -NucleoPin InputSignalPin
    }
    class PinMode {
        <<enum>>
        digital_input
        digital_input_pullup
        digital_output
        altMode
    }
    class NucleoPin {
        -GpioTypedef block
        -uint8_t pin
        -PinMode mode
        +NucleoPin(GpioTypedef* block, uint8_t pinNr, PinMode mode)
        +SetAltMode(unit8_t mode)
        +Setup() bool
        +Write()
        +Read() bool
    }

    %% *.. == is a
    %% <-- == has a
    %% <|.. == implements interface

    TSQueue -- ManualControlPanel
    TSQueue -- MotorController
    CarSystem o-- ManualControlPanel
    ManualControlPanel o-- "2" IButton
    IBtnIRQ <-- IButton
    IButton <|.. Button

    MotorController o-- "2" IMotor
    MotorController o-- "2" IFeedbackSensor
    MotorController o-- "2" Pid

    IMotor <|.. ServoMotor

    CarSystem --> MotorController

    CarSystem o-- IDistanceSensor
    IDistanceSensor <|.. HC_SR04_DistSensor

    IFeedbackSensor <|.. FeedbackSensor

    HC_SR04_DistSensor o-- NucleoPin
    FeedbackSensor o-- NucleoPin
    ServoMotor o-- NucleoPin
    Button o-- NucleoPin
    NucleoPin o-- PinMode
```

### TODO

- why does motorController have 2 instances of the interfaces??
- add `HardwareTimer` to diagram
- add `update()` to `CarSystem`
- add `Logger` class

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
