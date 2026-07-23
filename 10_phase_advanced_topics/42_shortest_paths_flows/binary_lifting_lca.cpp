// Binary lifting LCA — up[k][v] = 2^k-th ancestor; related LC 1483
#include <algorithm>
#include <iostream>
#include <vector>

struct BinaryLift {
    int n = 0;
    int LOG = 0;
    std::vector<int> depth;
    std::vector<std::vector<int>> up;
    std::vector<std::vector<int>> g;

    BinaryLift(int n_, const std::vector<std::vector<int>>& edges, int root = 0)
        : n(n_), depth(n_, 0), g(edges) {
        LOG = 1;
        while ((1 << LOG) <= n) {
            ++LOG;
        }
        up.assign(LOG, std::vector<int>(n, -1));
        dfs(root, root);
        for (int k = 1; k < LOG; ++k) {
            for (int v = 0; v < n; ++v) {
                int mid = up[k - 1][v];
                up[k][v] = mid < 0 ? -1 : up[k - 1][mid];
            }
        }
    }

    void dfs(int v, int p) {
        up[0][v] = p;
        for (int to : g[v]) {
            if (to != p) {
                depth[to] = depth[v] + 1;
                dfs(to, v);
            }
        }
    }

    int lift(int v, int dist) const {
        for (int k = 0; k < LOG; ++k) {
            if (dist & (1 << k)) {
                v = up[k][v];
                if (v < 0) {
                    return -1;
                }
            }
        }
        return v;
    }

    int lca(int a, int b) const {
        if (depth[a] < depth[b]) {
            std::swap(a, b);
        }
        a = lift(a, depth[a] - depth[b]);
        if (a == b) {
            return a;
        }
        for (int k = LOG - 1; k >= 0; --k) {
            if (up[k][a] != up[k][b]) {
                a = up[k][a];
                b = up[k][b];
            }
        }
        return up[0][a];
    }
};

int main() {
    int n = 5;
    std::vector<std::vector<int>> g(n);
    auto add = [&](int u, int v) {
        g[u].push_back(v);
        g[v].push_back(u);
    };
    add(0, 1);
    add(0, 2);
    add(1, 3);
    add(2, 4);
    BinaryLift bl(n, g, 0);
    std::cout << "LCA(3,4)=" << bl.lca(3, 4) << " (expected 0)\n";
    std::cout << "LCA(3,1)=" << bl.lca(3, 1) << " (expected 1)\n";
    return 0;
}
