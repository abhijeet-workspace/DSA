// Fruit Into Baskets — LC 904
// Longest subarray with at most 2 distinct values (sliding window + freq map).
#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>

int totalFruit(const std::vector<int>& fruits) {
    std::unordered_map<int, int> count;
    int left = 0;
    int best = 0;
    for (int right = 0; right < static_cast<int>(fruits.size()); ++right) {
        ++count[fruits[static_cast<size_t>(right)]];
        while (static_cast<int>(count.size()) > 2) {
            int leftFruit = fruits[static_cast<size_t>(left)];
            if (--count[leftFruit] == 0)
                count.erase(leftFruit);
            ++left;
        }
        best = std::max(best, right - left + 1);
    }
    return best;
}

int main() {
    std::cout << totalFruit({1, 2, 1}) << " (expected 3)\n";
    std::cout << totalFruit({0, 1, 2, 2}) << " (expected 3)\n";
    std::cout << totalFruit({1, 2, 3, 2, 2}) << " (expected 4)\n";
    return 0;
}
