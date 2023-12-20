#ifndef LIB_IBUTTON_HPP_
#define LIB_IBUTTON_HPP_

#include "IBtnIRQ.hpp"

class IButton : public IBtnIrq {
public:
    virtual ~IButton() {}
    virtual void ShortPress() = 0;
    virtual void LongPress() = 0;
};

#endif
