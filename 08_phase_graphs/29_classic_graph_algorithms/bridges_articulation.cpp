// Bridges & articulation points — Tarjan DFS (tin / low).
// Print critical edges and cut vertices on an undirected graph.
#include <algorithm>
#include <iostream>
#include <utility>
#include <vector>

int timer = 0;

void dfs(int u, int p, const std::vector<std::vector<int>>& adj, std::vector<int>& tin,
         std::vector<int>& low, std::vector<bool>& visited,
         std::vector<std::pair<int, int>>& bridges, std::vector<bool>& art) {
    visited[static_cast<size_t>(u)] = true;
    tin[static_cast<size_t>(u)] = low[static_cast<size_t>(u)] = timer++;
    int children = 0;
    for (int v : adj[static_cast<size_t>(u)]) {
        if (v == p) {
            continue;
        }
        if (visited[static_cast<size_t>(v)]) {
            low[static_cast<size_t>(u)] =
                std::min(low[static_cast<size_t>(u)], tin[static_cast<size_t>(v)]);
        } else {
            ++children;
            dfs(v, u, adj, tin, low, visited, bridges, art);
            low[static_cast<size_t>(u)] =
                std::min(low[static_cast<size_t>(u)], low[static_cast<size_t>(v)]);
            if (low[static_cast<size_t>(v)] > tin[static_cast<size_t>(u)]) {
                bridges.push_back({u, v}); // no back-edge from v's subtree to u/ancestors
            }
            if (p != -1 && low[static_cast<size_t>(v)] >= tin[static_cast<size_t>(u)]) {
                art[static_cast<size_t>(u)] = true;
            }
        }
    }
    if (p == -1 && children > 1) {
        art[static_cast<size_t>(u)] = true; // root with ≥2 DFS children
    }
}

int main() {
    const int V = 5;
    std::vector<std::vector<int>> adj(static_cast<size_t>(V));
    const std::vector<std::pair<int, int>> edges = {
        {0, 1}, {1, 2}, {2, 0}, {1, 3}, {3, 4},
    };
    for (const auto& [a, b] : edges) {
        adj[static_cast<size_t>(a)].push_back(b);
        adj[static_cast<size_t>(b)].push_back(a);
    }
    std::vector<int> tin(static_cast<size_t>(V), -1);
    std::vector<int> low(static_cast<size_t>(V), -1);
    std::vector<bool> visited(static_cast<size_t>(V), false);
    std::vector<std::pair<int, int>> bridges;
    std::vector<bool> art(static_cast<size_t>(V), false);
    timer = 0;
    for (int i = 0; i < V; ++i) {
        if (!visited[static_cast<size_t>(i)]) {
            dfs(i, -1, adj, tin, low, visited, bridges, art);
        }
    }
    std::cout << "bridges:\n";
    for (const auto& [a, b] : bridges) {
        std::cout << a << " - " << b << "\n";
    }
    std::cout << "articulation:";
    for (int i = 0; i < V; ++i) {
        if (art[static_cast<size_t>(i)]) {
            std::cout << " " << i;
        }
    }
    std::cout << "\n";
    return 0;
}
