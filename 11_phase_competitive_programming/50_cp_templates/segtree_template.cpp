// Segment tree template — range sum, point update
#include <iostream>
#include <vector>

struct SegTree {
    int n;
    std::vector<long long> t;
    explicit SegTree(const std::vector<long long>& a) : n(static_cast<int>(a.size())), t(4 * n, 0) {
        build(1, 0, n - 1, a);
    }
    void build(int v, int tl, int tr, const std::vector<long long>& a) {
        if (tl == tr) {
            t[v] = a[tl];
            return;
        }
        int tm = (tl + tr) / 2;
        build(2 * v, tl, tm, a);
        build(2 * v + 1, tm + 1, tr, a);
        t[v] = t[2 * v] + t[2 * v + 1];
    }
    void update(int v, int tl, int tr, int pos, long long val) {
        if (tl == tr) {
            t[v] = val;
            return;
        }
        int tm = (tl + tr) / 2;
        if (pos <= tm)
            update(2 * v, tl, tm, pos, val);
        else
            update(2 * v + 1, tm + 1, tr, pos, val);
        t[v] = t[2 * v] + t[2 * v + 1];
    }
    long long query(int v, int tl, int tr, int l, int r) {
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
    std::vector<long long> a = {1, 2, 3, 4, 5};
    SegTree st(a);
    long long q = st.query(1, 0, st.n - 1, 1, 3);  // 2+3+4
    st.update(1, 0, st.n - 1, 2, 10);              // a[2]=10
    long long q2 = st.query(1, 0, st.n - 1, 1, 3); // 2+10+4=16
    std::cout << "q=" << q << " q2=" << q2 << "\n";
    const bool ok = (q == 9 && q2 == 16);
    std::cout << (ok ? "OK\n" : "FAIL\n");
    return ok ? 0 : 1;
}
