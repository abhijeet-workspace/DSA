// Richest Customer Wealth — LC 1672
// Max over customers of sum(accounts[i]).
#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>

int maximumWealth(const std::vector<std::vector<int>>& accounts) {
    int best = 0;
    for (const auto& row : accounts) {
        best = std::max(best, std::accumulate(row.begin(), row.end(), 0));
    }
    return best;
}

int main() {
    std::cout << maximumWealth({{1, 2, 3}, {3, 2, 1}}) << " (expected 6)\n"
              << maximumWealth({{1, 5}, {7, 3}, {3, 5}}) << " (expected 10)\n";
    return 0;
}
