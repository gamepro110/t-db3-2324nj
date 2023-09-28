---
tags:
  - COMM
  - protocols
  - research
---
## step 1 (investigating protocols)

#### lighting in p8

- micro controller with touch display connecting to web-hooks.

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
- ![mqtt_Layout](mqtt_layout.png)
- light weight
- bi-directional
- uses tcp
- higher power consumption
- easy to implement
- ! no error handling
- subscriber based setup

### CoAP

- designed for micro controllers
- for resource constrained internet device
- easily translated to `http`
- low overhead and simple
- for `iot` (internet of things) and `m2m` (machine to machine)
- can run on most devices that support `udp`
- restful API

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

## step 2 (imagining the usage of mqtt or CoAP)

- smart home
	- context
		- someone wants to make his home 'smart'. for example: only turn on the lights if someone is in that room, turn on the floor heating in a room when someone is there, open and close doors using a servo and a distance sensor, logging activities, etc.
		- the systems want to be notified of changes, like a person changing rooms.
		- the smart home system is made from multiple smaller systems
	- advice
		- mqtt
	- reason
		- mqtt works on a subscriber based system, meaning that once something changes everything listening to that 'channel' gets notified and can act accordingly.
- factory line control panel
	- context
		- a factory consisting of modules. each module has a status and has to communicate with other modules about their input/output. the system has to run continuously and be able to accept recipe changes.
	- advice
		- mqtt
	- reason
		- due to the system having to communicate based on changes in the modules state i would recommend mqtt over CoAP, as CoAP acts more like a restful API. having to request each time u need to check multiple modules is inefficient, when u can have a central place that notifies the module on changes.
		- when using CoAP u would need to continuously request information, because the moment u receive your request it can be made invalid by the module u requested it from.
- machine to machine
	- context
		- ![CoAP-setup-example](CoAP_setup.jpg)
		- 
	- advice
		- CoAP
	- reason
	- [source](https://www.hivemq.com/article/mqtt-vs-coap-for-iot/)

### bonus (Lora)

- bat box presence detection system
	- context
		- it is legally required for cities to keep track of the number of bat boxes in use. if u place a heat sensor inside a bat box and are able to request the temperature to see if it is in use, would save a lot of volunteers about 2 hours a day. since they currently have to manually check with a flashlight if bats are using a curtain bat box. as the bat boxes are located in odd and often even remote locations (like a forest, or in the walls of a church) they need to be battery powered and last a long time because how wants to replace batteries every week.
	- advice
		- lora
	- reason
		- the environment is very challenging and the resources are constrained, meaning we cant have it polling for events all the time.
		- power availability is not guaranteed, hence the battery. meaning low power consumption is a must.
		- Lora can be used to connect to the internet and send the data

## sources

- Wikipedia
	- [mqtt](https://en.wikipedia.org/wiki/MQTT)
	- [CoAP](https://en.wikipedia.org/wiki/Constrained_Application_Protocol)