// Lab: compare Euler+RMQ LCA vs binary lifting on same queries
#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

int main() {
    std::vector<std::vector<int>> adj(6);
    auto add = [&](int u, int v) {
        adj[u].push_back(v);
        adj[v].push_back(u);
    };
    add(0, 1);
    add(0, 2);
    add(1, 3);
    add(1, 4);
    add(2, 5);
    // Binary lifting
    int n = 6, LOG = 4;
    std::vector<int> depth(n), parent(n, -1);
    std::vector<std::vector<int>> up(LOG, std::vector<int>(n, -1));
    auto dfs1 = [&](auto&& self, int u, int p) -> void {
        parent[u] = p;
        up[0][u] = p;
        for (int v : adj[u])
            if (v != p) {
                depth[v] = depth[u] + 1;
                self(self, v, u);
            }
    };
    dfs1(dfs1, 0, -1);
    for (int k = 1; k < LOG; ++k)
        for (int v = 0; v < n; ++v)
            if (up[k - 1][v] != -1)
                up[k][v] = up[k - 1][up[k - 1][v]];
    auto lift = [&](int u, int k) {
        for (int i = 0; i < LOG && u != -1; ++i)
            if (k & (1 << i))
                u = up[i][u];
        return u;
    };
    auto lcaLift = [&](int u, int v) {
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
    };
    // Euler + sparse RMQ
    std::vector<int> euler, depthE, first(n, -1);
    auto dfs2 = [&](auto&& self, int u, int p, int d) -> void {
        first[u] = (int)euler.size();
        euler.push_back(u);
        depthE.push_back(d);
        for (int v : adj[u])
            if (v != p) {
                self(self, v, u, d + 1);
                euler.push_back(u);
                depthE.push_back(d);
            }
    };
    dfs2(dfs2, 0, -1, 0);
    int m = (int)euler.size(), LG = 32 - __builtin_clz(m);
    std::vector<std::vector<int>> st(LG, std::vector<int>(m));
    st[0] = depthE;
    for (int k = 1; k < LG; ++k)
        for (int i = 0; i + (1 << k) <= m; ++i)
            st[k][i] = std::min(st[k - 1][i], st[k - 1][i + (1 << (k - 1))]);
    auto rmq = [&](int l, int r) {
        int len = r - l + 1, k = 31 - __builtin_clz(len);
        return std::min(st[k][l], st[k][r - (1 << k) + 1]);
    };
    auto lcaRMQ = [&](int u, int v) {
        int L = first[u], R = first[v];
        if (L > R)
            std::swap(L, R);
        int bestD = rmq(L, R);
        for (int i = L; i <= R; ++i)
            if (depthE[i] == bestD)
                return euler[i];
        return 0;
    };
    bool ok = true;
    for (int u = 0; u < n; ++u)
        for (int v = 0; v < n; ++v)
            if (lcaLift(u, v) != lcaRMQ(u, v))
                ok = false;
    std::cout << (ok ? "all LCA methods agree OK\n" : "FAIL\n");
    return ok ? 0 : 1;
}
