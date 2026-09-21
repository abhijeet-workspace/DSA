// Assertions & Basic Debugging — C++ basics
// Show assert for invariants; contrast with runtime checks that stay in release builds.
#include <cassert>
#include <iostream>
#include <string>

int dividePositive(int a, int b) {
    assert(b != 0 && "divisor must be non-zero"); // disabled if NDEBUG is defined
    return a / b;
}

int checkedDivide(int a, int b) {
    if (b == 0) { // remains in release builds
        std::cerr << "error: division by zero\n";
        return 0;
    }
    return a / b;
}

int main() {
    std::cout << "dividePositive(10,2)=" << dividePositive(10, 2) << '\n';
    std::cout << "checkedDivide(10,0)=" << checkedDivide(10, 0) << '\n';

    // Uncomment to see assert abort in debug builds:
    // dividePositive(10, 0);

    std::string s = "debug tip: print intermediate state";
    std::cout << s << '\n';
    return 0;
}
