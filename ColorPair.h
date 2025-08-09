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

    std::string toString() const {
        const char* maj = majorColorName(major_);
        const char* min = minorColorName(minor_);
        std::string s;
        s.reserve(16);
        s += maj;
        s += ' ';
        s += min;
        return s;
    }

private:
    MajorColor major_;
    MinorColor minor_;
};

}

#endif
