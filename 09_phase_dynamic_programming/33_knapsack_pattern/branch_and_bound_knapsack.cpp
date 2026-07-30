// Branch and Bound — 0/1 knapsack (fractional-upper-bound pruning)
#include <algorithm>
#include <iostream>
#include <vector>

struct Item {
    int weight;
    int value;
};

struct Node {
    int level;
    int profit;
    int weight;
    double bound;
};

double fractionalBound(const Node& u, int n, int W, const std::vector<Item>& items) {
    if (u.weight >= W) return 0;
    double profit = u.profit;
    int totWeight = u.weight;
    int j = u.level + 1;
    while (j < n && totWeight + items[static_cast<size_t>(j)].weight <= W) {
        totWeight += items[static_cast<size_t>(j)].weight;
        profit += items[static_cast<size_t>(j)].value;
        ++j;
    }
    if (j < n) {
        profit += (W - totWeight) *
                  (static_cast<double>(items[static_cast<size_t>(j)].value) /
                   items[static_cast<size_t>(j)].weight);
    }
    return profit;
}

int knapsackBranchAndBound(int W, std::vector<Item> items) {
    const int n = static_cast<int>(items.size());
    std::sort(items.begin(), items.end(), [](const Item& a, const Item& b) {
        return static_cast<double>(a.value) / a.weight > static_cast<double>(b.value) / b.weight;
    });

    std::vector<Node> stack;
    Node u{-1, 0, 0, 0}, v{};
    u.bound = fractionalBound(u, n, W, items);
    stack.push_back(u);
    int maxProfit = 0;

    while (!stack.empty()) {
        u = stack.back();
        stack.pop_back();
        if (u.level == n - 1 || u.bound <= maxProfit) continue;

        // Include next item
        v.level = u.level + 1;
        v.weight = u.weight + items[static_cast<size_t>(v.level)].weight;
        v.profit = u.profit + items[static_cast<size_t>(v.level)].value;
        if (v.weight <= W && v.profit > maxProfit) maxProfit = v.profit;
        v.bound = fractionalBound(v, n, W, items);
        if (v.bound > maxProfit) stack.push_back(v);

        // Exclude next item
        v.weight = u.weight;
        v.profit = u.profit;
        v.bound = fractionalBound(v, n, W, items);
        if (v.bound > maxProfit) stack.push_back(v);
    }
    return maxProfit;
}

int main() {
    int W = 50;
    std::vector<Item> items = {{10, 60}, {20, 100}, {30, 120}};
    std::cout << "Max knapsack profit: " << knapsackBranchAndBound(W, items) << "\n"; // 220
    return 0;
}
