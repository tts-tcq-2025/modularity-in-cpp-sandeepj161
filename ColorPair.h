#ifndef COLOR_PAIR_H
#define COLOR_PAIR_H

#include <string>
#include "ColorCode.h"

namespace TelCoColorCoder {

class ColorPair {
public:
    constexpr ColorPair(MajorColor major, MinorColor minor) noexcept
        : major_(major), minor_(minor) {}

    constexpr MajorColor major() const noexcept { return major_; }
    constexpr MinorColor minor() const noexcept { return minor_; }

    std::string toString() const;

private:
    MajorColor major_;
    MinorColor minor_;
};

}

#endif