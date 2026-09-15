// Persistent array via path-copying segtree
#include <iostream>
#include <vector>

struct Node {
    int L = -1, R = -1;
    int val = 0;
};
std::vector<Node> T;

int neo(Node x = {}) {
    T.push_back(x);
    return (int)T.size() - 1;
}

int build(const std::vector<int>& a, int l, int r) {
    int v = neo();
    if (l == r) {
        T[v].val = a[l];
        return v;
    }
    int m = (l + r) / 2;
    T[v].L = build(a, l, m);
    T[v].R = build(a, m + 1, r);
    return v;
}

int upd(int prev, int l, int r, int idx, int val) {
    int v = neo(T[prev]);
    if (l == r) {
        T[v].val = val;
        return v;
    }
    int m = (l + r) / 2;
    if (idx <= m)
        T[v].L = upd(T[prev].L, l, m, idx, val);
    else
        T[v].R = upd(T[prev].R, m + 1, r, idx, val);
    return v;
}

int get(int v, int l, int r, int idx) {
    if (l == r)
        return T[v].val;
    int m = (l + r) / 2;
    if (idx <= m)
        return get(T[v].L, l, m, idx);
    return get(T[v].R, m + 1, r, idx);
}

int main() {
    std::vector<int> a = {1, 2, 3};
    int n = (int)a.size();
    int v0 = build(a, 0, n - 1);
    int v1 = upd(v0, 0, n - 1, 0, 9);
    std::cout << "v0[0]=" << get(v0, 0, n - 1, 0) << " (expected 1)\n";
    std::cout << "v1[0]=" << get(v1, 0, n - 1, 0) << " (expected 9)\n";
    std::cout << "v1[2]=" << get(v1, 0, n - 1, 2) << " (expected 3)\n";
    return 0;
}
