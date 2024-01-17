# car challenge report

2024-01-17
Karlo Koelewijn

## history

| date | version | author | notes |
| :---: | :---: | :---: | --- |
| 2024-01-17 | 0.1 | Karlo | added layout + started research |
<!-- |  |  |  |  | -->

## content

- [car challenge report](#car-challenge-report)
  - [history](#history)
  - [content](#content)
  - [introduction](#introduction)
  - [research](#research)
    - [main question](#main-question)
    - [subquestions](#subquestions)
  - [design](#design)
  - [advice](#advice)
  - [conclusion](#conclusion)

## introduction

## research

### main question

> how do I get the Nucleo car driving and avoiding obstacles using low level hardware control?

### subquestions

- [x] what parts does the car have?
  - [x] [object diagram](<./../../ES/car challenge/class diagram.md#object>)
  - [x] [class diagram](<./../../ES/car challenge/class diagram.md#class>)
- [x] how do i control the actuators?
  - [x] servo
    - [x] pwm
    - [x] pwm + pid
  - [x] distance sensor
    - [x] gpio control
- [x] how do i control the sensors?
  - [x] servo
    - [x] [pwm](<./../../ES/nucleo tests/nucleo-f303re-2x-pwm/>)
  - [x] button
    - [x] [interrupts](<./../../ES/nucleo tests/nucleo-f303re-gpio-challange/>)
  - [x] ultra sonic distance
    - [x] pwm
      - [x] [reading servo pwm](<./../../ES/nucleo tests/nucleo-f303re-pwm-input/>)
- [x] how do i control the car while its running?
  - [x] serial communication
    - sotfware serial
  - [x] mcp (manual control panel)
    - [example](./../../ES/nucleo%20tests/nucleo-f303re-gpio-challange/)
- [x] what is an obstacle?
  - an obstacle is anything the distance sensor can sense within N cm for longer than a few measurements
- [x] how do i communicate between threads while keeping it in real time?
  - [x] [freeRtos](<./../../ES/nucleo tests/nucleo-f303re-freeRtos-test/>)
    - [x] [message queue example](./../../ES/nucleo%20tests/nucleo-f303re-rtos-msgQueue-test/)

## design

## advice

## conclusion
