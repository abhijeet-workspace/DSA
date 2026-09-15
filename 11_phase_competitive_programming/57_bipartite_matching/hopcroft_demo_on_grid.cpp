// Hopcroft–Karp Demo on Grid — teaching
// Bipartite matching: black cells to white cells for adjacent pairs on a checkerboard.
#include <iostream>
#include <queue>
#include <vector>

struct HK {
    int nL, nR;
    std::vector<std::vector<int>> g;
    std::vector<int> pairU, pairV, dist;
    static constexpr int NIL = 0;
    static constexpr int INF = 1e9;
    HK(int nL_, int nR_)
        : nL(nL_), nR(nR_), g(nL_ + 1), pairU(nL_ + 1, NIL), pairV(nR_ + 1, NIL), dist(nL_ + 1) {}
    bool bfs() {
        std::queue<int> q;
        for (int u = 1; u <= nL; ++u) {
            if (pairU[static_cast<size_t>(u)] == NIL) {
                dist[static_cast<size_t>(u)] = 0;
                q.push(u);
            } else
                dist[static_cast<size_t>(u)] = INF;
        }
        dist[NIL] = INF;
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            if (dist[static_cast<size_t>(u)] < dist[NIL]) {
                for (int v : g[static_cast<size_t>(u)]) {
                    int pu = pairV[static_cast<size_t>(v)];
                    if (dist[static_cast<size_t>(pu)] == INF) {
                        dist[static_cast<size_t>(pu)] = dist[static_cast<size_t>(u)] + 1;
                        q.push(pu);
                    }
                }
            }
        }
        return dist[NIL] != INF;
    }
    bool dfs(int u) {
        if (u == NIL)
            return true;
        for (int v : g[static_cast<size_t>(u)]) {
            int pu = pairV[static_cast<size_t>(v)];
            if (dist[static_cast<size_t>(pu)] == dist[static_cast<size_t>(u)] + 1 && dfs(pu)) {
                pairU[static_cast<size_t>(u)] = v;
                pairV[static_cast<size_t>(v)] = u;
                return true;
            }
        }
        dist[static_cast<size_t>(u)] = INF;
        return false;
    }
    int maxMatching() {
        int matching = 0;
        while (bfs())
            for (int u = 1; u <= nL; ++u)
                if (pairU[static_cast<size_t>(u)] == NIL && dfs(u))
                    ++matching;
        return matching;
    }
};

int main() {
    // 2x2 grid: 2 black, 2 white, 4 edges → matching 2
    HK hk(2, 2);
    hk.g[1] = {1, 2};
    hk.g[2] = {1, 2};
    std::cout << hk.maxMatching() << " (expected 2)\n";
    return 0;
}
