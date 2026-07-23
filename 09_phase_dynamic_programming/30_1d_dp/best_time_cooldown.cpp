// Best Time with Cooldown — https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-cooldown/
// Max profit; one share; cooldown day after each sell.
#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

int maxProfit(const std::vector<int>& prices) {
    int hold = INT_MIN / 2; // holding a share
    int sold = 0;           // sold today
    int rest = 0;           // free to buy (cooldown done)
    for (int p : prices) {
        const int prev_sold = sold;
        sold = hold + p;                      // sell today
        hold = std::max(hold, rest - p);      // buy or keep
        rest = std::max(rest, prev_sold);     // idle or enter cooldown
    }
    return std::max(sold, rest);
}

int main() {
    const std::vector<int> p = {1, 2, 3, 0, 2};
    std::cout << maxProfit(p) << " (expected 3)\n";
    return 0;
}
