// Decompose + Answer Distance Queries — teaching
// Baseline: parent-climb LCA. CD ancestor tables noted in md.
#include <iostream>
#include <vector>

struct DistQueries {
    int n;
    std::vector<std::vector<int>> g;
    std::vector<int> depth, parent;
    DistQueries(int n_) : n(n_), g(n_ + 1), depth(n_ + 1), parent(n_ + 1) {}
    void addEdge(int u, int v) {
        g[static_cast<size_t>(u)].push_back(v);
        g[static_cast<size_t>(v)].push_back(u);
    }
    void dfs(int v, int p, int d) {
        parent[static_cast<size_t>(v)] = p;
        depth[static_cast<size_t>(v)] = d;
        for (int to : g[static_cast<size_t>(v)])
            if (to != p)
                dfs(to, v, d + 1);
    }
    int dist(int u, int v) {
        int a = u, b = v;
        while (depth[static_cast<size_t>(a)] > depth[static_cast<size_t>(b)])
            a = parent[static_cast<size_t>(a)];
        while (depth[static_cast<size_t>(b)] > depth[static_cast<size_t>(a)])
            b = parent[static_cast<size_t>(b)];
        while (a != b) {
            a = parent[static_cast<size_t>(a)];
            b = parent[static_cast<size_t>(b)];
        }
        return depth[static_cast<size_t>(u)] + depth[static_cast<size_t>(v)] -
               2 * depth[static_cast<size_t>(a)];
    }
};

int main() {
    DistQueries t(5);
    t.addEdge(1, 2);
    t.addEdge(2, 3);
    t.addEdge(3, 4);
    t.addEdge(2, 5);
    t.dfs(1, 0, 0);
    std::cout << t.dist(4, 5) << " (expected 3)\n";
    std::cout << t.dist(1, 4) << " (expected 3)\n";
    return 0;
}
