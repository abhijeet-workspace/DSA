// Counting Bits — https://leetcode.com/problems/counting-bits/
// dp[i] = dp[i>>1] + (i&1); reuse answer without LSB.
#include <iostream>
#include <vector>

std::vector<int> countBits(int n) {
    std::vector<int> dp(static_cast<size_t>(n) + 1, 0);
    for (int i = 1; i <= n; ++i) {
        dp[static_cast<size_t>(i)] = dp[static_cast<size_t>(i >> 1)] + (i & 1);
    }
    return dp;
}

int main() {
    for (int x : countBits(5)) std::cout << x << " ";
    std::cout << "(expected 0 1 1 2 1 2)\n";
    return 0;
}
