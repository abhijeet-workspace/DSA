// Graph BFS — level-order traversal from a source
// Queue + visited; visit each vertex/edge once on unweighted graphs.
#include <iostream>
#include <queue>
#include <vector>

void addEdge(std::vector<std::vector<int>>& adj, int u, int v) {
    adj[u].push_back(v);
    adj[v].push_back(u);
}

void bfs(const std::vector<std::vector<int>>& adj, int src) {
    std::vector<bool> visited(adj.size(), false);
    std::queue<int> q;
    visited[src] = true; // mark before enqueue
    q.push(src);

    std::cout << "BFS from " << src << ": ";
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        std::cout << u << " ";
        for (int v : adj[u]) {
            if (!visited[v]) {
                visited[v] = true;
                q.push(v);
            }
        }
    }
    std::cout << "\n";
}

int main() {
    const int V = 5;
    std::vector<std::vector<int>> adj(V);
    addEdge(adj, 0, 1);
    addEdge(adj, 0, 2);
    addEdge(adj, 1, 3);
    addEdge(adj, 2, 4);

    bfs(adj, 0); // expected 0 1 2 3 4 (order among same level may vary)
    return 0;
}
