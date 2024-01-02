#ifndef LIB_WATCHDOG_HPP_
#define LIB_WATCHDOG_HPP_

#include <cstdint>

class Watchdog {
public:
    /// @param reloadValue max (1<<11)
    Watchdog(const uint16_t reloadValue);
    ~Watchdog() = default;
    void Reset() const;
};

#endif
