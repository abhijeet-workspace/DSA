// DSU (Union-Find) template — connected components on edges
#include <iostream>
#include <numeric>
#include <vector>

struct DSU {
    std::vector<int> p, sz;
    explicit DSU(int n) : p(n), sz(n, 1) { std::iota(p.begin(), p.end(), 0); }
    int find(int x) { return p[x] == x ? x : p[x] = find(p[x]); }
    bool unite(int a, int b) {
        a = find(a);
        b = find(b);
        if (a == b)
            return false;
        if (sz[a] < sz[b])
            std::swap(a, b);
        p[b] = a;
        sz[a] += sz[b];
        return true;
    }
};

int main() {
    DSU d(5);
    d.unite(0, 1);
    d.unite(1, 2);
    d.unite(3, 4);
    const bool same = d.find(0) == d.find(2);
    const bool diff = d.find(0) != d.find(3);
    std::cout << "same02=" << same << " diff03=" << diff << "\n";
    std::cout << ((same && diff) ? "OK\n" : "FAIL\n");
    return (same && diff) ? 0 : 1;
}
