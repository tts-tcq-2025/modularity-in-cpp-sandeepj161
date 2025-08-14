#include <cassert>
#include "ColorCode.h"
#include "ColorPair.h"
#include "ManualFormatter.h"

using TelCoColorCoder::MajorColor;
using TelCoColorCoder::MinorColor;
using TelCoColorCoder::ColorPair;
using TelCoColorCoder::colorFromPairNumber;
using TelCoColorCoder::pairNumberFromColor;

static void testNumberToPair(int pairNumber,
                             MajorColor expectedMajor,
                             MinorColor expectedMinor) {
    auto [maj, min] = colorFromPairNumber(pairNumber);
    const ColorPair p{maj, min};
    assert(p.major() == expectedMajor);
    assert(p.minor() == expectedMinor);
}

static void testPairToNumber(MajorColor major,
                             MinorColor minor,
                             int expectedPairNumber) {
    const int n = pairNumberFromColor(major, minor);
    assert(n == expectedPairNumber);
}

int main() {
    testNumberToPair(4, MajorColor::White, MinorColor::Brown);
    testNumberToPair(5, MajorColor::White, MinorColor::Slate);
    testPairToNumber(MajorColor::Black,  MinorColor::Orange, 12);
    testPairToNumber(MajorColor::Violet, MinorColor::Slate,  25);

    return 0;
}