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
| distance FeedbackSensor | 1 | pin trigger pulse | ? |
| button | 4 | physical interaction | interrupt |
<!-- |  |  |  | -->

## class

> `<<active>>` has its own thread. `TSQueue` = freeRtos messageQueue

```mermaid
classDiagram
    class CarSystem {
        -osMessageQueueId_t queueId
    }
    class TSQueue {
        +Read()
        +Write()
    }
    class MotorController {
        <<active>>
        -osMessageQueueId_t queueId
        -wheelLeft : IMotor
        -wheelRight : IMotor
        -fbLeft : IFeedbackSensor
        -fbRight : IFeedbackSensor 
        +Setup()
        +Loop()
    }
    class IMotor {
        -IsReversed() bool
        +SetSpeed(int8_t value)
    }
    class ServoMotor {
    }
    class ManualControlPanel {
        <<active>>
        -osMessageQueueId_t queueId
        +Setup()
        +Loop()
    }
    class IButton {
        +SetupIrq()
        +HandleIRQ()
        +shortPress() action
        +LongPress() action
    }
    class Button
    class IDistanceSensor {
        GetDistance() float
    }
    class HC_SR04_DistSensor {
    }
    class Pid
    class IFeedbackSensor {
        GetSpeed() float
    }

    %% *.. == is a
    %% <-- == has a
    %% <|.. == implements interface

    TSQueue <-- ManualControlPanel
    TSQueue <-- MotorController
    CarSystem --> ManualControlPanel
    ManualControlPanel --> "2" IButton
    IButton <|.. Button

    MotorController --> "2" IMotor
    MotorController --> "2" IFeedbackSensor
    MotorController --> "2" Pid

    IMotor <|.. ServoMotor

    CarSystem --> MotorController

    CarSystem --> IDistanceSensor
    IDistanceSensor <|.. HC_SR04_DistSensor

    IFeedbackSensor <|.. FeedbackSensor
```

### TODO

- change some `has a` arrows to `aggragation` arrows

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
