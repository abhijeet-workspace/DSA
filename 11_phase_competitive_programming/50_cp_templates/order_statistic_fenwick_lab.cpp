// Order-statistic via Fenwick — portable alternative to GNU pbds
// Support insert value (as rank) and query k-th smallest (1-based k)
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
    int sumPrefix(int i) const {
        int s = 0;
        for (; i > 0; i -= i & -i)
            s += bit[i];
        return s;
    }
    int kth(int k) const {
        int idx = 0;
        int mask = 1;
        while ((mask << 1) <= n)
            mask <<= 1;
        for (int d = mask; d; d >>= 1) {
            int next = idx + d;
            if (next <= n && bit[next] < k) {
                idx = next;
                k -= bit[next];
            }
        }
        return idx + 1;
    }
};

int main() {
    std::vector<int> vals = {40, 10, 30, 20};
    std::vector<int> sorted = vals;
    std::sort(sorted.begin(), sorted.end());
    sorted.erase(std::unique(sorted.begin(), sorted.end()), sorted.end());
    auto rank = [&](int x) {
        return int(std::lower_bound(sorted.begin(), sorted.end(), x) - sorted.begin()) + 1;
    };
    Fenwick fw(static_cast<int>(sorted.size()));
    for (int x : vals)
        fw.add(rank(x), 1);
    // 1st..4th smallest among multiset {10,20,30,40}
    std::vector<int> got;
    for (int k = 1; k <= 4; ++k)
        got.push_back(sorted[fw.kth(k) - 1]);
    const std::vector<int> exp = {10, 20, 30, 40};
    std::cout << "order:";
    for (int x : got)
        std::cout << " " << x;
    std::cout << "\n";
    const bool ok = (got == exp);
    std::cout << (ok ? "OK\n" : "FAIL\n");
    return ok ? 0 : 1;
}
