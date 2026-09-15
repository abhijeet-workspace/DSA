// Flow Matching via Dinic — teaching
// Unit bipartite matching as max flow source->L->R->sink.
#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

struct Edge {
    int to, rev, cap;
};

struct Dinic {
    int N;
    std::vector<std::vector<Edge>> g;
    std::vector<int> level, it;
    Dinic(int n) : N(n), g(n), level(n), it(n) {}
    void addEdge(int u, int v, int c) {
        Edge a{v, static_cast<int>(g[static_cast<size_t>(v)].size()), c};
        Edge b{u, static_cast<int>(g[static_cast<size_t>(u)].size()), 0};
        g[static_cast<size_t>(u)].push_back(a);
        g[static_cast<size_t>(v)].push_back(b);
    }
    bool bfs(int s, int t) {
        std::fill(level.begin(), level.end(), -1);
        std::queue<int> q;
        level[static_cast<size_t>(s)] = 0;
        q.push(s);
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            for (auto& e : g[static_cast<size_t>(u)])
                if (e.cap > 0 && level[static_cast<size_t>(e.to)] < 0) {
                    level[static_cast<size_t>(e.to)] = level[static_cast<size_t>(u)] + 1;
                    q.push(e.to);
                }
        }
        return level[static_cast<size_t>(t)] >= 0;
    }
    int dfs(int u, int t, int f) {
        if (u == t)
            return f;
        for (int& i = it[static_cast<size_t>(u)];
             i < static_cast<int>(g[static_cast<size_t>(u)].size()); ++i) {
            Edge& e = g[static_cast<size_t>(u)][static_cast<size_t>(i)];
            if (e.cap > 0 &&
                level[static_cast<size_t>(e.to)] == level[static_cast<size_t>(u)] + 1) {
                int got = dfs(e.to, t, std::min(f, e.cap));
                if (got > 0) {
                    e.cap -= got;
                    g[static_cast<size_t>(e.to)][static_cast<size_t>(e.rev)].cap += got;
                    return got;
                }
            }
        }
        return 0;
    }
    int maxflow(int s, int t) {
        int flow = 0, f;
        while (bfs(s, t)) {
            std::fill(it.begin(), it.end(), 0);
            while ((f = dfs(s, t, 1e9)) > 0)
                flow += f;
        }
        return flow;
    }
};

int bipartiteMatchingFlow(int nL, int nR, const std::vector<std::pair<int, int>>& edges) {
    int S = 0, T = nL + nR + 1;
    Dinic d(T + 1);
    for (int i = 1; i <= nL; ++i)
        d.addEdge(S, i, 1);
    for (int j = 1; j <= nR; ++j)
        d.addEdge(nL + j, T, 1);
    for (auto [u, v] : edges)
        d.addEdge(u, nL + v, 1);
    return d.maxflow(S, T);
}

int main() {
    std::cout << bipartiteMatchingFlow(2, 2, {{1, 1}, {1, 2}, {2, 2}}) << " (expected 2)\n";
    return 0;
}
