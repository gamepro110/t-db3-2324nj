#ifndef HARDWARETIMER_H
#define HARDWARETIMER_H

#include "stdint.h"
#include "stm32f3xx_hal.h"

class HardwareTimer {
public:
    HardwareTimer(TIM_TypeDef* timer);
    void SetTimerEnable() const;
    void SetPrescaler(const uint8_t prescalerDivider) const;
    void SetEnablePeripheralClock() const;
    void SetEnableCCModex(const uint8_t channel, const uint8_t ccxs, const uint8_t ocxm) const;
    void SetEnableCCx(const uint8_t channel, const uint8_t ccxe, const uint8_t ccxp, const uint8_t ccxnp) const;
    void SetCCRxRegister(const uint32_t CCRvalue, const uint8_t registerNo) const;
    void SetAutoReload(const uint32_t ARRvalue) const;
    void SetSlaveModeResetFP1() const;
    uint32_t GetCaptureCompareRegister1();
    uint32_t GetCaptureCompareRegister2();
    uint32_t GetCaptureCompareRegister3();
    uint32_t GetCaptureCompareRegister4();
    uint32_t GetTimerCount();
    int InitiliazePWMOutput(const uint16_t prescalerdivider, const uint32_t arrvalue, const uint32_t ccrvalue, const uint8_t ccrRegisterNo);
    int InitiliazePWMInput(const uint16_t prescalerdivider, const uint8_t channel1, const uint8_t channel2);

    TIM_TypeDef* GetTimPtr() const {
        return timer;
    }

private:
    TIM_TypeDef* timer;
};

#endif
