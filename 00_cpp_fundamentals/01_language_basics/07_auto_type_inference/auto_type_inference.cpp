// Auto Type Inference — C++ basics
// Show auto with a comparison expression and a separate helper return.
#include <iostream>

int getValue(); // forward declaration

int main() {
    auto result = (10 <= 20) > 0; // auto deduces bool from comparison chain
    std::cout << result << std::endl; // prints 1 (true)
    std::cout << getValue() << std::endl; // prints 36
    return 0;
}

int getValue() {
    int result = 4 * 9; // local product
    return result;
}
