// Minimum Cost Tree From Leaf Values —
// https://leetcode.com/problems/minimum-cost-tree-from-leaf-values/
#include <algorithm>
#include <iostream>
#include <vector>

int mctFromLeafValues(std::vector<int>& arr) {
    const int n = static_cast<int>(arr.size());
    std::vector<std::vector<int>> mx(n, std::vector<int>(n, 0)), dp(n, std::vector<int>(n, 0));
    for (int i = 0; i < n; ++i) {
        mx[static_cast<size_t>(i)][static_cast<size_t>(i)] = arr[static_cast<size_t>(i)];
        for (int j = i + 1; j < n; ++j)
            mx[static_cast<size_t>(i)][static_cast<size_t>(j)] =
                std::max(mx[static_cast<size_t>(i)][static_cast<size_t>(j - 1)],
                         arr[static_cast<size_t>(j)]);
    }
    for (int len = 2; len <= n; ++len) {
        for (int i = 0; i + len - 1 < n; ++i) {
            const int j = i + len - 1;
            dp[static_cast<size_t>(i)][static_cast<size_t>(j)] = 1e9;
            for (int k = i; k < j; ++k) {
                dp[static_cast<size_t>(i)][static_cast<size_t>(j)] =
                    std::min(dp[static_cast<size_t>(i)][static_cast<size_t>(j)],
                             dp[static_cast<size_t>(i)][static_cast<size_t>(k)] +
                                 dp[static_cast<size_t>(k + 1)][static_cast<size_t>(j)] +
                                 mx[static_cast<size_t>(i)][static_cast<size_t>(k)] *
                                     mx[static_cast<size_t>(k + 1)][static_cast<size_t>(j)]);
            }
        }
    }
    return dp[0][static_cast<size_t>(n - 1)];
}

int main() {
    std::vector<int> arr{6, 2, 4};
    std::cout << mctFromLeafValues(arr) << " (expected 32)\n";
    return 0;
}
