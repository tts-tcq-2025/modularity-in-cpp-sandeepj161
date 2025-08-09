#ifndef COLOR_CODE_H
#define COLOR_CODE_H

#include <utility>
#include <cstddef>

namespace TelCoColorCoder {

enum class MajorColor : std::size_t { White, Red, Black, Yellow, Violet };
enum class MinorColor : std::size_t { Blue, Orange, Green, Brown, Slate };

constexpr int numberOfMajorColors() noexcept { return 5; }
constexpr int numberOfMinorColors() noexcept { return 5; }
constexpr int totalPairs() noexcept { return numberOfMajorColors() * numberOfMinorColors(); }

constexpr int pairNumberFromColor(MajorColor major, MinorColor minor) noexcept {
    return static_cast<int>(static_cast<int>(major) * numberOfMinorColors()
         + static_cast<int>(minor) + 1);
}

std::pair<MajorColor, MinorColor> color