// Lambdas — anonymous function objects (C++11/14)
// Captures, mutable, generic params, and STL algorithm comparators.
#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::cout << "=== C++ Lambdas Demonstration ===\n\n";

    auto greet = []() {
        std::cout << "Hello from a simple lambda!\n";
    };
    greet();

    int factor = 2;
    int divisor = 5;
    auto capture_val = [factor](int x) { return x * factor; }; // copy of factor
    auto capture_ref = [&divisor](int x) {
        divisor = 10; // mutates outer divisor
        return x / divisor;
    };

    std::cout << "Capture by value (factor=" << factor << "): 5 * factor = "
              << capture_val(5) << "\n";
    std::cout << "Capture by reference (before divisor=" << divisor
              << "): 20 / divisor = " << capture_ref(20);
    std::cout << " (after divisor=" << divisor << ")\n";

    int counter = 0;
    auto increment = [counter]() mutable {
        counter++; // modifies the captured copy only
        std::cout << "Inside mutable lambda counter = " << counter << "\n";
    };
    increment();
    increment();
    std::cout << "Outside lambda counter = " << counter << " (unchanged)\n";

    auto print_val = [](auto x) { // C++14 generic lambda
        std::cout << "Generic lambda print: " << x << "\n";
    };
    print_val(10);
    print_val("C++ lambdas are powerful");

    std::vector<int> nums = {4, 2, 8, 5, 1};
    std::cout << "Original vector: ";
    for (int n : nums) std::cout << n << " ";
    std::cout << "\n";

    std::sort(nums.begin(), nums.end(), [](int a, int b) {
        return a > b; // descending
    });

    std::cout << "Sorted descending: ";
    for (int n : nums) std::cout << n << " ";
    std::cout << "\n";

    return 0;
}
