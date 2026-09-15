// Perfect Squares — https://leetcode.com/problems/perfect-squares/
// DP: dp[i] = min coins of squares summing to i (unbounded).
#include <algorithm>
#include <iostream>
#include <vector>

int numSquares(int n) {
    std::vector<int> dp(static_cast<size_t>(n) + 1, n + 1);
    dp[0] = 0;
    for (int i = 1; i <= n; ++i) {
        for (int s = 1; s * s <= i; ++s) {
            dp[static_cast<size_t>(i)] =
                std::min(dp[static_cast<size_t>(i)], dp[static_cast<size_t>(i - s * s)] + 1);
        }
    }
    return dp[static_cast<size_t>(n)];
}

int main() {
    std::cout << numSquares(12) << " (expected 3)\n"
              << numSquares(13) << " (expected 2)\n";
    return 0;
}
