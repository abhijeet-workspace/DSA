// Tallest Billboard — https://leetcode.com/problems/tallest-billboard/
#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <unordered_map>
#include <vector>

int tallestBillboard(std::vector<int>& rods) {
    std::unordered_map<int, int> dp{{0, 0}};
    for (int r : rods) {
        auto cur = dp;
        for (auto [diff, taller] : cur) {
            dp[diff + r] = std::max(dp[diff + r], taller + r);
            const int nd = std::abs(diff - r);
            const int nt = taller + std::max(0, r - diff);
            dp[nd] = std::max(dp.count(nd) ? dp[nd] : 0, nt);
        }
    }
    return dp[0];
}

int main() {
    std::vector<int> rods{1, 2, 3, 6};
    std::cout << tallestBillboard(rods) << " (expected 6)\n";
    return 0;
}
