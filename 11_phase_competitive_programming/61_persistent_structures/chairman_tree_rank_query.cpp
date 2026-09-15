// Chairman tree rank query — count <= x in [L,R]
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
int countLeq(int vl, int vr, int l, int r, int idx) {
    if (idx < l)
        return 0;
    if (r <= idx)
        return T[vr].cnt - T[vl].cnt;
    int m = (l + r) / 2;
    return countLeq(T[vl].L, T[vr].L, l, m, idx) + countLeq(T[vl].R, T[vr].R, m + 1, r, idx);
}

int main() {
    std::vector<int> a = {0, 2, 1, 3, 1};
    int n = 4;
    std::vector<int> vals = {1, 2, 3};
    auto rankv = [&](int x) {
        return (int)(std::upper_bound(vals.begin(), vals.end(), x) - vals.begin()) - 1;
    };
    int U = (int)vals.size() - 1;
    std::vector<int> root(n + 1);
    root[0] = build(0, U);
    for (int i = 1; i <= n; ++i) {
        int idx = (int)(std::lower_bound(vals.begin(), vals.end(), a[i]) - vals.begin());
        root[i] = upd(root[i - 1], 0, U, idx);
    }
    int ans = countLeq(root[0], root[4], 0, U, rankv(1));
    std::cout << "count<=" << 1 << " -> " << ans << " (expected 2)\n";
    return 0;
}
