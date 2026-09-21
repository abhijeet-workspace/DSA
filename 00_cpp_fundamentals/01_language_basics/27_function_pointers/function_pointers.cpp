// Function Pointers — C++ basics
// Store and call functions via pointers; pass a callback into an algorithm-style helper.
#include <iostream>

int add(int a, int b) {
    return a + b;
}

int mul(int a, int b) {
    return a * b;
}

int apply(int a, int b, int (*op)(int, int)) { // callback parameter
    return op(a, b);
}

int main() {
    int (*fn)(int, int) = add; // pointer to function
    std::cout << "fn(2,3) via add=" << fn(2, 3) << '\n';

    fn = mul;
    std::cout << "fn(2,3) via mul=" << fn(2, 3) << '\n';

    std::cout << "apply add=" << apply(4, 5, add) << " apply mul=" << apply(4, 5, mul) << '\n';

    // Modern alternative: lambdas / std::function (see 09_modern_cpp)
    auto lambda = [](int a, int b) { return a - b; };
    std::cout << "lambda(9,4)=" << lambda(9, 4) << '\n';

    return 0;
}
