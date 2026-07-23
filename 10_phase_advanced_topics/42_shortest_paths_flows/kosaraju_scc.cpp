// Kosaraju SCC — finish-order DFS, then DFS on transpose
#include <algorithm>
#include <iostream>
#include <stack>
#include <vector>

void dfs1(int u, const std::vector<std::vector<int>>& adj, std::vector<char>& vis,
          std::stack<int>& stk) {
    vis[static_cast<size_t>(u)] = 1;
    for (int v : adj[static_cast<size_t>(u)]) {
        if (!vis[static_cast<size_t>(v)]) {
            dfs1(v, adj, vis, stk);
        }
    }
    stk.push(u);
}

void dfs2(int u, const std::vector<std::vector<int>>& radj, std::vector<char>& vis,
          std::vector<int>& comp) {
    vis[static_cast<size_t>(u)] = 1;
    comp.push_back(u);
    for (int v : radj[static_cast<size_t>(u)]) {
        if (!vis[static_cast<size_t>(v)]) {
            dfs2(v, radj, vis, comp);
        }
    }
}

std::vector<std::vector<int>> kosarajuSCC(int V, const std::vector<std::vector<int>>& adj) {
    std::vector<char> vis(static_cast<size_t>(V), 0);
    std::stack<int> stk;
    for (int i = 0; i < V; ++i) {
        if (!vis[static_cast<size_t>(i)]) {
            dfs1(i, adj, vis, stk);
        }
    }
    std::vector<std::vector<int>> radj(static_cast<size_t>(V));
    for (int u = 0; u < V; ++u) {
        for (int v : adj[static_cast<size_t>(u)]) {
            radj[static_cast<size_t>(v)].push_back(u);
        }
    }
    std::fill(vis.begin(), vis.end(), 0);
    std::vector<std::vector<int>> sccs;
    while (!stk.empty()) {
        int u = stk.top();
        stk.pop();
        if (!vis[static_cast<size_t>(u)]) {
            std::vector<int> comp;
            dfs2(u, radj, vis, comp);
            sccs.push_back(std::move(comp));
        }
    }
    return sccs;
}

int main() {
    std::vector<std::vector<int>> adj(5);
    adj[0].push_back(2);
    adj[2].push_back(1);
    adj[1].push_back(0);
    adj[1].push_back(3);
    adj[3].push_back(4);
    auto sccs = kosarajuSCC(5, adj);
    std::cout << "sccs=" << sccs.size() << " (expected 3)\n";
    return 0;
}
