// Graph Adjacency Matrix — undirected dense representation
// V×V grid; mat[u][v]=1 means an edge (symmetric for undirected).
#include <iostream>

const int V = 4;

void addEdge(int mat[V][V], int u, int v) {
    mat[u][v] = 1; // edge u -> v
    mat[v][u] = 1; // undirected symmetry
}

int main() {
    int mat[V][V] = {}; // all zeros
    addEdge(mat, 0, 1);
    addEdge(mat, 0, 2);
    addEdge(mat, 1, 2);
    addEdge(mat, 2, 3);

    std::cout << "Adjacency Matrix:\n";
    for (int i = 0; i < V; ++i) {
        for (int j = 0; j < V; ++j) {
            std::cout << mat[i][j] << " ";
        }
        std::cout << "\n";
    }
    return 0;
}
