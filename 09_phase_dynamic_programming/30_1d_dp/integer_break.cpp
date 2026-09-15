// Integer Break — https://leetcode.com/problems/integer-break/
// Break n into ≥2 positive integers maximizing product; DP or prefer parts of 3.
#include <algorithm>
#include <iostream>
#include <vector>

int integerBreak(int n) {
    // dp[i] = max product breaking i into ≥2 parts
    std::vector<int> dp(static_cast<size_t>(n + 1), 0);
    dp[1] = 1;
    for (int i = 2; i <= n; ++i) {
        for (int j = 1; j < i; ++j) {
            // j + (i-j); second part may stay whole or be further broken
            dp[static_cast<size_t>(i)] = std::max(
                {dp[static_cast<size_t>(i)], j * (i - j), j * dp[static_cast<size_t>(i - j)]});
        }
    }
    return dp[static_cast<size_t>(n)];
}

int main() {
    std::cout << integerBreak(2) << " (expected 1)\n" << integerBreak(10) << " (expected 36)\n";
    return 0;
}
