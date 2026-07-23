// Floyd-Warshall — all-pairs shortest paths on a dense weighted graph.
// Prints distance matrix; assumes no negative cycle.
#include <algorithm>
#include <iostream>
#include <vector>

constexpr int INF = 1000000000;

void floydWarshall(int V, const std::vector<std::vector<int>>& graph) {
    std::vector<std::vector<int>> dist = graph;
    for (int k = 0; k < V; ++k) {
        for (int i = 0; i < V; ++i) {
            for (int j = 0; j < V; ++j) {
                if (dist[static_cast<size_t>(i)][static_cast<size_t>(k)] != INF &&
                    dist[static_cast<size_t>(k)][static_cast<size_t>(j)] != INF) {
                    dist[static_cast<size_t>(i)][static_cast<size_t>(j)] = std::min(
                        dist[static_cast<size_t>(i)][static_cast<size_t>(j)],
                        dist[static_cast<size_t>(i)][static_cast<size_t>(k)] +
                            dist[static_cast<size_t>(k)][static_cast<size_t>(j)]);
                }
            }
        }
    }
    std::cout << "dist matrix:\n";
    for (int i = 0; i < V; ++i) {
        for (int j = 0; j < V; ++j) {
            if (dist[static_cast<size_t>(i)][static_cast<size_t>(j)] == INF) {
                std::cout << "INF ";
            } else {
                std::cout << dist[static_cast<size_t>(i)][static_cast<size_t>(j)] << " ";
            }
        }
        std::cout << "\n";
    }
}

int main() {
    const int V = 4;
    const std::vector<std::vector<int>> graph = {
        {0, 3, INF, 7},
        {8, 0, 2, INF},
        {5, INF, 0, 1},
        {2, INF, INF, 0},
    };
    floydWarshall(V, graph);
    return 0;
}
