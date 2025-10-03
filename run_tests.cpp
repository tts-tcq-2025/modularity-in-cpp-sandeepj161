#include "ColorTestUtils.h"

using namespace TelCoColorCoder::TestUtils;

inline void runTests() {
    validateAllPairs();
    validateSpecificPairs();
    validateInvalidInputs();
    validateNamesAndStrings();
    validateReferenceManual();
}
