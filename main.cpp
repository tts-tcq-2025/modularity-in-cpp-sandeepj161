#include <iostream>
#include "ColorCode.h"
#include "ColorPair.h"
#include "ManualFormatter.h"

using TelCoColorCoder::MajorColor;
using TelCoColorCoder::MinorColor;
using TelCoColorCoder::colorFromPairNumber;
using TelCoColorCoder::pairNumberFromColor;
using TelCoColorCoder::ColorPair;
using TelCoColorCoder::makeReferenceManual;

static void testNumberToPair(int pair_number, MajorColor expected_major, MinorColor expected_minor) {
  auto p = colorFromPairNumber(pair_number);
  const ColorPair pair{p.first, p.second};
  std::cout << "Got pair " << pair.toString() << '\n';
  if (pair.major() != expected_major || pair.minor() != expected_minor) {
    std::cerr << "Mismatch for pair number " << pair_number << '\n';
    std::exit(1);
  }
}

static void testPairToNumber(MajorColor major, MinorColor minor, int expected_pair_number) {
  const int n = pairNumberFromColor(major, minor);
  std::cout << "Got pair number " << n << '\n';
  if (n != expected_pair_number) {
    std::cerr << "Mismatch for colors -> expected " << expected_pair_number << '\n';
    std::exit(1);
  }
}

int main() {
  testNumberToPair(4, MajorColor::White, MinorColor::Brown);
  testNumberToPair(5, MajorColor::White, MinorColor::Slate);
  testPairToNumber(MajorColor::Black, MinorColor::Orange, 12);
  testPairToNumber(MajorColor::Violet, MinorColor::Slate, 25);

  std::cout << '\n' << makeReferenceManual();
  return 0;
}