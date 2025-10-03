#include <cassert>
#include "ColorCode.h"
#include "ColorPair.h"
#include "ManualFormatter.h"

using TelCoColorCoder::MajorColor;
using TelCoColorCoder::MinorColor;
using TelCoColorCoder::ColorPair;
using TelCoColorCoder::colorFromPairNumber;
using TelCoColorCoder::pairNumberFromColor;

#ifndef TEST_RUNNER
int main() {
    auto [m4, s4] = colorFromPairNumber(4);
    assert(m4 == MajorColor::White && s4 == MinorColor::Brown);
    auto [m5, s5] = colorFromPairNumber(5);
    assert(m5 == MajorColor::White && s5 == MinorColor::Slate);
    assert(pairNumberFromColor(MajorColor::Black,  MinorColor::Orange) == 12);
    assert(pairNumberFromColor(MajorColor::Violet, MinorColor::Slate)  == 25);

    for (int n = 1; n <= TelCoColorCoder::totalPairs(); ++n) {
        auto [maj, min] = colorFromPairNumber(n);
        assert(pairNumberFromColor(maj, min) == n);
    }
    return 0;
}
#endif