// Path sum via Euler tour difference: +val at in[u], -val at out[u]
// path-root sum = prefix[in[u]]; path u-v = rootu+rootv-2*rootLCA (+val[LCA] if node weights)
#include <iostream>
#include <vector>

int main() {
    // tree 0-1-3, 0-2 values on nodes
    std::vector<long long> val = {1, 2, 3, 4};
    std::vector<std::vector<int>> adj(4);
    auto add = [&](int u, int v) {
        adj[u].push_back(v);
        adj[v].push_back(u);
    };
    add(0, 1);
    add(1, 3);
    add(0, 2);
    std::vector<int> inT(4), outT(4), parent(4, -1);
    int timer = 0;
    std::vector<long long> diff;
    auto dfs = [&](auto&& self, int u, int p) -> void {
        parent[u] = p;
        inT[u] = timer++;
        diff.push_back(val[u]);
        for (int v : adj[u])
            if (v != p)
                self(self, v, u);
        outT[u] = timer++;
        diff.push_back(-val[u]);
    };
    dfs(dfs, 0, -1);
    std::vector<long long> pref(diff.size() + 1, 0);
    for (size_t i = 0; i < diff.size(); ++i)
        pref[i + 1] = pref[i] + diff[i];
    auto rootSum = [&](int u) { return pref[inT[u] + 1]; };
    // LCA climb
    auto lca = [&](int u, int v) {
        std::vector<int> seen(4, 0);
        for (int x = u; x != -1; x = parent[x])
            seen[x] = 1;
        for (int x = v; x != -1; x = parent[x])
            if (seen[x])
                return x;
        return 0;
    };
    auto pathSum = [&](int u, int v) {
        int w = lca(u, v);
        return rootSum(u) + rootSum(v) - 2 * rootSum(w) + val[w];
    };
    long long a = pathSum(3, 2); // 4+2+1+3=10
    long long b = pathSum(3, 1); // 4+2=6
    std::cout << "a=" << a << " b=" << b << "\n";
    bool ok = (a == 10 && b == 6);
    std::cout << (ok ? "OK\n" : "FAIL\n");
    return ok ? 0 : 1;
}
