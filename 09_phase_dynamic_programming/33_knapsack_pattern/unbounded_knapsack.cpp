// Unbounded Knapsack — classic complete knapsack (teaching)
#include <algorithm>
#include <iostream>
#include <vector>

int unboundedKnapsack(int W, const std::vector<int>& wt, const std::vector<int>& val) {
    std::vector<int> dp(static_cast<size_t>(W + 1), 0);
    const int n = static_cast<int>(wt.size());
    for (int i = 0; i < n; ++i) {
        for (int w = wt[static_cast<size_t>(i)]; w <= W; ++w) {
            dp[static_cast<size_t>(w)] = std::max(
                dp[static_cast<size_t>(w)],
                dp[static_cast<size_t>(w - wt[static_cast<size_t>(i)])] + val[static_cast<size_t>(i)]);
        }
    }
    return dp[static_cast<size_t>(W)];
}

int main() {
    std::vector<int> val{10, 40, 50, 70}, wt{1, 3, 4, 5};
    std::cout << unboundedKnapsack(8, wt, val) << " (expected 110)\n";
    return 0;
}
