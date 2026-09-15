// Count Inversions — classic Fenwick / CSES-style
// Right→left: query how many already-seen (to the right) are smaller.
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

long long countInversions(std::vector<int> a) {
    std::vector<int> s = a;
    std::sort(s.begin(), s.end());
    s.erase(std::unique(s.begin(), s.end()), s.end());
    auto rank = [&](int x) {
        return static_cast<int>(std::lower_bound(s.begin(), s.end(), x) - s.begin()) + 1;
    };
    Fenwick fw(static_cast<int>(s.size()));
    long long inv = 0;
    for (int i = static_cast<int>(a.size()) - 1; i >= 0; --i) {
        int r = rank(a[i]);
        inv += fw.sum(r - 1);
        fw.add(r, 1);
    }
    return inv;
}

int main() {
    std::cout << countInversions({2, 3, 8, 6, 1}) << " (expected 5)\n"
              << countInversions({1, 2, 3}) << " (expected 0)\n"
              << countInversions({3, 2, 1}) << " (expected 3)\n";
    return 0;
}
