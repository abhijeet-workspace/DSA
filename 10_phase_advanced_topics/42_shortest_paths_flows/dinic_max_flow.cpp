// Dinic max flow — BFS level graph + DFS blocking flows
#include <algorithm>
#include <climits>
#include <iostream>
#include <queue>
#include <vector>

struct Dinic {
    struct Edge {
        int to;
        int rev;
        long long cap;
    };
    int N = 0;
    int s = 0;
    int t = 0;
    std::vector<std::vector<Edge>> g;
    std::vector<int> level;
    std::vector<int> it;

    explicit Dinic(int n) : N(n), g(n), level(n), it(n) {}

    void addEdge(int u, int v, long long c) {
        Edge a{v, static_cast<int>(g[v].size()), c};
        Edge b{u, static_cast<int>(g[u].size()), 0};
        g[u].push_back(a);
        g[v].push_back(b);
    }

    bool bfs() {
        std::fill(level.begin(), level.end(), -1);
        std::queue<int> q;
        level[s] = 0;
        q.push(s);
        while (!q.empty()) {
            int v = q.front();
            q.pop();
            for (const Edge& e : g[v]) {
                if (e.cap > 0 && level[e.to] < 0) {
                    level[e.to] = level[v] + 1;
                    q.push(e.to);
                }
            }
        }
        return level[t] >= 0;
    }

    long long dfs(int v, long long f) {
        if (!f || v == t) {
            return f;
        }
        for (int& i = it[v]; i < static_cast<int>(g[v].size()); ++i) {
            Edge& e = g[v][i];
            if (e.cap > 0 && level[v] < level[e.to]) {
                long long ret = dfs(e.to, std::min(f, e.cap));
                if (ret) {
                    e.cap -= ret;
                    g[e.to][e.rev].cap += ret;
                    return ret;
                }
            }
        }
        return 0;
    }

    long long maxflow(int S, int T) {
        s = S;
        t = T;
        long long flow = 0;
        while (bfs()) {
            std::fill(it.begin(), it.end(), 0);
            while (long long f = dfs(s, LLONG_MAX / 4)) {
                flow += f;
            }
        }
        return flow;
    }
};

int main() {
    Dinic d(4);
    d.addEdge(0, 1, 10);
    d.addEdge(0, 2, 5);
    d.addEdge(1, 3, 8);
    d.addEdge(2, 3, 10);
    d.addEdge(1, 2, 4);
    std::cout << "maxflow=" << d.maxflow(0, 3) << " (expected 15)\n";
    return 0;
}
