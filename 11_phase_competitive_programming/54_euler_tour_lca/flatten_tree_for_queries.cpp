// Flatten tree (enter times only) for subtree array queries
#include <iostream>
#include <vector>

int main() {
    std::vector<std::vector<int>> adj(5);
    auto ae = [&](int u, int v) {
        adj[u].push_back(v);
        adj[v].push_back(u);
    };
    ae(0, 1);
    ae(0, 2);
    ae(1, 3);
    ae(1, 4);
    std::vector<int> inT(5), outT(5), flat;
    int timer = 0;
    auto dfs = [&](auto&& self, int u, int p) -> void {
        inT[u] = timer++;
        flat.push_back(u);
        for (int v : adj[u])
            if (v != p)
                self(self, v, u);
        outT[u] = timer - 1;
    };
    dfs(dfs, 0, -1);
    // subtree of 1 should be contiguous in flat[in..out]
    std::vector<int> sub;
    for (int i = inT[1]; i <= outT[1]; ++i)
        sub.push_back(flat[i]);
    const std::vector<int> exp = {1, 3, 4}; // order depends on adj order
    bool ok = (sub == exp || (sub.size() == 3 && inT[1] <= inT[3] && outT[3] <= outT[1] &&
                              inT[1] <= inT[4] && outT[4] <= outT[1]));
    std::cout << "flat:";
    for (int x : flat)
        std::cout << " " << x;
    std::cout << "\nsub1:";
    for (int x : sub)
        std::cout << " " << x;
    std::cout << "\n" << (ok ? "OK\n" : "FAIL\n");
    return ok ? 0 : 1;
}
