#include "HardwareTimer.hpp"

HardwareTimer::HardwareTimer(TIM_TypeDef *timer) :
    timer(timer)
{
}

void HardwareTimer::SetTimerEnable() const {
    timer->CR1 = TIM_CR1_CEN;
}

//geeft echte divider mee want doet min om die waarde in het register te stoppen.
void HardwareTimer::SetPrescaler(const uint8_t prescalerDivider) const {
    timer->PSC = prescalerDivider - 1;
}

void HardwareTimer::SetEnablePeripheralClock() const {
    if(timer == TIM1 || timer > TIM7)
    {
        int temp = (int) timer - 0x40010000;
        temp = temp / 1024;
        RCC->APB2ENR |= (1 << temp);
    }
    else
    {
        //voor waardes tim2 tot en met tim7, zitten in apb1enr en zitten op de eerste paar bits, dus kun je bitshiften.
        int temp = (int) timer - 0x40000000;
        temp = temp / 1024;
        RCC->APB1ENR |= (1 << temp);
    }
}

void HardwareTimer::SetEnableCCModex(const uint8_t channel, const uint8_t ccxs, const uint8_t ocxm) const {
    uint8_t tempocxm = ocxm << 4;
    switch(channel)
    {
        case 1:
            timer->CCMR1 |= ccxs;
            timer->CCMR1 |= tempocxm;
            break;
        case 2:
            timer->CCMR1 |= ccxs << 8;
            timer->CCMR1 |= tempocxm << 8;
            break;
        case 3:
            timer->CCMR2 |= ccxs;
            timer->CCMR2 |= tempocxm;
            break;
        case 4:
            timer->CCMR2 |= ccxs << 8;
            timer->CCMR2 |= tempocxm << 8;
            break;
        default:
            break;
    }
}

void HardwareTimer::SetEnableCCx(const uint8_t channel, const uint8_t ccxe, const uint8_t ccxp, const uint8_t ccxnp) const {
    timer->CCER |= (ccxe | (ccxp << 1) | (ccxnp << 3)) << (4 * channel - 4);
}


int HardwareTimer::InitiliazePWMOutput(const uint16_t prescalerdivider, const uint32_t arrvalue, const uint32_t ccrvalue, const uint8_t channelNo) {
    SetEnablePeripheralClock();
    SetPrescaler(prescalerdivider);
    SetAutoReload(arrvalue);
    SetEnableCCModex(channelNo, 0, 6);
    SetCCRxRegister(ccrvalue, channelNo);
    SetEnableCCx(channelNo, 1, 0, 0);

    if(timer == TIM15 || timer == TIM16 || timer == TIM17) //verander het naar alle advanced timers
    {
        timer->BDTR |= TIM_BDTR_MOE;
    }

    SetTimerEnable();
    return 0;
}

void HardwareTimer::SetCCRxRegister(const uint32_t CCRvalue, const uint8_t registerNo) const {
    switch (registerNo)
    {
    case 1:
        timer->CCR1 = CCRvalue;
        break;
    case 2:
        timer->CCR2 = CCRvalue;
        break;
    case 3:
        timer->CCR3 = CCRvalue;
        break;
    case 4:
        timer->CCR4 = CCRvalue;
        break;
    default:
        break;
    }
}

void HardwareTimer::SetAutoReload(const uint32_t ARRvalue) const {
    timer->ARR = ARRvalue;
}

void HardwareTimer::SetSlaveModeResetFP1() const {
    timer->SMCR = TIM_SMCR_TS_2 | TIM_SMCR_TS_0 | TIM_SMCR_SMS_2;
}

int HardwareTimer::InitiliazePWMInput(const uint16_t prescalerdivider, const uint8_t channel1, const uint8_t channel2) {
    if(timer == TIM16 || timer == TIM17)
    {
        return -1;
    }

    SetEnablePeripheralClock();
    SetPrescaler(prescalerdivider);
    SetEnableCCModex(channel1, 1, 0);
    SetEnableCCModex(channel2, 2, 0);
    SetEnableCCx(channel1, 1, 0, 0);
    SetEnableCCx(channel2, 1, 1, 0);
    SetSlaveModeResetFP1();
    SetTimerEnable();
    return 0;
}

uint32_t HardwareTimer::GetCaptureCompareRegister1() {
    return timer->CCR1;
}

uint32_t HardwareTimer::GetCaptureCompareRegister2() {
    return timer->CCR2;
}

uint32_t HardwareTimer::GetCaptureCompareRegister3() {
    return timer->CCR3;
}

uint32_t HardwareTimer::GetCaptureCompareRegister4() {
    return timer->CCR4;
}

uint32_t HardwareTimer::GetTimerCount() {
    return timer->CNT;
}
