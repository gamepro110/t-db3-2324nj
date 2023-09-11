---
tags:
  - COMM
  - protocol
---
## investigating protocols
#### lighting in p8

- mcu with touch display connecting to webhooks.

#### counting wildlife

- motion detector
- cam
- Lora 

#### air quality reporting tilburg

- sensor
- mqtt
- influx db (?)

#### measuring glacier size (climate change impact)

- ...?

## protocol notes

### mqtt

- requires a broker
- clients connect to broker
- layout![[mqtt_layout.png]]
- light weight
- bi-directional
- uses tcp
- higher power consumption
- easy to implement
- ! no error handling

### CoAp

- designed for micro controllers
- for resource constrained internet device
- easily translated to `http`
- low overhead and simple
- for `iot` (internet of things) and `m2m` (machine to machine)
- can run on most devices that support `udp`

#### message format

| bit offset from 0 | element size (bits) | description                        |
|:-----------------:|:-------------------:| ---------------------------------- |
|         0         |          2          | version                            |
|         2         |          2          | type #?                            |
|         4         |          4          | token length                       |
|         8         |          8          | request/response code              |
|        16         |         16          | message id                         |
|        32         |         64          | token (0-8 bytes)                  |
|        128        |         32          | options (if available)             |
|        160        |          8          | payload marker (byte full of `1`s) |
|        168        |          *          | payload (if available)             |

>source [wiki](https://en.wikipedia.org/wiki/Constrained_Application_Protocol)
