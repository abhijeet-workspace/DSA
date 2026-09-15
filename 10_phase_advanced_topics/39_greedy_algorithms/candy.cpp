// Candy — https://leetcode.com/problems/candy/
// Two-pass: left-to-right then right-to-left peaks; sum candies.
#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>

int candy(const std::vector<int>& ratings) {
    const int n = static_cast<int>(ratings.size());
    std::vector<int> candies(static_cast<size_t>(n), 1);
    for (int i = 1; i < n; ++i) {
        if (ratings[static_cast<size_t>(i)] > ratings[static_cast<size_t>(i - 1)]) {
            candies[static_cast<size_t>(i)] = candies[static_cast<size_t>(i - 1)] + 1;
        }
    }
    for (int i = n - 2; i >= 0; --i) {
        if (ratings[static_cast<size_t>(i)] > ratings[static_cast<size_t>(i + 1)]) {
            candies[static_cast<size_t>(i)] =
                std::max(candies[static_cast<size_t>(i)], candies[static_cast<size_t>(i + 1)] + 1);
        }
    }
    return std::accumulate(candies.begin(), candies.end(), 0);
}

int main() {
    std::cout << candy({1, 0, 2}) << " (expected 5)\n"
              << candy({1, 2, 2}) << " (expected 4)\n";
    return 0;
}
