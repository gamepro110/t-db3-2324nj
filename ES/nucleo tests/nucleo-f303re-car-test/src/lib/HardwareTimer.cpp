#include "HardwareTimer.hpp"

HardwareTimer::HardwareTimer(TIM_TypeDef *timer) :
    timer(timer)
{}

bool HardwareTimer::Init(uint8_t prescaler, uint32_t arrValue, uint32_t outputCCValue, const uint8_t outputChannel, const uint8_t inputChannel1, const uint8_t inputChannel2) {
    if (timer == TIM6 || timer == TIM17) {
        return false;
    }

    SetEnablePeripheralClock();
    SetPrescaler(prescaler);

    // input
    SetEnableCCModex(inputChannel1, 1, 0);
    SetEnableCCModex(inputChannel2, 2, 0);
    SetEnableCCx(inputChannel1, 1, 0, 0);
    SetEnableCCx(inputChannel2, 1, 1, 0);
    SetSlaveModeResetFP1();

    // output
    SetAutoReload(arrValue);
    SetEnableCCModex(outputChannel, 0, 6);
    SetCCRxRegister(outputCCValue, outputChannel);
    SetEnableCCx(outputChannel, 1, 0, 0);

    if (timer == TIM15 || timer == TIM16 || timer == TIM17) {
        timer->BDTR |= TIM_BDTR_MOE;
    }

    SetTimerEnable();
    return true;
}

void HardwareTimer::SetTimerEnable() const {
    timer->CR1 = TIM_CR1_CEN;
}

//geeft echte divider mee want doet min om die waarde in het register te stoppen.
void HardwareTimer::SetPrescaler(const uint8_t prescalerDivider) const {
    timer->PSC = prescalerDivider - 1;
}

void HardwareTimer::SetEnablePeripheralClock() const {
    if (timer == TIM1 || timer > TIM7) {
        int temp = (int) timer - 0x40010000;
        temp = temp / 1024;
        RCC->APB2ENR |= (1 << temp);
    }
    else if (timer == TIM15) {
        RCC->APB2ENR |= RCC_APB2ENR_TIM15EN;
    }
    else {
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

void HardwareTimer::SetCCRxRegister(const uint32_t CCRvalue, const uint8_t registerNo) const {
    switch (registerNo) {
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

uint32_t HardwareTimer::GetCaptureCompareRegister1() const {
    return timer->CCR1;
}

uint32_t HardwareTimer::GetCaptureCompareRegister2() const {
    return timer->CCR2;
}

uint32_t HardwareTimer::GetCaptureCompareRegister3() const {
    return timer->CCR3;
}

uint32_t HardwareTimer::GetCaptureCompareRegister4() const {
    return timer->CCR4;
}

uint32_t HardwareTimer::GetTimerCount() const {
    return timer->CNT;
}
