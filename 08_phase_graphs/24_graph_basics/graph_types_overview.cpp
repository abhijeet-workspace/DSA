// Graph Types Demo — directed/undirected, weighted, DAG topo, bipartite
// Teaching walkthrough of common graph classifications and checks.
#include <iostream>
#include <queue>
#include <utility>
#include <vector>

void demoDirectedVsUndirected() {
    const int V = 4;
    std::vector<std::vector<int>> undirected(V);
    std::vector<std::vector<int>> directed(V);

    undirected[0].push_back(1);
    undirected[1].push_back(0);
    undirected[1].push_back(2);
    undirected[2].push_back(1);

    directed[0].push_back(1); // one-way only
    directed[1].push_back(2);

    std::cout << "\n--- 1. Directed vs Undirected ---\n";
    for (int i = 0; i < V; ++i) {
        std::cout << "undirected " << i << ": ";
        for (int nb : undirected[i]) {
            std::cout << nb << " ";
        }
        std::cout << "\n";
    }
    for (int i = 0; i < V; ++i) {
        std::cout << "directed " << i << ": ";
        for (int nb : directed[i]) {
            std::cout << nb << " ";
        }
        std::cout << "\n";
    }
}

void demoWeightedGraph() {
    const int V = 4;
    std::vector<std::vector<int>> mat(V, std::vector<int>(V, -1)); // -1 = no edge
    std::vector<std::vector<std::pair<int, int>>> adj(V);          // {neighbor, weight}

    mat[0][1] = 5;
    mat[0][2] = 8;
    mat[1][2] = 2;
    mat[2][3] = 12;
    adj[0].push_back({1, 5});
    adj[0].push_back({2, 8});
    adj[1].push_back({2, 2});
    adj[2].push_back({3, 12});

    std::cout << "\n--- 2. Weighted Graph ---\n";
    for (int i = 0; i < V; ++i) {
        for (int j = 0; j < V; ++j) {
            if (mat[i][j] < 0) {
                std::cout << "INF ";
            } else {
                std::cout << mat[i][j] << " ";
            }
        }
        std::cout << "\n";
    }
    for (int i = 0; i < V; ++i) {
        std::cout << i << ": ";
        for (const auto& e : adj[i]) {
            std::cout << "(" << e.first << "," << e.second << ") ";
        }
        std::cout << "\n";
    }
}

void demoDAGAndTopologicalSort() {
    const int V = 6;
    std::vector<std::vector<int>> adj(V);
    std::vector<int> indegree(V, 0);
    const std::vector<std::pair<int, int>> edges = {
        {5, 2}, {5, 0}, {4, 0}, {4, 1}, {2, 3}, {3, 1},
    };
    for (const auto& e : edges) {
        adj[e.first].push_back(e.second);
        ++indegree[e.second];
    }

    std::queue<int> q;
    for (int i = 0; i < V; ++i) {
        if (indegree[i] == 0) {
            q.push(i);
        }
    }

    std::vector<int> topo;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        topo.push_back(u);
        for (int v : adj[u]) {
            if (--indegree[v] == 0) {
                q.push(v);
            }
        }
    }

    std::cout << "\n--- 3. DAG / Kahn Topo ---\n";
    if (static_cast<int>(topo.size()) == V) {
        std::cout << "DAG topo: ";
        for (int x : topo) {
            std::cout << x << " ";
        }
        std::cout << "\n";
    } else {
        std::cout << "cyclic — topo impossible\n";
    }
}

bool isBipartite(int V, std::vector<std::vector<int>>& adj) {
    std::vector<int> color(V, -1); // -1 uncolored
    for (int s = 0; s < V; ++s) {
        if (color[s] != -1) {
            continue;
        }
        std::queue<int> q;
        q.push(s);
        color[s] = 0;
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            for (int v : adj[u]) {
                if (color[v] == -1) {
                    color[v] = 1 - color[u];
                    q.push(v);
                } else if (color[v] == color[u]) {
                    return false; // same color across edge
                }
            }
        }
    }
    return true;
}

void demoBipartite() {
    std::cout << "\n--- 4. Bipartite Check ---\n";
    std::vector<std::vector<int>> square(4);
    square[0].push_back(1);
    square[1].push_back(0);
    square[1].push_back(2);
    square[2].push_back(1);
    square[2].push_back(3);
    square[3].push_back(2);
    square[3].push_back(0);
    square[0].push_back(3);
    std::cout << "C4 square: " << (isBipartite(4, square) ? "BIPARTITE" : "NOT") << "\n";

    std::vector<std::vector<int>> triangle(3);
    triangle[0].push_back(1);
    triangle[1].push_back(0);
    triangle[1].push_back(2);
    triangle[2].push_back(1);
    triangle[2].push_back(0);
    triangle[0].push_back(2);
    std::cout << "triangle: " << (isBipartite(3, triangle) ? "BIPARTITE" : "NOT") << "\n";
}

int main() {
    std::cout << "GRAPH TYPES DEMO\n";
    demoDirectedVsUndirected();
    demoWeightedGraph();
    demoDAGAndTopologicalSort();
    demoBipartite();
    return 0;
}
