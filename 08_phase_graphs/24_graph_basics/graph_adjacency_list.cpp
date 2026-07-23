// Graph Adjacency List — undirected sparse representation
// Build V lists of neighbors; add undirected edges both ways.
#include <iostream>
#include <vector>

const int V = 4;

void addEdge(std::vector<std::vector<int>>& adj, int u, int v) {
    adj[u].push_back(v); // u -> v
    adj[v].push_back(u); // undirected: v -> u
}

int main() {
    std::vector<std::vector<int>> adj(V);
    addEdge(adj, 0, 1);
    addEdge(adj, 0, 2);
    addEdge(adj, 1, 2);
    addEdge(adj, 2, 3);

    std::cout << "Adjacency List:\n";
    for (int i = 0; i < V; ++i) {
        std::cout << i << ": ";
        for (int nb : adj[i]) {
            std::cout << nb << " ";
        }
        std::cout << "\n";
    }
    return 0;
}
