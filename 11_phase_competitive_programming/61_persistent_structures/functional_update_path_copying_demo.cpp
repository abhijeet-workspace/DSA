// Functional update path-copying demo
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
    if (l == r)
        return neo({-1, -1, a[l]});
    int m = (l + r) / 2;
    int v = neo();
    T[v].L = build(a, l, m);
    T[v].R = build(a, m + 1, r);
    return v;
}

int setLeaf(int v, int l, int r, int idx, int val) {
    if (l == r)
        return neo({-1, -1, val});
    int m = (l + r) / 2;
    int nv = neo(T[v]);
    if (idx <= m)
        T[nv].L = setLeaf(T[v].L, l, m, idx, val);
    else
        T[nv].R = setLeaf(T[v].R, m + 1, r, idx, val);
    return nv;
}

int getLeaf(int v, int l, int r, int idx) {
    if (l == r)
        return T[v].val;
    int m = (l + r) / 2;
    if (idx <= m)
        return getLeaf(T[v].L, l, m, idx);
    return getLeaf(T[v].R, m + 1, r, idx);
}

int main() {
    std::vector<int> a = {1, 2, 3, 4};
    int n = 4;
    int old = build(a, 0, n - 1);
    int neu = setLeaf(old, 0, n - 1, 0, 9);
    std::cout << "old0=" << getLeaf(old, 0, n - 1, 0) << " new0=" << getLeaf(neu, 0, n - 1, 0)
              << " (expected 1 9)\n";
    return 0;
}
