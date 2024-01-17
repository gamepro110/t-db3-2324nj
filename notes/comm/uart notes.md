---
tags:
  - uart
  - COMM
---

# uart notes

## usefull links

| reason | url |
|---|---|
| configure minicom | <https://www.css-techhelp.com/post/configure-minicom-for-a-usb-to-serial-converter> |

## todo

- [x] write serial writer poc on uno
  - using digital read/write
  - uno r3 is too slow to write at `115200` baud rate
  - tested
    - [x] 9600 (succes)
    - [x] 14400 (succes)
    - [x] 19200 (failed, not fast enough)
    - [x] 115200 (failed, not fast enough)
- [x] write serial reader poc on uno
- [x] write MMIO serial writer poc on uno
- [x] write MMIO serial reader poc on uno
- [x] write serial reader/writer poc on nucleo
  - tested speeds
    - [x] 9600 (succes)
    - [x] 38400 (succes)
    - [x] 57600 (succes)
    - [x] 115200 (does not work. output gets garbeld)
- [x] state diagram
  - use the function names to link them
- [ ] report
  - [ ] update intro?
  - [ ] tests
  - [ ] conclusion

## info

| bit | value | info |
| --- | --- | ---|
| `start` | digital `0` | signifies the start of a byte |
| `stop` | digital `1` | signifies the stop of a byte |
| `on` | digital `1` | on value of the bit in the byte |
| `off` | digital `0` | off value of the bit in the byte |
| `idle` | digital `1` | idle state of the serial line |

## class diagram

```mermaid
classDiagram
class SoftUart~typename DataType, uint8_t numDataBits, uint8_t numStopBits, uint8_t numParityBits, uint8_t bufferSize~ {
  +SoftUart(uint32_t baud)
  +Setup() bool
  +ReadByte(char& byte) bool
  +WriteByte(uint8_t byte)
  +Write(string_view text)
  -BitDuration() uint64_t
  -updateTimerAndWait(const uint64_t& duration)

  -NucleoPin rx
  -NucleoPin tx
  -HardwareTimer tim
  -const uint32_t baud
  -const bool BITSTART
  -const bool BITSTOP
  -const bool BITONE
  -const bool BITZERO
  -const bool BITIDLE
}
```

## state diagram

> arrows with no guard can be considered an else case

```mermaid
stateDiagram-v2
state "read byte" as rb
state "detecting start bit" as dsb
state "reading data bits" as rdb

state "UpdateTimerAndWait" as utw1
state "UpdateTimerAndWait" as utw2
state "UpdateTimerAndWait" as utw3

state "reading parity bits" as rpb
state "detecting stop bits" as rsb
state "detecting stop bit" as dstopb
state "reading data bit i" as rdi
state "reading parity bit i" as rpi
state "calculate parity bit i" as cpbi
%%state "a"

dsb : entry / rx.read()

[*] --> rb
state rb {
  [*] --> dsb
  dsb --> [*] : [rx.read != BITSTART]/return false
  dsb --> rdb : [rx.read == BITSTART]

  state rdb{
    [*] --> rdi : / i = 0
    rdi --> utw1
    utw1 --> rdi : [i < numDataBits]/ i++
    utw1 --> [*] : [i >= numDataBits]
  }

  rdb --> rpb : [numParityBits > 0]
  rdb --> rsb : [numParityBits == 0]

  state rpb{
    [*] --> cpbi : / i = 0
    cpbi --> rpi
    rpi --> utw2
    utw2 --> rpi : [i < numParityBits]/ i++
    utw2 --> [*] : [i >= numParityBits]
  }

  rpb --> rsb

  state rsb {
    [*] --> dstopb : / i = 0
    dstopb --> utw3 : [rx.read == BITSTOP]
    dstopb --> [*] : [rx.read != BITSTOP] / return false
    utw3 --> dstopb : [i < numStopBits] / i++
    utw3 --> [*] : [i >= numStopBits]
  }

  rsb --> [*]
}
rb --> [*] : / return true

```

### old version

```mermaid
stateDiagram-v2
state "Write" as w
state "WriteByte" as wb
state "start bit" as wsta
state "data bits" as wd
state "parity bits" as wp
state "stop bits" as ws

wsta : exit / updateTimerAndWait
wd : exit / updateTimerAndWait
wp : exit / updateTimerAndWait
ws : exit / updateTimerAndWait

state w {
  state wb{
    [*] --> wsta
    wsta --> wd
    wd --> wp
    wp --> ws
    ws --> [*]
  }

  [*] --> wb
  wb --> [*]
}

[*] --> w
w --> [*]
```
