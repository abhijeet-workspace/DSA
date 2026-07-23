// 0/1 Knapsack — classic capacity DP (each item at most once).
// 1D rolling: iterate weight descending so each item is used once.
#include <algorithm>
#include <iostream>
#include <vector>

int knapsack(int W, const std::vector<int>& wt, const std::vector<int>& val) {
    std::vector<int> dp(static_cast<size_t>(W) + 1, 0);
    const int n = static_cast<int>(wt.size());
    for (int i = 0; i < n; ++i) {
        for (int w = W; w >= wt[static_cast<size_t>(i)]; --w) {
            dp[static_cast<size_t>(w)] = std::max(
                dp[static_cast<size_t>(w)],
                dp[static_cast<size_t>(w - wt[static_cast<size_t>(i)])] +
                    val[static_cast<size_t>(i)]);
        }
    }
    return dp[static_cast<size_t>(W)];
}

int main() {
    const std::vector<int> val = {60, 100, 120};
    const std::vector<int> wt = {10, 20, 30};
    std::cout << knapsack(50, wt, val) << " (expected 220)\n";
    return 0;
}
