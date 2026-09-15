// Binary lifting LCA (contest standard)
#include <iostream>
#include <vector>

struct LCA {
    int n, LOG;
    std::vector<int> depth;
    std::vector<std::vector<int>> up;
    LCA(int n, const std::vector<std::vector<int>>& adj, int root = 0) : n(n), LOG(1), depth(n, 0) {
        while ((1 << LOG) <= n)
            ++LOG;
        up.assign(LOG, std::vector<int>(n, -1));
        auto dfs = [&](auto&& self, int u, int p) -> void {
            up[0][u] = p;
            for (int v : adj[u])
                if (v != p) {
                    depth[v] = depth[u] + 1;
                    self(self, v, u);
                }
        };
        dfs(dfs, root, -1);
        for (int k = 1; k < LOG; ++k)
            for (int v = 0; v < n; ++v)
                if (up[k - 1][v] != -1)
                    up[k][v] = up[k - 1][up[k - 1][v]];
    }
    int lift(int u, int k) const {
        for (int i = 0; i < LOG && u != -1; ++i)
            if (k & (1 << i))
                u = up[i][u];
        return u;
    }
    int query(int u, int v) const {
        if (depth[u] < depth[v])
            std::swap(u, v);
        u = lift(u, depth[u] - depth[v]);
        if (u == v)
            return u;
        for (int i = LOG - 1; i >= 0; --i)
            if (up[i][u] != up[i][v]) {
                u = up[i][u];
                v = up[i][v];
            }
        return up[0][u];
    }
};

int main() {
    std::vector<std::vector<int>> adj(5);
    auto add = [&](int u, int v) {
        adj[u].push_back(v);
        adj[v].push_back(u);
    };
    add(0, 1);
    add(1, 3);
    add(0, 2);
    add(2, 4);
    LCA lca(5, adj, 0);
    bool ok = lca.query(3, 4) == 0 && lca.query(3, 1) == 1 && lca.query(4, 2) == 2;
    std::cout << "lca34=" << lca.query(3, 4) << " lca31=" << lca.query(3, 1) << "\n";
    std::cout << (ok ? "OK\n" : "FAIL\n");
    return ok ? 0 : 1;
}
