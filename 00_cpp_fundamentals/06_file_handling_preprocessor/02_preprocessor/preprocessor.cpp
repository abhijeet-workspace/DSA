// Preprocessor — local teaching demo
// Show a simple #define macro expanded before compilation.
#include <iostream>

#define PI 3.14 // compile-time text substitution

int main() {
    std::cout << "PI = " << PI << '\n'; // PI becomes 3.14
    return 0;
}
