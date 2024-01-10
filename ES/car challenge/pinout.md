# pinout

## pins

| n | item | pin | reason | note |
| --- | --- | --- | --- | --- |
| 1 | button 0 | `PC0` |  | dont use irq2 |
| 2 | button 1 | `PC1` |  | dont use irq2 |
| 3 | ultrasonic input (echo) | `PB6` | tim4 alt func | `AF2` |
| 4 | ultrasonic input (trigger) | `PB8` | tim4 alt func | `AF2` |
| 5 | left servo drive | `PB14` | alt func pwm output tim15 ch1 | `AF1` |
| 6 | right servo drive | `PB15` | alt func pwm output tim15 ch2 | `AF1` |
| 7 | left servo measure | `PA15` | alt func pwm input tim2 ch1 | `AF1` |
| 8 | right servo measure | `PA6` | alt func pwm input tim3 ch1 | `AF2` |
<!-- |  |  | `P` |  |  | -->

## timer allocation

- `tim15`
  - driving servos
- `tim4`
  - trigger + echo dist sensor
- `tim2`
  - measure left servo output
- `tim3`
  - measure right servo output
