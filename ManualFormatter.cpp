#include "ManualFormatter.h"

#include <string>
#include "ColorCode.h"
#include "ColorPair.h"

namespace TelCoColorCoder {

std::string makeReferenceManual() {
  std::string out;
  out.reserve(640);
  out += "25-Pair Color Code Reference Manual\n";
  out += "-----------------------------------\n";
  for (int n = 1; n <= totalPairs(); ++n) {
    auto pair = colorFromPairNumber(n);
    out += std::to_string(n);
    out += " - ";
    out += ColorPair{pair.first, pair.second}.toString();
    out += '\n';
  }
  return out;
}

}