#include "ColorCode.h"
#include <stdexcept>

namespace TelCoColorCoder {

static constexpr const char* kMajor[] = { "White","Red","Black","Yellow","Violet" };
static constexpr const char* kMinor[] = { "Blue","Orange","Green","Brown","Slate" };

const char* majorColorName(MajorColor major) {
    const auto i = static_cast<std::size_t>(major);
    if (i >= static_cast<std::size_t>(numberOfMajorColors()))
        throw std::out_of_range("MajorColor index out of range");
    return kMajor[i];
}

const char* minorColorName(MinorColor minor) {
    const auto i = static_cast<std::size_t>(minor);
    if (i >= static_cast<std::size_t>(numberOfMinorColors()))
        throw std::out_of_range("MinorColor index out of range");
    return kMinor[i];
}

std::pair<MajorColor, MinorColor> colorFromPairNumber(int pairNumber) {
    if (pairNumber < 1 || pairNumber > totalPairs())
        throw std::out_of_range("pairNumber out of range");
    const int zero = pairNumber - 1;
    MajorColor maj = static_cast<MajorColor>(zero / numberOfMinorColors());
    MinorColor min = static_cast<MinorColor>(zero % numberOfMinorColors());
    return {maj, min};
}

const char* const* majorNamesTable() noexcept { return kMajor; }
const char* const* minorNamesTable() noexcept { return kMinor; }

}