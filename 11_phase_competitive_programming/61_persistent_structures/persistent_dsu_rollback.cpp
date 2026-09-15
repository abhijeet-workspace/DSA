// Rollback DSU — time-travel via undo stack
#include <iostream>
#include <utility>
#include <vector>

struct RollbackDSU {
    std::vector<int> p, sz;
    std::vector<std::pair<int, int>> hist; // (node, old_parent_or_-size)

    explicit RollbackDSU(int n) : p(n), sz(n, 1) {
        for (int i = 0; i < n; ++i)
            p[i] = i;
    }
    int find(int x) {
        while (x != p[x])
            x = p[x];
        return x;
    }
    int snapshot() const { return (int)hist.size(); }
    void rollback(int snap) {
        while ((int)hist.size() > snap) {
            auto [x, old] = hist.back();
            hist.pop_back();
            if (old < 0)
                sz[x] = -old;
            else
                p[x] = old;
        }
    }
    bool unite(int a, int b) {
        a = find(a);
        b = find(b);
        if (a == b)
            return false;
        if (sz[a] < sz[b])
            std::swap(a, b);
        hist.push_back({b, p[b]});
        hist.push_back({a, -sz[a]});
        p[b] = a;
        sz[a] += sz[b];
        return true;
    }
    bool same(int a, int b) { return find(a) == find(b); }
};

int main() {
    RollbackDSU d(4);
    d.unite(1, 2);
    int snap = d.snapshot();
    d.unite(2, 3);
    std::cout << std::boolalpha;
    std::cout << "before rb same(1,3)=" << d.same(1, 3) << " (expected true)\n";
    d.rollback(snap);
    std::cout << "after rb same(1,3)=" << d.same(1, 3) << " (expected false)\n";
    std::cout << "after rb same(1,2)=" << d.same(1, 2) << " (expected true)\n";
    return 0;
}
