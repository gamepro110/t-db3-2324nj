# Communication protocol assignment

![titleImg1](<../Assets/CoAP_setup.jpg>)

[Fig. 1][coap_layout]

2023-10-27
Karlo Koelewijn

## Content

- [Communication protocol assignment](#communication-protocol-assignment)
  - [Content](#content)
  - [Introduction](#introduction)
  - [analysis](#analysis)
    - [MQTT](#mqtt)
      - [MQTT protocol](#mqtt-protocol)
      - [MQTT requirements](#mqtt-requirements)
      - [MQTT constriants/limitations](#mqtt-constriantslimitations)
      - [MQTT Diagram](#mqtt-diagram)
    - [CoAp](#coap)
      - [CoAp protocols](#coap-protocols)
      - [CoAp requirements](#coap-requirements)
      - [CoAp constraints/limitations](#coap-constraintslimitations)
      - [CoAp Diagram](#coap-diagram)
  - [discussion](#discussion)
    - [differences](#differences)
    - [comparisons](#comparisons)
  - [conclusion](#conclusion)
  - [references](#references)

## Introduction

To determine the differences between 2 communication protocols, MQTT and CoAp. we look at both protocols, determine their pros and cons, and discus a few use cases for each application.</br>
This time its between 2 protocols, but by doing this we learn how to objectively look at concepts and determine how they can be used, what they can be used for and how to compare different concepts.

## analysis

I went through the following steps to learn about each protocol.

1. look up the protocols
2. look at the requirements
3. look at the constraints/limitations

### MQTT

#### MQTT protocol

- light weight
- uses tcp

#### MQTT requirements

- requires a broker
- clients connect to broker

#### MQTT constriants/limitations

- higher power consumption
- easy to implement
- subscriber based setup

#### MQTT Diagram

- client 1 -> mcu diaplaying info
- client 2 -> server logging data
- client 3 -> mcu measuring data

```mermaid
sequenceDiagram
participant b as MQTT broker
participant a1 as MQTT client 1
participant a2 as MQTT client 2
participant a3 as MQTT client 3

note over a1,b : client 1 connects and subscribes
  a1 -) b : connect
  b -->> a1 : ack
  a1 -->> b : subscribe topic "temp-room-1"

note over a2,b : client 2 connects and subscribes
  a2 -) b : connect
  b -->> a2 : ack
  a2 -->> b : subscribe topic "temp-room-1"

note over a3,b : client 3 connects and subscribes
  a3 -) b : connect
  b -->> a3 : ack

note over a3,b : mcu publishes data to the topic
a3 ->>+ b : publish data {"topic":"temp-room-1","message":"22c"}
b --) a1 : {"topic":"temp-room-1","message":"22c"}
b --) a2 : {"topic":"temp-room-1","message":"22c"}
deactivate b
%%b
```

### CoAp

#### CoAp protocols

- designed for
  - micro controllers
  - resource constrained internet device
- protocol easily translates to http

#### CoAp requirements

- Application layer protocol

#### CoAp constraints/limitations

- low overhead and simple
- for IOT (internet of things) and M2M (machine to machine)
- can run on most devices that support udp
- restful API

#### CoAp Diagram

![CoAp diagram](../Assets/CoAP_setup.jpg)

[Fig. 1][coap_layout]

possible setups

- m2m (machine to machine)
- machine to server
- client to server
- client to proxy to server

## discussion

There are a few comparisons to be found, but naturally also some differences, lets point them out.

### differences

- MQTT requires a broker while CoAp does not
- MQTT uses the subscriber modal while CoAp acts like a RESTful api
- MQTT requires more power
- MQTT needs 'ordered lossless, bidirectional' communication while CoAp can run on most devices that support the udp standard

### comparisons

- both can
  - do M2M (machine to machine)
  - use multiple transport protocol
    - MQTT
      - tcp
      - QUIC
    - CoAp
      - udp
      - SMS
      - cellular
- both don't mention error correction

## conclusion

<<>>

## references

[coap_layout]: <https://www.mdpi.com/1424-8220/20/21/6391>
[wiki_coap]: <https://en.wikipedia.org/wiki/Constrained_Application_Protocol>
[wiki_mqtt]: <https://en.wikipedia.org/wiki/MQTT>

- [mqtt information source][wiki_mqtt]
  - raw link: <https://en.wikipedia.org/wiki/MQTT>
- [coap information source][wiki_coap]
  - raw link: <https://en.wikipedia.org/wiki/Constrained_Application_Protocol>
- Fig. 1: [source][coap_layout]
  - raw link: <https://www.mdpi.com/1424-8220/20/21/6391>
