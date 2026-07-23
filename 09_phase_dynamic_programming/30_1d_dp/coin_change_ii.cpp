// Coin Change II — https://leetcode.com/problems/coin-change-ii/
// Number of combinations to make amount; unlimited each coin.
#include <iostream>
#include <vector>

int change(int amount, const std::vector<int>& coins) {
    std::vector<int> dp(static_cast<size_t>(amount) + 1, 0);
    dp[0] = 1; // one way to make 0
    for (int c : coins) { // outer coins → combinations not permutations
        for (int a = c; a <= amount; ++a) {
            dp[static_cast<size_t>(a)] += dp[static_cast<size_t>(a - c)];
        }
    }
    return dp[static_cast<size_t>(amount)];
}

int main() {
    const std::vector<int> c = {1, 2, 5};
    std::cout << change(5, c) << " (expected 4)\n";
    return 0;
}
