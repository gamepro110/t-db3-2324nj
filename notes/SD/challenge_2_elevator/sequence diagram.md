---
tags:
  - SD
  - diagrams
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
participant L as ButtonBackLight
participant F as Floor
participant Df as FloorDoor
participant De as ElevatorDoor
participant If as Floor Indicator
participant Ie as Elevator Indicator
participant SP as Speaker
participant P as PreasureSensor
participant Bb as BreakBeamSensor

%% ----------------------------------------

%% start user interaction
U ->> B: user presses a button
B -) S: ButtonPressInterrupt
activate S
B -) L : Light.On()
S -) If : floorIndicator.Show()
S ->> S : addElevatorRequest()


S ->> E : isAvailable(targetFloor)
%% empty on purpose
E -->> S : 
S -) E : SetTargetFloor()
S ->>+ E : Update()

E ->>+ Ie : UpdateFloor()
%% empty on purpose
Ie -->>- E : 

%% elevator reaches target
%%E ->> E : floorReached()
note over E : elevator reached target floor
E -) SP : Play()
E -) De : Open()
E ->>+ F : OpenDoor(floor)
F -) Df : Open()
F -->>- E : 

%% empty on purpose
E -->>- S : 

%% start door timer
S -)+ P : TimerStart()
S -)+ Bb : TimerStart()

%% close door at end of timer
note over S : user enters elevator and timer ends
P -)- S : 
Bb -)- S : 
S -) E : CloseDoor()
S -) F : CloseDoor()
deactivate S

```

> `Button_up` can also be `button_down`

## assumptions

- elevators are on random floors
- all elevators are empty
