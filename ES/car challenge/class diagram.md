# diagrams

## object

```mermaid
graph
c([car])
d([distance Sensor])
s1([servo motor 1])
s2([servo motor 2])

c --> d
c --> s1
c --> s2
```

## class

> `<<active>>` has its own thread. `TSQueue` = freeRtos messageQueue

```mermaid
classDiagram
    class CarSystem {
        -osMessageQueueId_t queueId
    }
    class MotorController {
        <<active>>
        +Setup()
        +Loop()
    }
    class IMotor {
        -IsReversed() bool
        +SetSpeed(int8_t value)
    }
    class IButton {
        +SetupIrq()
        +HandleIRQ()
        +shortPress() action
        +LongPress() action
    }

    class ServoMotor {
        -uint16_t idleSpeed
    }
    class Button

    class ManualControlPanel {
        <<active>>
        +Setup()
        +Loop()
    }

    class TSQueue {
        +Read()
        +Write()
    }

    %% *.. == is a
    %% <-- == has a
    %% <|.. == implements interface

    MotorController --> "2" IMotor

    ManualControlPanel --> "2" IButton

    IMotor <|.. ServoMotor
    IButton <|.. Button

    CarSystem --> ManualControlPanel

    TSQueue <-- ManualControlPanel
    TSQueue <-- MotorController

    %%CarSystem --> TSQueue
    CarSystem --> MotorController
```

## todo

- add distance sensor to graph

### notes

- IMotor::SetSpeed argument range: `0` - ±`100`
- `action` => `std::function<void()>`
