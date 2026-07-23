// GCD, LCM, Extended Euclidean — Bezout: ax + by = gcd(a,b)
#include <iostream>

long long gcd(long long a, long long b) {
    return b == 0 ? a : gcd(b, a % b);
}

long long lcm(long long a, long long b) {
    return a / gcd(a, b) * b; // divide first to limit overflow
}

long long extGcd(long long a, long long b, long long& x, long long& y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    long long x1 = 0, y1 = 0;
    long long g = extGcd(b, a % b, x1, y1);
    x = y1;
    y = x1 - (a / b) * y1;
    return g;
}

int main() {
    std::cout << gcd(48, 18) << " (expected 6)\n";
    std::cout << lcm(4, 6) << " (expected 12)\n";
    long long x = 0, y = 0;
    long long g = extGcd(35, 15, x, y);
    std::cout << g << " " << x << " " << y << " (expected 5 1 -2)\n";
    return 0;
}
