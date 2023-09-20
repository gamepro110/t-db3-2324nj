#include "encoder.h"

#include "lib/print.h"

Encoder::Encoder(GPIO_TypeDef* blockPinClk, uint8_t pinClk, GPIO_TypeDef* blockPinDt, uint8_t pinDt) :
    blockPinClk(blockPinClk), pinClk(pinClk), blockPinDt(blockPinDt), pinDt(pinDt)
{
    blockPinClk->MODER = (
        (blockPinClk->MODER & ~(0b00 << (2* pinClk))) |
        (0b00 << (2 * pinClk))
    );

    blockPinDt->MODER = (
        (blockPinDt->MODER & ~(0b00 << (2* pinDt))) |
        (0b00 << (2 * pinDt))
    );
}

Encoder::~Encoder() {
}

EncoderOutput Encoder::Poll() {
    EncoderOutput output = EncoderOutput::NoChange;
    sigClk = (blockPinClk->IDR & (1 << pinClk)) == 0;
    sigDt = (blockPinDt->IDR & (1 << pinDt)) == 0;

    const int MSGBUFSIZE = 80;
    char msgBuf[MSGBUFSIZE];
    snprintf(msgBuf, MSGBUFSIZE, "clk:%d dt:%d ", sigClk, sigDt);
    vprint(msgBuf);

    uint32_t now = HAL_GetTick();

    if (sigClk && (now - lastTrigger) > debouncTime) {
        lastTrigger = now;

        if (sigDt) {
            output = EncoderOutput::rotatedLeft;
        }
        else {
            output = EncoderOutput::rotatedRight;
        }
    }

    return output;
}
