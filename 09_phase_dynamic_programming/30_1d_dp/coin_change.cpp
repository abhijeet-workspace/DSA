// Coin Change — https://leetcode.com/problems/coin-change/
// Fewest coins to make amount; unlimited supply; -1 if impossible.
#include <iostream>
#include <vector>
#include <algorithm>

int coinChange(const std::vector<int>& coins, int amount) {
    std::vector<int> dp(static_cast<size_t>(amount) + 1, amount + 1); // sentinel
    dp[0] = 0;
    for (int x = 1; x <= amount; ++x) {
        for (int c : coins) {
            if (x - c >= 0) {
                dp[static_cast<size_t>(x)] = std::min(
                    dp[static_cast<size_t>(x)],
                    dp[static_cast<size_t>(x - c)] + 1);
            }
        }
    }
    return dp[static_cast<size_t>(amount)] > amount
               ? -1
               : dp[static_cast<size_t>(amount)];
}

int main() {
    std::cout << coinChange({1, 2, 5}, 11) << " (expected 3)\n"
              << coinChange({2}, 3) << " (expected -1)\n"
              << coinChange({1}, 0) << " (expected 0)\n";
    return 0;
}
