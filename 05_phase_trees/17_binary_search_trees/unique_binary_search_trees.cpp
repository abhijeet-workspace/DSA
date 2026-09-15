// Unique Binary Search Trees — https://leetcode.com/problems/unique-binary-search-trees/
#include <iostream>
#include <vector>

int numTrees(int n) {
    std::vector<long long> dp(n + 1, 0);
    dp[0] = 1;
    for (int k = 1; k <= n; ++k) {
        for (int i = 0; i < k; ++i) {
            dp[k] += dp[i] * dp[k - 1 - i];
        }
    }
    return static_cast<int>(dp[n]);
}

int main() {
    std::cout << numTrees(3) << " (expected 5)\n";
    std::cout << numTrees(1) << " (expected 1)\n";
    return 0;
}
