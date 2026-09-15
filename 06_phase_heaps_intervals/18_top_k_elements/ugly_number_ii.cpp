// Ugly Number II — https://leetcode.com/problems/ugly-number-ii/
// Generate nth ugly number via three pointers / min-candidates (heap-like merge).
#include <algorithm>
#include <iostream>
#include <vector>

int nthUglyNumber(int n) {
    std::vector<int> ugly(static_cast<size_t>(n));
    ugly[0] = 1;
    int i2 = 0;
    int i3 = 0;
    int i5 = 0;
    for (int i = 1; i < n; ++i) {
        const long long next2 = static_cast<long long>(ugly[static_cast<size_t>(i2)]) * 2;
        const long long next3 = static_cast<long long>(ugly[static_cast<size_t>(i3)]) * 3;
        const long long next5 = static_cast<long long>(ugly[static_cast<size_t>(i5)]) * 5;
        const long long nxt = std::min({next2, next3, next5});
        ugly[static_cast<size_t>(i)] = static_cast<int>(nxt);
        if (nxt == next2) {
            ++i2;
        }
        if (nxt == next3) {
            ++i3;
        }
        if (nxt == next5) {
            ++i5;
        }
    }
    return ugly[static_cast<size_t>(n - 1)];
}

int main() {
    std::cout << nthUglyNumber(10) << " (expected 12)\n" << nthUglyNumber(1) << " (expected 1)\n";
    return 0;
}
