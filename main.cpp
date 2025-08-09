#include <iostream>
#include "ColorCode.h"
#include "ColorPair.h"
#include "ManualFormatter.h"

using namespace TelCoColorCoder;

static void testNumberToPair(int pairNumber, MajorColor expectedMajor, MinorColor expectedMinor) {
    auto [maj, min] = colorFromPairNumber(pairNumber);
    const ColorPair p{maj, min};
    std::cout << "Got pair " << p.toString() << '\n';

    if (p.major() != expectedMajor || p.minor() != expectedMinor) {
        std::cerr << "Mismatch for " << pairNumber << '\n';
        std::exit(1);
    }
}

static void testPairToNumber(MajorColor major, MinorColor minor, int expectedPairNumber) {
    const int n = pairNumberFromColor(major, minor);
    std::cout << "Got pair number " << n << '\n';
    if (n != expectedPairNumber) {
        std::cerr << "Mismatch for " << static_cast<int>(major) << ", " << static_cast<int>(minor) << '\n';
        std::exit(1);
    }
}

int main() {
    testNumberToPair(4, MajorColor::White, MinorColor::Brown);
    testNumberToPair(5, MajorColor::White, MinorColor::Slate);
    testPairToNumber(MajorColor::Black,  MinorColor::Orange, 12);
    testPairToNumber(MajorColor::Violet, MinorColor::Slate,  25);

    std::cout << '\n' << makeReferenceManual();
    return 0;
}