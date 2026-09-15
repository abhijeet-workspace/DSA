// Last Stone Weight II — https://leetcode.com/problems/last-stone-weight-ii/
#include <iostream>
#include <numeric>
#include <vector>

int lastStoneWeightII(std::vector<int>& stones) {
    const int total = std::accumulate(stones.begin(), stones.end(), 0);
    const int target = total / 2;
    std::vector<char> dp(static_cast<size_t>(target + 1), 0);
    dp[0] = 1;
    for (int s : stones) {
        for (int w = target; w >= s; --w) {
            if (dp[static_cast<size_t>(w - s)]) dp[static_cast<size_t>(w)] = 1;
        }
    }
    for (int w = target; w >= 0; --w) {
        if (dp[static_cast<size_t>(w)]) return total - 2 * w;
    }
    return total;
}

int main() {
    std::vector<int> stones{2, 7, 4, 1, 8, 1};
    std::cout << lastStoneWeightII(stones) << " (expected 1)\n";
    return 0;
}
