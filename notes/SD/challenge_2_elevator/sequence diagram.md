---
tags:
  - SD
  - diagrams
  - todo
---

# sequence diagram

> title: user requests elevator

```mermaid
sequenceDiagram

%%TODO fix order when done
actor U as user
participant B as Button_up 
participant S as system
participant E as Elevator
participant L as Light
participant F as Floor
participant Df as FloorDoor
participant De as ElevatorDoor
participant If as Floor Indicator
participant Ie as Elevator Indicator
participant SP as Speaker
participant T as TensionSensor

%% ----------------------------------------

%% start user interaction
U ->> B: user presses a button
B -) S: ButtonPressInterrupt
B -) L : Light.On()
S -) If : floorIndicator.Show()
S ->>+ S : addElevatorRequest()

loop in "addElevatorRequest()"
    S ->> E : IElevator elevator.isAvailable(targetFloor)
    
    alt false
        E -->> S : "try next elevator"
    else true
        E -->> S : true
        S -) E : SetTargetFloor()
    end
end

S ->>+ E : IElevator.Update()
E ->>+ T : IsLimitExceded()
    alt True
        T -->> E : emergency stop
        E -->> S : Notify system
    else False
        T -->>- E : 
    end

E ->>+ Ie : GetCurrentFloor() //validate
Ie -->>- E : value
    alt elevator.GetCurrentFloor() != value
        E -) Ie : SetCurrentFloor()
        E -) If : SetCurrentFloor()
    end

%% elevator reaches target
alt GetCurrentFloor == GetTargetFloor
E ->> E : targetFloors.PopFront
E -) SP : Play()
E -) De : Open()
E -->>+ S : notify arival
S ->> Df : Open()
S -->- E : 
end

%% start door timer

%% close door at end of timer

%% empty on purpose
E -->>- S : 

%%S -->>- S : 
```

> `Button_up` can also be `button_down`

### todo

- [ ] validate `GetCurrentFloor()`
- [ ]  start door timer
- [ ] close door at end of timer

### assumptions

- elevators are on random floors
- all elevators are empty
