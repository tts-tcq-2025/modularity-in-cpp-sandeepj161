#ifndef COLORCODE_H_
#define COLORCODE_H_

#include <cstddef>
#include <utility>

namespace TelCoColorCoder {

enum class MajorColor : std::size_t { White, Red, Black, Yellow, Violet };
enum class MinorColor : std::size_t { Blue, Orange, Green, Brown, Slate };

constexpr int numberOfMajorColors() noexcept { return 5; }
constexpr int numberOfMinorColors() noexcept { return 5; }
constexpr int totalPairs() noexcept {
  return numberOfMajorColors() * numberOfMinorColors();
}

constexpr int pairNumberFromColor(MajorColor major,
                                  MinorColor minor) noexcept {
  return static_cast<int>(static_cast<int>(major) * numberOfMinorColors() +
                          static_cast<int>(minor) + 1);
}

std::pair<MajorColor, MinorColor> colorFromPairNumber(int pairNumber);

const char* majorColorName(MajorColor major);
const char* minorColorName(MinorColor minor);

const char* const* majorNamesTable() noexcept;
const char* const* minorNamesTable() noexcept;

}

#endif