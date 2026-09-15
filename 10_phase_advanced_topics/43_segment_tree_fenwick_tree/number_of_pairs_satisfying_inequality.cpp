// Number of Pairs Satisfying Inequality — https://leetcode.com/problems/number-of-pairs-satisfying-inequality/
// a[i]=nums1[i]-nums2[i]; count i<j with a[i] <= a[j]+diff via Fenwick.
#include <algorithm>
#include <iostream>
#include <vector>

struct Fenwick {
    int n;
    std::vector<int> bit;
    explicit Fenwick(int n) : n(n), bit(n + 1, 0) {}
    void add(int i, int v) {
        for (; i <= n; i += i & -i) bit[i] += v;
    }
    int sum(int i) const {
        int s = 0;
        for (; i > 0; i -= i & -i) s += bit[i];
        return s;
    }
};

long long numberOfPairs(const std::vector<int>& nums1, const std::vector<int>& nums2, int diff) {
    int n = static_cast<int>(nums1.size());
    std::vector<long long> a(n);
    for (int i = 0; i < n; ++i) a[i] = 1LL * nums1[i] - nums2[i];
    std::vector<long long> keys = a;
    for (auto v : a) keys.push_back(v + diff);
    std::sort(keys.begin(), keys.end());
    keys.erase(std::unique(keys.begin(), keys.end()), keys.end());
    auto id = [&](long long x) {
        return static_cast<int>(std::lower_bound(keys.begin(), keys.end(), x) - keys.begin()) + 1;
    };
    Fenwick fw(static_cast<int>(keys.size()));
    long long ans = 0;
    for (int j = 0; j < n; ++j) {
        ans += fw.sum(id(a[j] + diff));
        fw.add(id(a[j]), 1);
    }
    return ans;
}

int main() {
    std::cout << numberOfPairs({3, 2, 5}, {2, 2, 1}, 1) << " (expected 3)\n"
              << numberOfPairs({3, -1}, {-2, 2}, -1) << " (expected 0)\n";
    return 0;
}
