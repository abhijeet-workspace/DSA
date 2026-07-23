// Count inversions — Fenwick + coordinate compression
// Process L→R; before insert, add count of seen ranks strictly greater.
#include <algorithm>
#include <iostream>
#include <vector>

class Fenwick {
public:
    explicit Fenwick(int n) : bit(static_cast<size_t>(n) + 1, 0) {}

    void add(int i, int delta) {
        for (; i < static_cast<int>(bit.size()); i += i & -i) {
            bit[static_cast<size_t>(i)] += delta;
        }
    }

    int sumPrefix(int i) const {
        int s = 0;
        for (; i > 0; i -= i & -i) {
            s += bit[static_cast<size_t>(i)];
        }
        return s;
    }

private:
    std::vector<int> bit;
};

long long countInversions(std::vector<int> a) {
    std::vector<int> vals = a;
    std::sort(vals.begin(), vals.end());
    vals.erase(std::unique(vals.begin(), vals.end()), vals.end());
    for (int& x : a) {
        x = static_cast<int>(std::lower_bound(vals.begin(), vals.end(), x) - vals.begin()) + 1;
    }

    const int U = static_cast<int>(vals.size());
    Fenwick fw(U);
    long long inv = 0;
    int seen = 0;
    for (int r : a) {
        inv += seen - fw.sumPrefix(r); // ranks > r already seen
        fw.add(r, 1);
        ++seen;
    }
    return inv;
}

int main() {
    const long long ia = countInversions({3, 1, 2});
    const long long ib = countInversions({5, 4, 3, 2, 1});
    const long long ic = countInversions({1, 2, 3, 4});
    const long long id = countInversions({2, 2, 2});

    const bool ok = (ia == 2 && ib == 10 && ic == 0 && id == 0);
    std::cout << "[3,1,2] inversions=" << ia << " (expected 2)\n";
    std::cout << "[5,4,3,2,1] inversions=" << ib << " (expected 10)\n";
    std::cout << "[1,2,3,4] inversions=" << ic << " (expected 0)\n";
    std::cout << "[2,2,2] inversions=" << id << " (expected 0)\n";
    std::cout << (ok ? "OK\n" : "FAIL\n");
    return ok ? 0 : 1;
}
