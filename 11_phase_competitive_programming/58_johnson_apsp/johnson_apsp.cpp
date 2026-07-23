// Johnson APSP — related to LC 787 / 1334 style shortest-path ideas
// All-pairs shortest paths via potentials + Dijkstra; detect negative cycles.
#include <iostream>
#include <limits>
#include <queue>
#include <utility>
#include <vector>

struct Edge {
    int u, v;
    long long w;
};

struct Johnson {
    int n;
    std::vector<Edge> edges;
    std::vector<std::vector<std::pair<int, long long>>> adj;

    explicit Johnson(int n_) : n(n_), adj(n_) {}

    void addEdge(int u, int v, long long w) {
        edges.push_back({u, v, w});
        adj[static_cast<size_t>(u)].push_back({v, w});
    }

    bool apsp(std::vector<std::vector<long long>>& dist) {
        const long long INF = std::numeric_limits<long long>::max() / 4;

        std::vector<Edge> bf = edges;
        for (int v = 0; v < n; ++v) bf.push_back({n, v, 0}); // super = n
        std::vector<long long> h(static_cast<size_t>(n) + 1, INF);
        h[static_cast<size_t>(n)] = 0;
        for (int i = 0; i < n; ++i) {
            for (const Edge& e : bf) {
                if (h[static_cast<size_t>(e.u)] == INF) continue;
                if (h[static_cast<size_t>(e.u)] + e.w < h[static_cast<size_t>(e.v)])
                    h[static_cast<size_t>(e.v)] = h[static_cast<size_t>(e.u)] + e.w;
            }
        }
        for (const Edge& e : bf) {
            if (h[static_cast<size_t>(e.u)] != INF
                && h[static_cast<size_t>(e.u)] + e.w < h[static_cast<size_t>(e.v)]) {
                return false;
            }
        }

        std::vector<std::vector<std::pair<int, long long>>> radj(n);
        for (const Edge& e : edges) {
            long long nw = e.w + h[static_cast<size_t>(e.u)] - h[static_cast<size_t>(e.v)];
            radj[static_cast<size_t>(e.u)].push_back({e.v, nw});
        }

        dist.assign(n, std::vector<long long>(n, INF));
        for (int s = 0; s < n; ++s) {
            std::vector<long long> d(n, INF);
            d[static_cast<size_t>(s)] = 0;
            using Node = std::pair<long long, int>;
            std::priority_queue<Node, std::vector<Node>, std::greater<Node>> pq;
            pq.push({0, s});
            while (!pq.empty()) {
                auto [du, u] = pq.top();
                pq.pop();
                if (du != d[static_cast<size_t>(u)]) continue;
                for (auto [v, w] : radj[static_cast<size_t>(u)]) {
                    if (d[static_cast<size_t>(u)] + w < d[static_cast<size_t>(v)]) {
                        d[static_cast<size_t>(v)] = d[static_cast<size_t>(u)] + w;
                        pq.push({d[static_cast<size_t>(v)], v});
                    }
                }
            }
            for (int v = 0; v < n; ++v) {
                if (d[static_cast<size_t>(v)] == INF) dist[static_cast<size_t>(s)][static_cast<size_t>(v)] = INF;
                else dist[static_cast<size_t>(s)][static_cast<size_t>(v)] =
                    d[static_cast<size_t>(v)] - h[static_cast<size_t>(s)] + h[static_cast<size_t>(v)];
            }
        }
        return true;
    }
};

int main() {
    Johnson j(3);
    j.addEdge(0, 1, 1);
    j.addEdge(1, 2, -1);
    j.addEdge(0, 2, 3);
    std::vector<std::vector<long long>> dist;
    bool ok = j.apsp(dist);
    std::cout << "ok=" << (ok ? 1 : 0) << " (expected 1)\n";
    if (ok) {
        std::cout << "d[0][2]=" << dist[0][2] << " (expected 0)\n";
        std::cout << "d[0][1]=" << dist[0][1] << " (expected 1)\n";
    }

    Johnson bad(2);
    bad.addEdge(0, 1, 1);
    bad.addEdge(1, 0, -2);
    std::vector<std::vector<long long>> dist2;
    bool ok2 = bad.apsp(dist2);
    std::cout << "neg_cycle_detected=" << (ok2 ? 0 : 1) << " (expected 1)\n";
    return 0;
}
