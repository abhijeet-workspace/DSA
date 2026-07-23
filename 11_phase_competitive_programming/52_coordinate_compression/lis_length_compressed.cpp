// LIS length — Fenwick max on compressed ranks
// For rank r: best = 1 + max LIS among ranks < r; update Fenwick at r.
#include <algorithm>
#include <iostream>
#include <vector>

class FenwickMax {
public:
    explicit FenwickMax(int n) : bit(static_cast<size_t>(n) + 1, 0) {}

    void update(int i, int val) {
        for (; i < static_cast<int>(bit.size()); i += i & -i) {
            bit[static_cast<size_t>(i)] = std::max(bit[static_cast<size_t>(i)], val);
        }
    }

    int query(int i) const {
        int res = 0;
        for (; i > 0; i -= i & -i) {
            res = std::max(res, bit[static_cast<size_t>(i)]);
        }
        return res;
    }

private:
    std::vector<int> bit;
};

int lisLength(std::vector<int> a) {
    if (a.empty()) {
        return 0;
    }
    std::vector<int> vals = a;
    std::sort(vals.begin(), vals.end());
    vals.erase(std::unique(vals.begin(), vals.end()), vals.end());
    for (int& x : a) {
        x = static_cast<int>(std::lower_bound(vals.begin(), vals.end(), x) - vals.begin()) + 1;
    }

    FenwickMax fw(static_cast<int>(vals.size()));
    int best = 0;
    for (int r : a) {
        const int len = fw.query(r - 1) + 1;
        fw.update(r, len);
        best = std::max(best, len);
    }
    return best;
}

int main() {
    const int a = lisLength({10, 9, 2, 5, 3, 7, 101, 18});
    const int b = lisLength({0, 1, 0, 3, 2, 3});
    const int c = lisLength({7, 7, 7, 7});
    const int d = lisLength({3, 1, 2, 4});

    const bool ok = (a == 4 && b == 4 && c == 1 && d == 3);
    std::cout << "[10,9,2,5,3,7,101,18] LIS=" << a << " (expected 4)\n";
    std::cout << "[0,1,0,3,2,3] LIS=" << b << " (expected 4)\n";
    std::cout << "[7,7,7,7] LIS=" << c << " (expected 1)\n";
    std::cout << "[3,1,2,4] LIS=" << d << " (expected 3)\n";
    std::cout << (ok ? "OK\n" : "FAIL\n");
    return ok ? 0 : 1;
}
