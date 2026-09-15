// K-th between versions — chairman tree range order statistic
#include <algorithm>
#include <iostream>
#include <vector>

struct Node {
    int L = -1, R = -1, cnt = 0;
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
int upd(int prev, int l, int r, int idx) {
    int v = neo(T[prev]);
    T[v].cnt = T[prev].cnt + 1;
    if (l != r) {
        int m = (l + r) / 2;
        if (idx <= m)
            T[v].L = upd(T[prev].L, l, m, idx);
        else
            T[v].R = upd(T[prev].R, m + 1, r, idx);
    }
    return v;
}
int kth(int vl, int vr, int l, int r, int k) {
    if (l == r)
        return l;
    int m = (l + r) / 2;
    int left = T[T[vr].L].cnt - T[T[vl].L].cnt;
    if (k <= left)
        return kth(T[vl].L, T[vr].L, l, m, k);
    return kth(T[vl].R, T[vr].R, m + 1, r, k - left);
}

int main() {
    std::vector<int> a = {0, 1, 5, 2, 6, 3, 7, 4}; // 1-based
    int n = 7;
    std::vector<int> vals(a.begin() + 1, a.end());
    std::sort(vals.begin(), vals.end());
    vals.erase(std::unique(vals.begin(), vals.end()), vals.end());
    auto rank = [&](int x) {
        return (int)(std::lower_bound(vals.begin(), vals.end(), x) - vals.begin());
    };
    int U = (int)vals.size() - 1;
    std::vector<int> root(n + 1);
    root[0] = build(0, U);
    for (int i = 1; i <= n; ++i)
        root[i] = upd(root[i - 1], 0, U, rank(a[i]));
    int L = 2, R = 5, k = 3;
    int idx = kth(root[L - 1], root[R], 0, U, k);
    std::cout << "kth=" << vals[idx] << " (expected 5)\n";
    return 0;
}
