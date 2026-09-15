// Create Sorted Array through Instructions —
// https://leetcode.com/problems/create-sorted-array-through-instructions/ Fenwick frequencies; cost
// = min(less, greater) per insert.
#include <iostream>
#include <vector>

struct Fenwick {
    int n;
    std::vector<int> bit;
    explicit Fenwick(int n) : n(n), bit(n + 1, 0) {}
    void add(int i, int v) {
        for (; i <= n; i += i & -i)
            bit[i] += v;
    }
    int sum(int i) const {
        int s = 0;
        for (; i > 0; i -= i & -i)
            s += bit[i];
        return s;
    }
};

int createSortedArray(const std::vector<int>& instructions) {
    const int MOD = 1'000'000'007;
    int mx = 0;
    for (int x : instructions)
        mx = std::max(mx, x);
    Fenwick fw(mx);
    long long cost = 0;
    for (int i = 0; i < static_cast<int>(instructions.size()); ++i) {
        int x = instructions[i];
        int less = fw.sum(x - 1);
        int greater = i - fw.sum(x);
        cost = (cost + std::min(less, greater)) % MOD;
        fw.add(x, 1);
    }
    return static_cast<int>(cost);
}

int main() {
    std::cout << createSortedArray({1, 5, 6, 2}) << " (expected 1)\n"
              << createSortedArray({1, 2, 3, 6, 5, 4}) << " (expected 3)\n";
    return 0;
}
