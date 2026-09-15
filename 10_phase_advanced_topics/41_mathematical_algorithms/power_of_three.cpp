// Power of Three — https://leetcode.com/problems/power-of-three/
// 3^19 = 1162261467 is the largest power of 3 in 32-bit signed int.
#include <iostream>

bool isPowerOfThree(int n) {
    return n > 0 && 1162261467 % n == 0;
}

int main() {
    std::cout << std::boolalpha << isPowerOfThree(27) << " (expected true)\n"
              << isPowerOfThree(0) << " (expected false)\n"
              << isPowerOfThree(9) << " (expected true)\n";
    return 0;
}
