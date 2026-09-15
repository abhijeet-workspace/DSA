// Closest Dessert Cost — https://leetcode.com/problems/closest-dessert-cost/
#include <cmath>
#include <functional>
#include <iostream>
#include <vector>

int closestCost(std::vector<int>& baseCosts, std::vector<int>& toppingCosts, int target) {
    int best = baseCosts[0];
    auto better = [&](int cost) {
        const int d = std::abs(cost - target), bd = std::abs(best - target);
        if (d < bd || (d == bd && cost < best)) best = cost;
    };
    std::function<void(int, int)> dfs = [&](int i, int sum) {
        if (i == static_cast<int>(toppingCosts.size())) {
            better(sum);
            return;
        }
        for (int c = 0; c <= 2; ++c) {
            dfs(i + 1, sum + c * toppingCosts[static_cast<size_t>(i)]);
        }
    };
    for (int b : baseCosts) dfs(0, b);
    return best;
}

int main() {
    std::vector<int> base{1, 7}, top{3, 4};
    std::cout << closestCost(base, top, 10) << " (expected 10)\n";
    return 0;
}
