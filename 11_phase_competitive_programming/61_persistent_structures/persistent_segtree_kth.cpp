// Persistent SegTree k-th in [L,R] — CP classic
// Prefix versions + walk difference tree for order statistic.
#include <algorithm>
#include <iostream>
#include <vector>

struct Node {
    int cnt = 0;
    int L = -1;
    int R = -1;
};

struct PST {
    std::vector<Node> t;
    int U;

    explicit PST(int U_) : U(U_) { t.push_back(Node()); }

    int neo(Node x = {}) {
        t.push_back(x);
        return static_cast<int>(t.size()) - 1;
    }

    int build(int l, int r) {
        const int v = neo();
        if (l == r) {
            return v;
        }
        const int m = (l + r) / 2;
        t[static_cast<size_t>(v)].L = build(l, m);
        t[static_cast<size_t>(v)].R = build(m + 1, r);
        return v;
    }

    int upd(int prev, int l, int r, int idx) {
        const int v = neo(t[static_cast<size_t>(prev)]);
        t[static_cast<size_t>(v)].cnt = t[static_cast<size_t>(prev)].cnt + 1;
        if (l != r) {
            const int m = (l + r) / 2;
            if (idx <= m) {
                t[static_cast<size_t>(v)].L =
                    upd(t[static_cast<size_t>(prev)].L, l, m, idx);
            } else {
                t[static_cast<size_t>(v)].R =
                    upd(t[static_cast<size_t>(prev)].R, m + 1, r, idx);
            }
        }
        return v;
    }

    int kth(int vl, int vr, int l, int r, int k) const {
        if (l == r) {
            return l;
        }
        const int m = (l + r) / 2;
        const int leftCnt = t[static_cast<size_t>(t[static_cast<size_t>(vr)].L)].cnt -
                            t[static_cast<size_t>(t[static_cast<size_t>(vl)].L)].cnt;
        if (k <= leftCnt) {
            return kth(t[static_cast<size_t>(vl)].L, t[static_cast<size_t>(vr)].L, l, m,
                       k);
        }
        return kth(t[static_cast<size_t>(vl)].R, t[static_cast<size_t>(vr)].R, m + 1, r,
                   k - leftCnt);
    }
};

int main() {
    const std::vector<int> a = {0, 3, 1, 4, 2}; // 1-based
    const std::vector<int> vals = {1, 2, 3, 4};
    auto rank = [&](int x) {
        return static_cast<int>(std::lower_bound(vals.begin(), vals.end(), x) -
                                vals.begin()) +
               1;
    };
    PST pst(4);
    std::vector<int> root(5);
    root[0] = pst.build(1, 4);
    for (int i = 1; i <= 4; ++i) {
        root[static_cast<size_t>(i)] =
            pst.upd(root[static_cast<size_t>(i - 1)], 1, 4, rank(a[static_cast<size_t>(i)]));
    }
    const int r = pst.kth(root[0], root[4], 1, 4, 2);
    std::cout << vals[static_cast<size_t>(r - 1)] << " (expected 2)\n";
    return 0;
}
