// Edmonds-Karp — Ford-Fulkerson with BFS shortest augmenting paths
#include <algorithm>
#include <climits>
#include <iostream>
#include <queue>
#include <vector>

long long edmondsKarp(std::vector<std::vector<long long>> cap, int s, int t) {
    int n = static_cast<int>(cap.size());
    long long flow = 0;
    while (true) {
        std::vector<int> parent(n, -1);
        parent[s] = s;
        std::queue<int> q;
        q.push(s);
        while (!q.empty() && parent[t] == -1) {
            int u = q.front();
            q.pop();
            for (int v = 0; v < n; ++v) {
                if (parent[v] == -1 && cap[u][v] > 0) {
                    parent[v] = u;
                    q.push(v);
                }
            }
        }
        if (parent[t] == -1) {
            break;
        }
        long long aug = LLONG_MAX / 4;
        for (int v = t; v != s; v = parent[v]) {
            aug = std::min(aug, cap[parent[v]][v]);
        }
        for (int v = t; v != s; v = parent[v]) {
            int u = parent[v];
            cap[u][v] -= aug;
            cap[v][u] += aug; // residual reverse
        }
        flow += aug;
    }
    return flow;
}

int main() {
    std::vector<std::vector<long long>> cap(4, std::vector<long long>(4, 0));
    cap[0][1] = 10;
    cap[0][2] = 5;
    cap[1][3] = 8;
    cap[2][3] = 10;
    cap[1][2] = 4;
    std::cout << "maxflow=" << edmondsKarp(cap, 0, 3) << " (expected 15)\n";
    return 0;
}
