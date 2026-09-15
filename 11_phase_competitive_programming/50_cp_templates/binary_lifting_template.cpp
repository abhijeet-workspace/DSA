// Binary lifting template — k-th ancestor on a rooted tree
#include <iostream>
#include <vector>

struct BinLift {
    int n, LOG;
    std::vector<std::vector<int>> up;
    std::vector<int> depth;
    BinLift(int n, const std::vector<std::vector<int>>& adj, int root = 0)
        : n(n), LOG(1), depth(n, 0) {
        while ((1 << LOG) <= n)
            ++LOG;
        up.assign(LOG, std::vector<int>(n, -1));
        dfs(root, -1, adj);
        for (int k = 1; k < LOG; ++k)
            for (int v = 0; v < n; ++v)
                if (up[k - 1][v] != -1)
                    up[k][v] = up[k - 1][up[k - 1][v]];
    }
    void dfs(int u, int p, const std::vector<std::vector<int>>& adj) {
        up[0][u] = p;
        for (int v : adj[u])
            if (v != p) {
                depth[v] = depth[u] + 1;
                dfs(v, u, adj);
            }
    }
    int kth(int u, int k) const {
        for (int i = 0; i < LOG && u != -1; ++i)
            if (k & (1 << i))
                u = up[i][u];
        return u;
    }
};

int main() {
    // 0-1-3, 0-2-4
    std::vector<std::vector<int>> adj(5);
    auto add = [&](int u, int v) {
        adj[u].push_back(v);
        adj[v].push_back(u);
    };
    add(0, 1);
    add(1, 3);
    add(0, 2);
    add(2, 4);
    BinLift bl(5, adj, 0);
    const int a = bl.kth(3, 1); // 1
    const int b = bl.kth(3, 2); // 0
    const int c = bl.kth(4, 1); // 2
    std::cout << "kth: " << a << " " << b << " " << c << "\n";
    const bool ok = (a == 1 && b == 0 && c == 2);
    std::cout << (ok ? "OK\n" : "FAIL\n");
    return ok ? 0 : 1;
}
