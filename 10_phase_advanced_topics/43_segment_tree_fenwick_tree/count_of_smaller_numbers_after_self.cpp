// Count of Smaller Numbers After Self —
// https://leetcode.com/problems/count-of-smaller-numbers-after-self/ Fenwick frequencies +
// coordinate compression, scan right→left.
#include <algorithm>
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

std::vector<int> countSmaller(std::vector<int> nums) {
    std::vector<int> sorted = nums;
    std::sort(sorted.begin(), sorted.end());
    sorted.erase(std::unique(sorted.begin(), sorted.end()), sorted.end());
    auto rank = [&](int x) {
        return static_cast<int>(std::lower_bound(sorted.begin(), sorted.end(), x) -
                                sorted.begin()) +
               1;
    };
    Fenwick fw(static_cast<int>(sorted.size()));
    std::vector<int> ans(nums.size());
    for (int i = static_cast<int>(nums.size()) - 1; i >= 0; --i) {
        int r = rank(nums[static_cast<size_t>(i)]);
        ans[static_cast<size_t>(i)] = fw.sum(r - 1);
        fw.add(r, 1);
    }
    return ans;
}

int main() {
    for (int x : countSmaller({5, 2, 6, 1}))
        std::cout << x << " ";
    std::cout << "(expected 2 1 1 0)\n";
    return 0;
}
