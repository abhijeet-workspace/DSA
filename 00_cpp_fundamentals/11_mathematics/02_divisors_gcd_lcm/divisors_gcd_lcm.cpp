// Divisors, GCD & LCM — C++ fundamentals
// O(sqrt(n)) divisors, Euclidean gcd, lcm via gcd.
#include <iostream>
#include <vector>
#include <algorithm>

std::vector<long long> divisors(long long n) {
    std::vector<long long> d;
    if (n <= 0) {
        return d;
    }
    for (long long i = 1; i * i <= n; ++i) {
        if (n % i == 0) {
            d.push_back(i);
            if (i != n / i) {
                d.push_back(n / i);
            }
        }
    }
    std::sort(d.begin(), d.end());
    return d;
}

long long gcdLL(long long a, long long b) {
    if (a < 0) {
        a = -a;
    }
    if (b < 0) {
        b = -b;
    }
    return b == 0 ? a : gcdLL(b, a % b);
}

long long lcmLL(long long a, long long b) {
    if (a == 0 || b == 0) {
        return 0;
    }
    return a / gcdLL(a, b) * b;
}

int main() {
    auto d = divisors(12);
    std::cout << "divisors of 12:";
    for (long long x : d) {
        std::cout << " " << x;
    }
    std::cout << " (expected 1 2 3 4 6 12)\n";

    std::cout << "gcd(48,18) = " << gcdLL(48, 18) << " (expected 6)\n";
    std::cout << "lcm(4,6) = " << lcmLL(4, 6) << " (expected 12)\n";
    return 0;
}
