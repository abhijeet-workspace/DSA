// Count Paths With XOR — CD teaching
#include <iostream>
#include <unordered_map>
#include <vector>

struct XorPaths {
    int n, X;
    std::vector<std::vector<std::pair<int, int>>> g;
    std::vector<int> sz, dead;
    long long ans = 0;
    XorPaths(int n_, int X_) : n(n_), X(X_), g(n_ + 1), sz(n_ + 1), dead(n_ + 1, 0) {}
    void addEdge(int u, int v, int w) {
        g[static_cast<size_t>(u)].push_back({v, w});
        g[static_cast<size_t>(v)].push_back({u, w});
    }
    int dfsSize(int v, int p) {
        sz[static_cast<size_t>(v)] = 1;
        for (auto [to, _] : g[static_cast<size_t>(v)])
            if (to != p && !dead[static_cast<size_t>(to)])
                sz[static_cast<size_t>(v)] += dfsSize(to, v);
        return sz[static_cast<size_t>(v)];
    }
    int findCentroid(int v, int p, int comp) {
        for (auto [to, _] : g[static_cast<size_t>(v)])
            if (to != p && !dead[static_cast<size_t>(to)] && sz[static_cast<size_t>(to)] > comp / 2)
                return findCentroid(to, v, comp);
        return v;
    }
    void collect(int v, int p, int xr, std::vector<int>& vals) {
        vals.push_back(xr);
        for (auto [to, w] : g[static_cast<size_t>(v)])
            if (to != p && !dead[static_cast<size_t>(to)])
                collect(to, v, xr ^ w, vals);
    }
    void at(int c) {
        std::unordered_map<int, int> freq;
        freq[0] = 1;
        for (auto [to, w] : g[static_cast<size_t>(c)]) {
            if (dead[static_cast<size_t>(to)])
                continue;
            std::vector<int> vals;
            collect(to, c, w, vals);
            for (int xr : vals)
                ans += freq[X ^ xr];
            for (int xr : vals)
                ++freq[xr];
        }
    }
    void build(int e) {
        int comp = dfsSize(e, -1);
        int c = findCentroid(e, -1, comp);
        at(c);
        dead[static_cast<size_t>(c)] = 1;
        for (auto [to, _] : g[static_cast<size_t>(c)])
            if (!dead[static_cast<size_t>(to)])
                build(to);
    }
    long long count() {
        ans = 0;
        build(1);
        return ans;
    }
};

int main() {
    XorPaths t(3, 3);
    t.addEdge(1, 2, 1);
    t.addEdge(2, 3, 2);
    std::cout << t.count() << " (expected 1)\n";
    return 0;
}
