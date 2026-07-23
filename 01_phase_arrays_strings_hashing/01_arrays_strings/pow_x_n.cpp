// Pow(x, n) — https://leetcode.com/problems/powx-n/
// Compute x raised to the power n (binary exponentiation).
#include <iostream>

double myPow(double x, long long n) {
    if (n < 0) { // negative exponent -> reciprocal
        x = 1.0 / x;
        n = -n;
    }
    double ans = 1.0;
    while (n) {
        if (n & 1) ans *= x; // multiply bit contribution
        x *= x; // square base
        n >>= 1; // next bit
    }
    return ans;
}

int main() {
    std::cout << myPow(2.0, 10) << " (expected 1024)\n";
    return 0;
}
