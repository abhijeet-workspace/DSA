// Graph Representations — adjacency matrix vs adjacency list side-by-side
// Same undirected 4-vertex graph printed both ways for comparison.
#include <iostream>
#include <vector>

void adjacencyMatrixDemo() {
    const int V = 4;
    std::vector<std::vector<int>> mat(V, std::vector<int>(V, 0));
    mat[0][1] = mat[1][0] = 1;
    mat[0][2] = mat[2][0] = 1;
    mat[1][2] = mat[2][1] = 1;
    mat[2][3] = mat[3][2] = 1;

    std::cout << "--- Adjacency Matrix ---\n";
    for (int i = 0; i < V; ++i) {
        for (int j = 0; j < V; ++j) {
            std::cout << mat[i][j] << " ";
        }
        std::cout << "\n";
    }
}

void adjacencyListDemo() {
    const int V = 4;
    std::vector<std::vector<int>> adj(V);
    adj[0].push_back(1);
    adj[1].push_back(0);
    adj[0].push_back(2);
    adj[2].push_back(0);
    adj[1].push_back(2);
    adj[2].push_back(1);
    adj[2].push_back(3);
    adj[3].push_back(2);

    std::cout << "--- Adjacency List ---\n";
    for (int i = 0; i < V; ++i) {
        std::cout << i << ": ";
        for (int nb : adj[i]) {
            std::cout << nb << " ";
        }
        std::cout << "\n";
    }
}

int main() {
    adjacencyMatrixDemo();
    adjacencyListDemo();
    return 0;
}
