// Number of Ways to Paint N x 3 Grid —
// https://leetcode.com/problems/number-of-ways-to-paint-n-x-3-grid/
#include <iostream>

int numOfWays(int n) {
    constexpr int MOD = 1'000'000'007;
    // a: 121-type rows (2 colors), b: 123-type (3 colors)
    long long a = 6, b = 6; // for n=1: 12 total = 6+6
    for (int i = 2; i <= n; ++i) {
        const long long na = (3 * a + 2 * b) % MOD;
        const long long nb = (2 * a + 2 * b) % MOD;
        a = na;
        b = nb;
    }
    return static_cast<int>((a + b) % MOD);
}

int main() {
    std::cout << numOfWays(1) << " (expected 12)\n";
    std::cout << numOfWays(2) << " (expected 54)\n";
    return 0;
}
