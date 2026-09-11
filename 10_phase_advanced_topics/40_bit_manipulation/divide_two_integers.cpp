// Divide Two Integers — https://leetcode.com/problems/divide-two-integers/
// Quotient via exponential subtract (shift doubles); clamp INT_MIN/-1 → INT_MAX.
#include <climits>
#include <cstdlib>
#include <iostream>

int divide(int dividend, int divisor) {
    if (dividend == INT_MIN && divisor == -1) return INT_MAX;

    const bool negative = (dividend > 0) ^ (divisor > 0);
    long long a = std::llabs(static_cast<long long>(dividend));
    long long b = std::llabs(static_cast<long long>(divisor));
    long long quotient = 0;

    while (a >= b) {
        long long temp = b;
        long long multiple = 1;
        // Double while 2*temp still fits in a (avoid signed overflow via long long).
        while (a >= (temp << 1)) {
            temp <<= 1;
            multiple <<= 1;
        }
        a -= temp;
        quotient += multiple;
    }

    return static_cast<int>(negative ? -quotient : quotient);
}

int main() {
    std::cout << divide(10, 3) << " (expected 3)\n"
              << divide(7, -3) << " (expected -2)\n"
              << divide(INT_MIN, -1) << " (expected " << INT_MAX << ")\n"
              << divide(INT_MIN, 1) << " (expected " << INT_MIN << ")\n"
              << divide(1, 1) << " (expected 1)\n";
    return 0;
}
