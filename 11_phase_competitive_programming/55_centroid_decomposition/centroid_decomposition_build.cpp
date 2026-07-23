// Centroid Decomposition Build — CP classic
// Recursively find centroids; build centroid tree with component sizes.
#include <iostream>
#include <vector>

struct CentroidDecomp {
    int n;
    std::vector<std::vector<int>> g;
    std::vector<int> sz, dead, cpar, compsize_at;
    std::vector<std::vector<int>> ctree;
    int root = -1;

    explicit CentroidDecomp(int n_)
        : n(n_),
          g(n_ + 1),
          sz(n_ + 1, 0),
          dead(n_ + 1, 0),
          cpar(n_ + 1, -1),
          compsize_at(n_ + 1, 0),
          ctree(n_ + 1) {}

    void addEdge(int u, int v) {
        g[static_cast<size_t>(u)].push_back(v);
        g[static_cast<size_t>(v)].push_back(u);
    }

    int dfsSize(int v, int p) {
        sz[static_cast<size_t>(v)] = 1;
        for (int to : g[static_cast<size_t>(v)]) {
            if (to == p || dead[static_cast<size_t>(to)]) continue;
            sz[static_cast<size_t>(v)] += dfsSize(to, v);
        }
        return sz[static_cast<size_t>(v)];
    }

    int findCentroid(int v, int p, int comp) {
        for (int to : g[static_cast<size_t>(v)]) {
            if (to == p || dead[static_cast<size_t>(to)]) continue;
            if (sz[static_cast<size_t>(to)] > comp / 2)
                return findCentroid(to, v, comp);
        }
        return v;
    }

    void build(int entry, int parent) {
        int comp = dfsSize(entry, -1);
        int c = findCentroid(entry, -1, comp);
        dead[static_cast<size_t>(c)] = 1; // remove before recurse
        cpar[static_cast<size_t>(c)] = parent;
        compsize_at[static_cast<size_t>(c)] = comp;
        if (parent < 0) root = c;
        else ctree[static_cast<size_t>(parent)].push_back(c);
        for (int to : g[static_cast<size_t>(c)]) {
            if (!dead[static_cast<size_t>(to)]) build(to, c);
        }
    }

    void decompose() { build(1, -1); }
};

int main() {
    CentroidDecomp cd(4);
    cd.addEdge(1, 2);
    cd.addEdge(2, 3);
    cd.addEdge(3, 4);
    cd.decompose();

    std::cout << "centroid_root=" << cd.root << "\n";
    std::cout << "cpar[1..4]:";
    for (int i = 1; i <= 4; ++i) std::cout << " " << cd.cpar[static_cast<size_t>(i)];
    std::cout << "\n";
    std::cout << "compsize_at_root=" << cd.compsize_at[static_cast<size_t>(cd.root)]
              << " (expected 4)\n";
    int marked = 0;
    for (int i = 1; i <= 4; ++i) if (cd.dead[static_cast<size_t>(i)]) ++marked;
    std::cout << "nodes_decomposed=" << marked << " (expected 4)\n";
    return 0;
}
