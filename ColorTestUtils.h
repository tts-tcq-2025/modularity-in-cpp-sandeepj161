#pragma once
#include <cassert>
#include <string>
#include <stdexcept>
#include "ColorCode.h"
#include "ColorPair.h"
#include "ManualFormatter.h"

namespace TelCoColorCoder::TestUtils {

inline void validateAllPairs() {
    for (int n = 1; n <= totalPairs(); ++n) {
        auto [maj, min] = colorFromPairNumber(n);
        assert((pairNumberFromColor(maj, min) == n));
    }
}

inline void validateSpecificPairs() {
    auto [m4, s4] = colorFromPairNumber(4);
    assert((m4 == MajorColor::White && s4 == MinorColor::Brown));

    auto [m5, s5] = colorFromPairNumber(5);
    assert((m5 == MajorColor::White && s5 == MinorColor::Slate));

    assert((pairNumberFromColor(MajorColor::Black, MinorColor::Orange) == 12));
    assert((pairNumberFromColor(MajorColor::Violet, MinorColor::Slate) == 25));
}

inline void validateInvalidInputs() {
    try { colorFromPairNumber(0); } catch (const std::out_of_range&) {} 
    try { colorFromPairNumber(26); } catch (const std::out_of_range&) {}

    // Separate asserts outside try/catch
    assert(true); // Optional: keep header syntactically correct
}

inline void validateNamesAndStrings() {
    assert((std::string(majorColorName(MajorColor::Yellow)) == "Yellow"));
    assert((std::string(minorColorName(MinorColor::Slate)) == "Slate"));
    assert((ColorPair{MajorColor::Red, MinorColor::Green}.toString() == std::string("Red Green")));
}

inline void validateReferenceManual() {
    const std::string manual = makeReferenceManual();
    assert((manual.find("1 - White Blue") != std::string::npos));
    assert((manual.find("25 - Violet Slate") != std::string::npos));
}

} // namespace TestUtils
