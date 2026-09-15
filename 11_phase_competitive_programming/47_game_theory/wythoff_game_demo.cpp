#include <algorithm>
#include <cmath>
#include <iostream>

bool isCold(int a, int b) {
    if (a > b)
        std::swap(a, b);
    double phi = (1 + std::sqrt(5.0)) / 2.0;
    for (int k = 0; k <= a + 2; ++k) {
        int A = (int)std::floor(k * phi);
        int B = A + k;
        if (A == a && B == b)
            return true;
        if (A > a)
            break;
    }
    return false;
}

bool firstWins(int a, int b) {
    return !isCold(a, b);
}

int main() {
    std::cout << std::boolalpha << firstWins(1, 2) << " (expected false)\n"
              << firstWins(1, 3) << " (expected true)\n";
}