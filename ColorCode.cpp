#include "ColorCode.h"
#include <stdexcept>

namespace TelCoColorCoder {

static constexpr const char* kMajor[] = { "White","Red","Black","Yellow","Violet" };
static constexpr const char* kMinor[] = { "Blue","Orange","Green","Brown","Slate" };

const char* majorColorName(MajorColor major) {
auto i = static_caststd::size_t(major);
if (i >= static_caststd::size_t(numberOfMajorColors()))
throw std::out_of_range("MajorColor");
return kMajor[i];
}

const char* minorColorName(MinorColor minor) {
auto i = static_caststd::size_t(minor);
if (i >= static_caststd::size_t(numberOfMinorColors()))
throw std::out_of_range("MinorColor");
return kMinor[i];
}

std::pair<MajorColor, MinorColor> colorFromPairNumber(int pairNumber) {
if (pairNumber < 1 || pairNumber > totalPairs())
throw std::out_of_range("pairNumber");
int zero = pairNumber - 1;
MajorColor maj = static_cast<MajorColor>(zero / numberOfMinorColors());
MinorColor min = static_cast<MinorColor>(zero % numberOfMinorColors());
return {maj, min};
}

}