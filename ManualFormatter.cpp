#include "ManualFormatter.h"
#include "ColorCode.h"
#include "ColorPair.h"
#include <string>

namespace TelCoColorCoder {

std::string makeReferenceManual() {
std::string out;
out.reserve(640);
out += "25-Pair Color Code Reference Manual\n";
out += "-----------------------------------\n";
for (int n = 1; n <= totalPairs(); ++n) {
auto [maj, min] = colorFromPairNumber(n);
out += std::to_string(n);
out += " - ";
out += ColorPair{maj, min}.toString();
out += '\n';
}
return out;
}

} 