// Euler tour — in/out times; test if u lies in subtree of v
// Contiguous [in[v], out[v]] contains exactly subtree(v).
#include <iostream>
#include <vector>

void dfs(int u, int p, const std::vector<std::vector<int>>& adj,
         std::vector<int>& inT, std::vector<int>& outT, int& timer) {
    inT[static_cast<size_t>(u)] = timer++;
    for (int v : adj[static_cast<size_t>(u)]) {
        if (v == p) {
            continue;
        }
        dfs(v, u, adj, inT, outT, timer);
    }
    outT[static_cast<size_t>(u)] = timer++;
}

bool inSubtree(int u, int v, const std::vector<int>& inT, const std::vector<int>& outT) {
    return inT[static_cast<size_t>(v)] <= inT[static_cast<size_t>(u)]
        && outT[static_cast<size_t>(u)] <= outT[static_cast<size_t>(v)];
}

int main() {
    // Tree: 0-1-3, 0-2
    const int n = 4;
    std::vector<std::vector<int>> adj(n);
    auto addEdge = [&](int u, int v) {
        adj[static_cast<size_t>(u)].push_back(v);
        adj[static_cast<size_t>(v)].push_back(u);
    };
    addEdge(0, 1);
    addEdge(0, 2);
    addEdge(1, 3);

    std::vector<int> inT(n), outT(n);
    int timer = 0;
    dfs(0, -1, adj, inT, outT, timer);

    const bool t1 = inSubtree(3, 1, inT, outT);
    const bool t2 = inSubtree(2, 1, inT, outT);
    const bool t3 = inSubtree(1, 0, inT, outT);
    const bool t4 = inSubtree(0, 0, inT, outT);
    const bool t5 = inSubtree(2, 3, inT, outT);

    const bool ok = t1 && !t2 && t3 && t4 && !t5;
    std::cout << "3 in subtree(1)? " << t1 << " (expected 1)\n";
    std::cout << "2 in subtree(1)? " << t2 << " (expected 0)\n";
    std::cout << "1 in subtree(0)? " << t3 << " (expected 1)\n";
    std::cout << "0 in subtree(0)? " << t4 << " (expected 1)\n";
    std::cout << "2 in subtree(3)? " << t5 << " (expected 0)\n";
    std::cout << (ok ? "OK\n" : "FAIL\n");
    return ok ? 0 : 1;
}
