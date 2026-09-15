// Falling Squares — https://leetcode.com/problems/falling-squares/
// Coord-compress + lazy segtree range max assign / query.
#include <algorithm>
#include <iostream>
#include <vector>

struct Seg {
    int n;
    std::vector<int> t, lazy;
    explicit Seg(int n) : n(n), t(4 * n), lazy(4 * n, -1) {}
    void apply(int node, int v) {
        t[node] = v;
        lazy[node] = v;
    }
    void push(int node) {
        if (lazy[node] == -1) return;
        apply(2 * node, lazy[node]);
        apply(2 * node + 1, lazy[node]);
        lazy[node] = -1;
    }
    void update(int node, int s, int e, int l, int r, int v) {
        if (r < s || e < l) return;
        if (l <= s && e <= r) {
            apply(node, v);
            return;
        }
        push(node);
        int m = (s + e) / 2;
        update(2 * node, s, m, l, r, v);
        update(2 * node + 1, m + 1, e, l, r, v);
        t[node] = std::max(t[2 * node], t[2 * node + 1]);
    }
    int query(int node, int s, int e, int l, int r) {
        if (r < s || e < l) return 0;
        if (l <= s && e <= r) return t[node];
        push(node);
        int m = (s + e) / 2;
        return std::max(query(2 * node, s, m, l, r), query(2 * node + 1, m + 1, e, l, r));
    }
    void update(int l, int r, int v) { update(1, 0, n - 1, l, r, v); }
    int query(int l, int r) { return query(1, 0, n - 1, l, r); }
};

std::vector<int> fallingSquares(const std::vector<std::vector<int>>& positions) {
    std::vector<int> xs;
    for (auto& p : positions) {
        xs.push_back(p[0]);
        xs.push_back(p[0] + p[1]);
    }
    std::sort(xs.begin(), xs.end());
    xs.erase(std::unique(xs.begin(), xs.end()), xs.end());
    auto id = [&](int x) { return static_cast<int>(std::lower_bound(xs.begin(), xs.end(), x) - xs.begin()); };
    Seg seg(static_cast<int>(xs.size()));
    std::vector<int> ans;
    int best = 0;
    for (auto& p : positions) {
        int L = id(p[0]), R = id(p[0] + p[1]) - 1;
        int h = seg.query(L, R) + p[1];
        seg.update(L, R, h);
        best = std::max(best, h);
        ans.push_back(best);
    }
    return ans;
}

int main() {
    for (int h : fallingSquares({{1, 2}, {2, 3}, {6, 1}})) std::cout << h << " ";
    std::cout << "(expected 2 5 5)\n";
    return 0;
}
