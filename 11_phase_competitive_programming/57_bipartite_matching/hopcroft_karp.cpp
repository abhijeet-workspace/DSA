// Hopcroft–Karp — CP classic
// Maximum bipartite matching via layered BFS + multiple DFS per phase (O(E√V)).
#include <iostream>
#include <limits>
#include <queue>
#include <vector>

int nL, nR;
std::vector<std::vector<int>> g;
std::vector<int> pairU, pairV, dist;
const int NIL = 0;
const int INF = std::numeric_limits<int>::max() / 4;

bool bfs() {
    std::queue<int> q;
    for (int u = 1; u <= nL; ++u) {
        if (pairU[static_cast<size_t>(u)] == NIL) {
            dist[static_cast<size_t>(u)] = 0;
            q.push(u);
        } else {
            dist[static_cast<size_t>(u)] = INF;
        }
    }
    dist[NIL] = INF;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        if (dist[static_cast<size_t>(u)] < dist[NIL]) {
            for (int v : g[static_cast<size_t>(u)]) {
                int u2 = pairV[static_cast<size_t>(v)];
                if (dist[static_cast<size_t>(u2)] == INF) {
                    dist[static_cast<size_t>(u2)] = dist[static_cast<size_t>(u)] + 1;
                    q.push(u2);
                }
            }
        }
    }
    return dist[NIL] != INF; // free right reachable via layers
}

bool dfs(int u) {
    if (u == NIL) return true;
    for (int v : g[static_cast<size_t>(u)]) {
        int u2 = pairV[static_cast<size_t>(v)];
        if (dist[static_cast<size_t>(u2)] == dist[static_cast<size_t>(u)] + 1 && dfs(u2)) {
            pairV[static_cast<size_t>(v)] = u;
            pairU[static_cast<size_t>(u)] = v;
            return true;
        }
    }
    dist[static_cast<size_t>(u)] = INF;
    return false;
}

int hopcroftKarp() {
    pairU.assign(static_cast<size_t>(nL) + 1, NIL);
    pairV.assign(static_cast<size_t>(nR) + 1, NIL);
    dist.assign(static_cast<size_t>(nL) + 1, 0);
    int matching = 0;
    while (bfs()) {
        for (int u = 1; u <= nL; ++u)
            if (pairU[static_cast<size_t>(u)] == NIL && dfs(u)) ++matching;
    }
    return matching;
}

int main() {
    nL = 2;
    nR = 2;
    g.assign(static_cast<size_t>(nL) + 1, {});
    g[1] = {1, 2};
    g[2] = {1, 2};
    std::cout << hopcroftKarp() << " (expected 2)\n";
    return 0;
}
