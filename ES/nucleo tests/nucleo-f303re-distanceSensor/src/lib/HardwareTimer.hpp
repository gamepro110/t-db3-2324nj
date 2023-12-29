#ifndef LIB_HARDWARETIMER_HPP_
#define LIB_HARDWARETIMER_HPP_

#include "stdint.h"
#include "stm32f3xx_hal.h"

class HardwareTimer {
public:
    HardwareTimer(TIM_TypeDef* timer);

    bool Init(uint8_t prescaler, uint32_t arrValue, uint32_t outputCCValue, const uint8_t outputChannel, const uint8_t inputChannel1, const uint8_t intputChannel2);

    void SetTimerEnable() const;
    void SetPrescaler(const uint8_t prescalerDivider) const;
    void SetEnablePeripheralClock() const;
    void SetEnableCCModex(const uint8_t channel, const uint8_t ccxs, const uint8_t ocxm) const;
    void SetEnableCCx(const uint8_t channel, const uint8_t ccxe, const uint8_t ccxp, const uint8_t ccxnp) const;
    void SetCCRxRegister(const uint32_t CCRvalue, const uint8_t registerNo) const;
    void SetAutoReload(const uint32_t ARRvalue) const;
    void SetSlaveModeResetFP1() const;

    uint32_t GetCaptureCompareRegister1() const;
    uint32_t GetCaptureCompareRegister2() const;
    uint32_t GetCaptureCompareRegister3() const;
    uint32_t GetCaptureCompareRegister4() const;
    uint32_t GetTimerCount() const;

private:
    TIM_TypeDef* timer;

};

#endif