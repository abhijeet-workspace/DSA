// Shortest Path (Unweighted) — BFS with parent pointers
// Reconstruct one minimum-edge path from src to dest in an undirected graph.
#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

std::vector<int> shortestPath(int V, const std::vector<std::vector<int>>& adj, int src,
                              int dest) {
    std::vector<int> dist(V, -1);
    std::vector<int> parent(V, -1);
    std::queue<int> q;
    dist[src] = 0;
    q.push(src);

    while (!q.empty()) {
        int u = q.front();
        q.pop();
        if (u == dest) {
            break;
        }
        for (int v : adj[u]) {
            if (dist[v] == -1) {
                dist[v] = dist[u] + 1;
                parent[v] = u;
                q.push(v);
            }
        }
    }

    if (dist[dest] == -1) {
        return {}; // unreachable
    }
    std::vector<int> path;
    for (int cur = dest; cur != -1; cur = parent[cur]) {
        path.push_back(cur);
    }
    std::reverse(path.begin(), path.end());
    return path;
}

int main() {
    const int V = 6;
    std::vector<std::vector<int>> adj(V);
    adj[0].push_back(1);
    adj[1].push_back(0);
    adj[0].push_back(2);
    adj[2].push_back(0);
    adj[1].push_back(3);
    adj[3].push_back(1);
    adj[2].push_back(4);
    adj[4].push_back(2);
    adj[3].push_back(5);
    adj[5].push_back(3);
    adj[4].push_back(5);
    adj[5].push_back(4);

    auto path = shortestPath(V, adj, 0, 5);
    std::cout << "path: ";
    for (int x : path) {
        std::cout << x << " ";
    }
    std::cout << "(expected length 3, e.g. 0 1 3 5)\n";
    return 0;
}
