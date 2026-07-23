// Min Cost Climbing Stairs — https://leetcode.com/problems/min-cost-climbing-stairs/
// Pay cost[i] to leave i; start at 0 or 1; reach top with min total cost.
#include <iostream>
#include <vector>
#include <algorithm>

int minCostClimbingStairs(const std::vector<int>& cost) {
    int a = 0; // min cost to reach i-2
    int b = 0; // min cost to reach i-1
    for (int i = 2; i <= static_cast<int>(cost.size()); ++i) {
        const int c = std::min(a + cost[static_cast<size_t>(i - 2)],
                               b + cost[static_cast<size_t>(i - 1)]);
        a = b;
        b = c;
    }
    return b; // top is one past last stair
}

int main() {
    const std::vector<int> c = {10, 15, 20};
    std::cout << minCostClimbingStairs(c) << " (expected 15)\n";
    return 0;
}
