## notes

- what is the primary function of the system?
- what are the secondary functions of the system?
- why is this system being built? what is it replacing and why?
- what are the actors in this system?

> construct the use case(s) for the primary function(s), taking into account
> - the role the external objects (actors) and system play in each scenario
> - the interaction (flows) necessary to complete the scenarios in the use case(s)
> - the sequence of events and data to realize the scenario in the use case(s)
> - what variations on the scenario are possible?

## system

---

|               |                                                                                                                                                                                                                                                                                                                                                                                                       |
| ------------- | ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- |
| `name`        | request elevator                                                                                                                                                                                                                                                                                                                                                                                      |
| `summary`     | actor on any floor requests an elevator                                                                                                                                                                                                                                                                                                                                                               |
| `actor`       | user                                                                                                                                                                                                                                                                                                                                                                                                  |
| `assumption`  | no request has been made from that floor in that direction yet, user is outside the elevator                                                                                                                                                                                                                                                                                                                                        |
| `description` | 1) actor presses the button for the direction he wants to go (up or down) </br> 2) the system enables the back-light of the button </br> 3) the system sends an elevator to the requested location{1} </br> 4) the system enables the indicator light when the elevator arrives at the requested floor </br> 5) the system opens the elevator and floor doors, starts the time-out and uses the speaker to notify the actor |
| `exception`   | {1}: no elevators available, the request will be pending until an elevator is send                                                                                                                                                                                                                                                                                                                    |
| `result`      | the actor is able to enter the elevator                                                                                                                                                                                                                                                                                                                                                               | 

---

|               |                                                                                                                                                                                                                                                                                                                                                                               |
| ------------- | ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- |
| `name`        | actor requests to go to a specific floor                                                                                                                                                                                                                                                                                                                                      |
| `summary`     | the actor can move between floors using the elevator                                                                                                                                                                                                                                                                                                                                                                              |
| `actor`       | user                                                                                                                                                                                                                                                                                                                                                                          |
| `assumption`  | actor is inside an elevator and the doors are closed                                                                                                                                                                                                                                                                                                                          |
| `description` | 1) actor presses the button belonging the the desired floor </br> 2) system turns on the pressed buttons back-light </br> 3) the system sends the elevator the the desired floor and keeps the indicator up-to-date </br> 4) when the elevator arrives at the desired location the system opens the doors and notifies using the speaker </br> 5) the actor leaves the elevator |
| `exception`   |                                                                                                                                                                                                                                                                                                                                                                               |
| `result`      | the actor can be on its way                                                                                                                                                                                                                                                                                                                                                   | 

---
