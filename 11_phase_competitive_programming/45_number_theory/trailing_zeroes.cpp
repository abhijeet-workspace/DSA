// LC172 Factorial Trailing Zeroes
#include <iostream>

int trailingZeroes(int n) {
    int ans = 0;
    while (n > 0) {
        n /= 5;
        ans += n;
    }
    return ans;
}

int main() {
    std::cout << "trailingZeroes(3)=" << trailingZeroes(3) << " (expected 0)\n";
    std::cout << "trailingZeroes(5)=" << trailingZeroes(5) << " (expected 1)\n";
    std::cout << "trailingZeroes(25)=" << trailingZeroes(25) << " (expected 6)\n";
    return 0;
}
