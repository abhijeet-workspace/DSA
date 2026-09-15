#include <algorithm>
#include <iostream>
#include <vector>
struct Seg {
    int n;
    std::vector<int> t;
    Seg(int n) : n(n), t(4 * n, 0) {}
    void add(int v, int tl, int tr, int pos, int delta) {
        if (tl == tr) {
            t[v] += delta;
            return;
        }
        int tm = (tl + tr) / 2;
        if (pos <= tm)
            add(2 * v, tl, tm, pos, delta);
        else
            add(2 * v + 1, tm + 1, tr, pos, delta);
        t[v] = t[2 * v] + t[2 * v + 1];
    }
    int query(int v, int tl, int tr, int l, int r) {
        if (l > r)
            return 0;
        if (l == tl && r == tr)
            return t[v];
        int tm = (tl + tr) / 2;
        return query(2 * v, tl, tm, l, std::min(r, tm)) +
               query(2 * v + 1, tm + 1, tr, std::max(l, tm + 1), r);
    }
};
int main() {
    std::vector<int> a = {100, 1, 100, 50};
    std::vector<int> vals = a;
    std::sort(vals.begin(), vals.end());
    vals.erase(std::unique(vals.begin(), vals.end()), vals.end());
    auto rank0 = [&](int x) {
        return int(std::lower_bound(vals.begin(), vals.end(), x) - vals.begin());
    };
    Seg st((int)vals.size());
    for (int x : a)
        st.add(1, 0, st.n - 1, rank0(x), 1);
    int L = rank0(50), R = rank0(100);
    int q = st.query(1, 0, st.n - 1, L, R); // {50,100,100} → 3
    std::cout << "count=" << q << " expected=3\n" << (q == 3 ? "OK\n" : "FAIL\n");
    return q == 3 ? 0 : 1;
}
