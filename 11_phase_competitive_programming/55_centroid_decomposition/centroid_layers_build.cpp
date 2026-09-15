// Centroid Layers Build — teaching
#include <iostream>
#include <vector>

struct CentroidLayers {
    int n;
    std::vector<std::vector<int>> g;
    std::vector<int> sz, dead, layer;
    CentroidLayers(int n_) : n(n_), g(n_ + 1), sz(n_ + 1), dead(n_ + 1, 0), layer(n_ + 1, -1) {}
    void addEdge(int u, int v) {
        g[static_cast<size_t>(u)].push_back(v);
        g[static_cast<size_t>(v)].push_back(u);
    }
    int dfsSize(int v, int p) {
        sz[static_cast<size_t>(v)] = 1;
        for (int to : g[static_cast<size_t>(v)])
            if (to != p && !dead[static_cast<size_t>(to)])
                sz[static_cast<size_t>(v)] += dfsSize(to, v);
        return sz[static_cast<size_t>(v)];
    }
    int findCentroid(int v, int p, int comp) {
        for (int to : g[static_cast<size_t>(v)])
            if (to != p && !dead[static_cast<size_t>(to)] && sz[static_cast<size_t>(to)] > comp / 2)
                return findCentroid(to, v, comp);
        return v;
    }
    void build(int entry, int dep) {
        int comp = dfsSize(entry, -1);
        int c = findCentroid(entry, -1, comp);
        layer[static_cast<size_t>(c)] = dep;
        dead[static_cast<size_t>(c)] = 1;
        for (int to : g[static_cast<size_t>(c)])
            if (!dead[static_cast<size_t>(to)])
                build(to, dep + 1);
    }
};

int main() {
    CentroidLayers t(5);
    for (int i = 1; i < 5; ++i)
        t.addEdge(i, i + 1);
    t.build(1, 0);
    bool ok = true;
    for (int i = 1; i <= 5; ++i)
        if (t.layer[static_cast<size_t>(i)] < 0)
            ok = false;
    std::cout << (ok ? "all_assigned" : "fail") << " (expected all_assigned)\n";
    return 0;
}
