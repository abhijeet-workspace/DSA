// Enum Basics — C++ fundamentals
// Define Color enumerators and print the underlying integer of GREEN.
#include <iostream>

enum Color { RED, GREEN, BLUE }; // unscoped enumerators: 0,1,2

int main() {
    Color c = GREEN; // named constant instead of magic 1
    std::cout << "Enum value: " << c; // prints underlying int (1)
    return 0;
}
