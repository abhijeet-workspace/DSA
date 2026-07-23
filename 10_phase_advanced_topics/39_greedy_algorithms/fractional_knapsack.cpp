// Fractional Knapsack — max value with capacity; fractions allowed
// Classic greedy (contrast 0/1 knapsack DP).
#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>

double fractionalKnapsack(std::vector<std::pair<int, int>> items, int capacity) {
    // sort by value/weight descending
    std::sort(items.begin(), items.end(), [](const auto& a, const auto& b) {
        return static_cast<double>(a.first) / a.second
             > static_cast<double>(b.first) / b.second;
    });
    double total = 0.0;
    for (auto [value, weight] : items) {
        if (capacity >= weight) {
            total += value;
            capacity -= weight;
        } else {
            total += static_cast<double>(value) * capacity / weight; // take fraction
            break;
        }
    }
    return total;
}

int main() {
    std::cout << fractionalKnapsack({{60, 10}, {100, 20}, {120, 30}}, 50)
              << " (expected 240)\n";
    return 0;
}
