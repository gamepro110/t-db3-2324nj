#ifndef LIB_IBTNIRQ_HPP_
#define LIB_IBTNIRQ_HPP_

class IBtnIrq {
public:
    virtual ~IBtnIrq() {}
    virtual void HandleIrq() = 0;
    virtual bool SetupIrq() = 0;
};

#endif
