#include "ColorPair.h"

namespace TelCoColorCoder {

std::string ColorPair::toString() const {
    const char* maj = majorColorName(major_);
    const char* min = minorColorName(minor_);
    std::string s;
    s.reserve(16);
    s += maj;
    s += ' ';
    s += min;
    return s;
}

}