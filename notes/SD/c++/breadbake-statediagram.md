# breadbake state diagram

```mermaid
stateDiagram-v2
    direction LR

    state "standby" as s
    state "processing" as p
    state "baking" as b
    state "raising" as r
    state "kneading" as k
    state "increasing timer" as timu
    state "decreasing timer" as timd
    state "increasing temperature" as temu
    state "decreasing temperature" as temd

    timu: entry / increase timer
    timd: entry / decrease timer

    temu: entry / increase temperature
    temd: entry / decrease temperature

    r: entry / heater.TurnOn()
    r: exit / heater.TurnOff()

    b: exit / heater.TurnOff()

    k: entry / kneader.TurnOn()
    k: exit / kneader.TurnOff()

    [*] --> s
    s --> timu : TIMER_UP_BUTTON_PRESSED [running == false] / STATE=STANDBY
    timu --> s

    s --> timd : TIMER_DOWN_BUTTON_PRESSED [running == false] / STATE=STANDBY
    timd --> s

    s --> temu : TEMP_UP_BUTTON_PRESSED [running == false] / STATE=STANDBY
    temu --> s

    s --> temd : TEMP_DOWN_BUTTON_PRESSED [running == false] / STATE=STANDBY
    temd --> s

    s --> p : START_BUTTON_PRESSED / SetTime(), TurnOn()
    state p {
        direction LR
        [*] --> k
        k --> r : KNEADING_TIME_1_DONE [kneadingTimer1 == 0]
        r --> k : RAISING_DONE [raisingTimer == 0]
        k --> b : KNEADING_TIME_2_DONE [kneadingTimer2 == 0]
        b --> [*] : OVEN_DONE [ovenTimer == 0]
    }
    p --> s : OVEN_DONE / TurnOff()
```
