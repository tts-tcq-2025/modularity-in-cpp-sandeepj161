#include <cassert>
#include <string>
#include "ColorCode.h"
#include "ColorPair.h"
#include "ManualFormatter.h"

using namespace TelCoColorCoder;

static void test_roundtrip_all_pairs() {
    for (int n = 1; n <= totalPairs(); ++n) {
        auto [maj, min] = colorFromPairNumber(n);
        assert(pairNumberFromColor(maj, min) == n);
    }
}

static void test_known_mappings() {
    auto [maj4, min4] = colorFromPairNumber(4);
    assert(maj4 == MajorColor::White && min4 == MinorColor::Brown);

    auto [maj5, min5] = colorFromPairNumber(5);
    assert(maj5 == MajorColor::White && min5 == MinorColor::Slate);

    assert(pairNumberFromColor(MajorColor::Black, MinorColor::Orange) == 12);
    assert(pairNumberFromColor(MajorColor::Violet, MinorColor::Slate) == 25);
}

static void test_invalid_inputs() {
    bool thrown = false;
    try {
        colorFromPairNumber(0);
    } catch (const std::out_of_range&) {
        thrown = true;
    }
    assert(thrown);

    thrown = false;
    try {
        colorFromPairNumber(26); // invalid
    } catch (const std::out_of_range&) {
        thrown = true;
    }
    assert(thrown);
}

static void test_name_functions() {
    assert(std::string(majorColorName(MajorColor::Yellow)) == "Yellow");
    assert(std::string(minorColorName(MinorColor::Slate)) == "Slate");
}

static void test_colorpair_to_string() {
    ColorPair cp{MajorColor::Red, MinorColor::Green};
    assert(cp.toString() == "Red Green");
}

static void test_manual_formatting() {
    // Check start and end entries
    std::string manual = makeReferenceManual();
    assert(manual.find("1 - White Blue") != std::string::npos);
    assert(manual.find("25 - Violet Slate") != std::string::npos);
}

int main() {
    test_roundtrip_all_pairs();
    test_known_mappings();
    test_invalid_inputs();
    test_name_functions();
    test_colorpair_to_string();
    test_manual_formatting();
    return 0;
}
