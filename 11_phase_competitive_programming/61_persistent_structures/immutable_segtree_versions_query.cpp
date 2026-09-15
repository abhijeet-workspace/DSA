// Immutable segtree versions — range sum on historical roots
#include <iostream>
#include <vector>

struct Node {
    int L = -1, R = -1;
    long long sum = 0;
};
std::vector<Node> T;
int neo(Node x = {}) {
    T.push_back(x);
    return (int)T.size() - 1;
}

int build(int l, int r) {
    int v = neo();
    if (l == r)
        return v;
    int m = (l + r) / 2;
    T[v].L = build(l, m);
    T[v].R = build(m + 1, r);
    return v;
}

int upd(int prev, int l, int r, int idx, long long val) {
    int v = neo(T[prev]);
    if (l == r) {
        T[v].sum = val;
        return v;
    }
    int m = (l + r) / 2;
    if (idx <= m)
        T[v].L = upd(T[prev].L, l, m, idx, val);
    else
        T[v].R = upd(T[prev].R, m + 1, r, idx, val);
    T[v].sum = T[T[v].L].sum + T[T[v].R].sum;
    return v;
}

long long query(int v, int l, int r, int ql, int qr) {
    if (qr < l || r < ql)
        return 0;
    if (ql <= l && r <= qr)
        return T[v].sum;
    int m = (l + r) / 2;
    return query(T[v].L, l, m, ql, qr) + query(T[v].R, m + 1, r, ql, qr);
}

int main() {
    int n = 4;
    std::vector<int> root;
    root.push_back(build(0, n - 1));
    root.push_back(upd(root.back(), 0, n - 1, 1, 5));
    root.push_back(upd(root.back(), 0, n - 1, 2, 3));
    std::cout << "v1 sum[1..2]=" << query(root[1], 0, n - 1, 1, 2) << " (expected 5)\n";
    std::cout << "v2 sum[1..2]=" << query(root[2], 0, n - 1, 1, 2) << " (expected 8)\n";
    return 0;
}
