// Best Time to Buy and Sell Stock — https://leetcode.com/problems/best-time-to-buy-and-sell-stock/
// One buy and one sell; maximize profit (sell after buy). Return 0 if none.
#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

int maxProfit(const std::vector<int>& prices) {
    int minPrice = INT_MAX; // cheapest so far
    int best = 0; // max profit so far
    for (int p : prices) { // one day at a time
        minPrice = std::min(minPrice, p); // update buy candidate
        best = std::max(best, p - minPrice); // sell today vs best
    }
    return best;
}

int main() {
    std::cout << maxProfit({7, 1, 5, 3, 6, 4}) << " (expected 5)\n"
              << maxProfit({7, 6, 4, 3, 1}) << " (expected 0)\n";
    return 0;
}
