// Unique Binary Search Trees — https://leetcode.com/problems/unique-binary-search-trees/
#include <iostream>
#include <vector>

int numTrees(int n) {
    std::vector<long long> dp(static_cast<size_t>(n + 1), 0);
    dp[0] = 1;
    for (int i = 1; i <= n; ++i)
        for (int j = 0; j < i; ++j)
            dp[static_cast<size_t>(i)] += dp[static_cast<size_t>(j)] * dp[static_cast<size_t>(i - 1 - j)];
    return static_cast<int>(dp[static_cast<size_t>(n)]);
}

int main() {
    std::cout << numTrees(3) << " (expected 5)\n";
    std::cout << numTrees(1) << " (expected 1)\n";
    return 0;
}
