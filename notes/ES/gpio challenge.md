---
tags:
  - ES
  - nucleo
---

# GPIO challenge notes

## class diagram

### polling

```mermaid
classDiagram
direction LR

class Led{
    +Led(GPIO_TypeDef* gpio_block, int pin)
    +~Led()
    +Toggle() void
    +On() void
    +Off() void
    -block GPIO_TypeDef*
    -pin intf
}

class buttonAction {
    <<Enum>>
    None,
    pressShort,
    pressLong,
}

class Button {
    +Button(GPIO_TypeDef* gpio_block, int pin)
    +~Button()
    +GetButtonAction(action buttonAction&)
    -isButtonPressed() void
    -GPIO_TypeDef* block
    -int pin
    -bool logicEntered
    -int startTime
}

class main {
    -int led1Timer
    -int led2Timer
    -const int ledToggleTimeShort
    -const int ledToggleTimeLong
    -buttonAction btn1
    -buttonAction btn2
}

main o-- "2" Button
main o-- "2" Led

```

---

### interrupts

> `std::function` = C++ `std::function<void()>`

```mermaid
classDiagram
direction TD

class Led{
    +Led(GPIO_TypeDef* block, uint8_t pin)
    +~Led()
    +Toggle() void
    +On() void
    +Off() void
    -GPIO_TypeDef* block
    -uint8_t pin
}

class buttonAction {
    <<Enum>>
    None,
    pressShort,
    pressLong,
}

class Button {
    +Button(GPIO_TypeDef* block, uint8_t pin, std::function<void()> shortPress, std::function<void()> longPress)
    +~Button()
    +init() void
    +HandleButtonAction() void
    +HandleIrq() volatile void;
    -GPIO_TypeDef* block
    -uint8_t pin
    -bool triggered volatile 
    -bool logicEntered
    -uint32_t startTime
    -std::function shortPressFunc
    -std::function longPressFunc
}

class main {
    -uint32_t led0Timer
    -uint32_t led1Timer
    -const int ledToggleTimeShort
    -const int ledToggleTimeLong
    -but0ShortPress()
    -but0LongPress()
    -but1ShortPress()
    -but1LongPress()
    -ledBlinkTimed(Led* led, const uint32_t delay, uint32& timer)
    -ledLogic(buttonAction btnAction, led& led, uint32_t& ledTimer, const uint32_t ledToggleTimeShort, const uint32_t ledToggleTimeLong)
}

main --o "2" Button
main --o "2" Led
main --* "2" buttonAction

```

## flowchart

### polling

```mermaid
flowchart TD
subgraph main
    sta([Start])
    sto([Stop])
    init[init]
    loop[[loop]]
    while{while 1}

    sta --> init
    init --> while
    while --true--> loop
    loop --> while
    while --false---> sto
end

%% main end

lStart([loop start])
lEnd([loop end])
poll[[poll button]]
check{button pressed}
ledUp[[led update]]
fhi[freq = hi]
flo[freq = lo]

lStart --> poll
poll --> check
check -- yes --> fhi
check -- no --> flo
fhi --> ledUp
flo --> ledUp
ledUp --> lEnd

%% loop end

lUS[led update start]
lUE[led update end]
swi{switch}
fslow[update led slow]
ffast[update led fast]
none[dont toggle led]

lUS --> swi
swi -- freq = slow--> fslow
swi -- freq = fast--> ffast
swi -- freq = unknown--> none
fslow-->lUE
ffast-->lUE
none-->lUE
lUE

```

### interrupt

```mermaid
flowchart LR
subgraph loop
    lStart([loop start])
    lEnd([loop end])
    buthl[[button HandleButtonAction]]
    ledLogic
    ledBlinkTimed
    
    lStart --> buthl
    buthl --> ledLogic
    ledLogic --> ledBlinkTimed
    ledBlinkTimed --> lEnd
end

subgraph onInterrupt
    inSta([interrupt start])
    pin[reset interrupt flag]
    butIrq[[button handleIrq: set triggerd true]]
    inSto([interrupt stop])
    
    inSta --> pin
    pin --> butIrq
    butIrq --> inSto
end

subgraph HandleButtonAction
    haSta([HandleButtonAction start])
    haSto([HandleButtonAction end])
    trig{triggered?}
    logi{logicEntered?}
    calc[calculate time delta]
    timSta[setTimeStart]
    delta{getTick - startTime}
    funs[shortPressFunc]
    funl[LongPressFunc]
    
    haSta --> trig
    trig -- no --> haSto
    trig -- yes --> logi

    logi -- no --> timSta
    timSta --> haSto
    
    logi -- yes --> calc
    
    calc --> delta
    
    delta -- < 20ms --> haSto
    delta -- < 500ms --> funs
    delta -- > 500ms --> funl
    
    funs --> haSto
    funl --> haSto
end

subgraph main
    start([Start])
    stop([Stop])
    init[[init]]
    loopF[[loop]]
    while{while 1}

    start --> init
    init --> while
    while --true--> loopF
    loopF --> while
    while --false---> stop
end

```