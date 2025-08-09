#ifndef COLOR_CODE_H
#include <utility>
#include<cstddef>

namespace TelCoColorCoder {

enum class MajorColor : std::size_t { White, Red, Black, Yellow, Violet };

constexpr int numberOfMajorColors() noexcept { return 5; }
constexpr int numberOfMinorColors() noexcept { return 5; }

constexpr int pairNumberFromColor(MajorColor major, MinorColor minor) noexcept {
<int>(static_cast<int>(major) * numberOfMinorColors() + sta<int>(minor) + 1);
}
std::pair<MajorColor, MinorColor> colorFromPairNumber(

const char* majorColorName(MajorColor major);
}

#endif