// Sqrt(x) — https://leetcode.com/problems/sqrtx/
// Integer Newton: r = (r + x/r) / 2 until stable.
#include <iostream>

int mySqrt(int x) {
    if (x < 2) return x;
    long r = x;
    while (r > x / r) r = (r + x / r) / 2;
    return static_cast<int>(r);
}

int main() {
    std::cout << mySqrt(4) << " (expected 2)\n"
              << mySqrt(8) << " (expected 2)\n"
              << mySqrt(0) << " (expected 0)\n"
              << mySqrt(2147395600) << " (expected 46340)\n";
    return 0;
}
