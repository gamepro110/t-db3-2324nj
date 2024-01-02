#include "watchdog.hpp"

#include "stm32f303xe.h"

Watchdog::Watchdog(const uint16_t reloadValue) {
    if (reloadValue != 0) {
        IWDG->KR = 0x5555;          // enable access to iwdg_pr, iwdg_rlr and iwdg_winr
        IWDG->PR = 0;               // prescaler devider: 0 = /4
        IWDG->RLR = reloadValue;    // setting reset value
        IWDG->KR = 0xAAAA;          // 'kick' watchdog
        IWDG->KR = 0xCCCC;          // starts watchdog
    }
}

void Watchdog::Reset() const {
    IWDG->KR = 0xAAAA;
}
