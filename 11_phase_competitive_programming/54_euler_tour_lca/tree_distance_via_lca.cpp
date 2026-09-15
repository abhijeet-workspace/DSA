// Distance(u,v) = depth[u]+depth[v]-2*depth[lca]
#include <iostream>
#include <vector>

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
    std::vector<int> depth(5), parent(5, -1);
    auto dfs = [&](auto&& self, int u, int p) -> void {
        parent[u] = p;
        for (int v : adj[u])
            if (v != p) {
                depth[v] = depth[u] + 1;
                self(self, v, u);
            }
    };
    dfs(dfs, 0, -1);
    auto lca = [&](int u, int v) {
        while (depth[u] > depth[v])
            u = parent[u];
        while (depth[v] > depth[u])
            v = parent[v];
        while (u != v) {
            u = parent[u];
            v = parent[v];
        }
        return u;
    };
    auto dist = [&](int u, int v) { return depth[u] + depth[v] - 2 * depth[lca(u, v)]; };
    bool ok = dist(3, 4) == 4 && dist(3, 1) == 1 && dist(4, 2) == 1;
    std::cout << "d34=" << dist(3, 4) << " d31=" << dist(3, 1) << "\n";
    std::cout << (ok ? "OK\n" : "FAIL\n");
    return ok ? 0 : 1;
}
