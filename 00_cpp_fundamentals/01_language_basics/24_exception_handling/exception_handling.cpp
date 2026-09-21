// Exception Handling — C++ basics
// throw / try / catch, catch-by-const-ref, and a fallback catch-all.
#include <iostream>
#include <stdexcept>
#include <string>

double safeDivide(double a, double b) {
    if (b == 0.0) {
        throw std::invalid_argument("division by zero");
    }
    return a / b;
}

int main() {
    try {
        std::cout << "10/2=" << safeDivide(10, 2) << '\n';
        std::cout << "10/0=" << safeDivide(10, 0) << '\n'; // throws
        std::cout << "unreachable\n";
    } catch (const std::invalid_argument& e) { // catch specific type by const ref
        std::cout << "caught invalid_argument: " << e.what() << '\n';
    } catch (const std::exception& e) { // base of standard hierarchy
        std::cout << "caught exception: " << e.what() << '\n';
    } catch (...) { // last resort
        std::cout << "caught unknown\n";
    }

    std::cout << "continues after handler\n";
    return 0;
}
