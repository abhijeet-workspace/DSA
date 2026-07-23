// Floyd vs Johnson Demo — teaching comparison
// Same small digraph: APSP via Floyd–Warshall and Johnson; confirm equality.
#include <algorithm>
#include <iostream>
#include <limits>
#include <queue>
#include <vector>

const long long INF = std::numeric_limits<long long>::max() / 4;

struct Edge {
    int u, v;
    long long w;
};

std::vector<std::vector<long long>> floyd(
    int n, const std::vector<std::vector<long long>>& init) {
    auto d = init;
    for (int k = 0; k < n; ++k)
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                if (d[static_cast<size_t>(i)][static_cast<size_t>(k)] < INF
                    && d[static_cast<size_t>(k)][static_cast<size_t>(j)] < INF)
                    d[static_cast<size_t>(i)][static_cast<size_t>(j)] = std::min(
                        d[static_cast<size_t>(i)][static_cast<size_t>(j)],
                        d[static_cast<size_t>(i)][static_cast<size_t>(k)]
                            + d[static_cast<size_t>(k)][static_cast<size_t>(j)]);
    return d;
}

bool johnson(int n, const std::vector<Edge>& edges,
             std::vector<std::vector<long long>>& dist) {
    std::vector<Edge> bf = edges;
    for (int v = 0; v < n; ++v) bf.push_back({n, v, 0});
    std::vector<long long> h(static_cast<size_t>(n) + 1, INF);
    h[static_cast<size_t>(n)] = 0;
    for (int i = 0; i < n; ++i)
        for (const Edge& e : bf)
            if (h[static_cast<size_t>(e.u)] < INF
                && h[static_cast<size_t>(e.u)] + e.w < h[static_cast<size_t>(e.v)])
                h[static_cast<size_t>(e.v)] = h[static_cast<size_t>(e.u)] + e.w;
    for (const Edge& e : bf)
        if (h[static_cast<size_t>(e.u)] < INF
            && h[static_cast<size_t>(e.u)] + e.w < h[static_cast<size_t>(e.v)])
            return false;

    std::vector<std::vector<std::pair<int, long long>>> radj(n);
    for (const Edge& e : edges)
        radj[static_cast<size_t>(e.u)].push_back(
            {e.v, e.w + h[static_cast<size_t>(e.u)] - h[static_cast<size_t>(e.v)]});

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
        for (int v = 0; v < n; ++v)
            if (d[static_cast<size_t>(v)] < INF)
                dist[static_cast<size_t>(s)][static_cast<size_t>(v)] =
                    d[static_cast<size_t>(v)] - h[static_cast<size_t>(s)] + h[static_cast<size_t>(v)];
    }
    return true;
}

static void printMat(const char* name,
                     const std::vector<std::vector<long long>>& d) {
    std::cout << name << ":\n";
    for (size_t i = 0; i < d.size(); ++i) {
        for (size_t j = 0; j < d[i].size(); ++j) {
            if (j) std::cout << " ";
            if (d[i][j] >= INF / 2) std::cout << "INF";
            else std::cout << d[i][j];
        }
        std::cout << "\n";
    }
}

int main() {
    int n = 4;
    std::vector<Edge> edges = {{0, 1, 4}, {0, 2, 5}, {1, 2, -2}, {1, 3, 3}, {2, 3, 4}};

    std::vector<std::vector<long long>> init(n, std::vector<long long>(n, INF));
    for (int i = 0; i < n; ++i) init[static_cast<size_t>(i)][static_cast<size_t>(i)] = 0;
    for (const Edge& e : edges)
        init[static_cast<size_t>(e.u)][static_cast<size_t>(e.v)] =
            std::min(init[static_cast<size_t>(e.u)][static_cast<size_t>(e.v)], e.w);

    auto fw = floyd(n, init);
    std::vector<std::vector<long long>> jh;
    bool ok = johnson(n, edges, jh);
    std::cout << "johnson_ok=" << (ok ? 1 : 0) << " (expected 1)\n";
    printMat("Floyd", fw);
    printMat("Johnson", jh);

    bool same = true;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            if (fw[static_cast<size_t>(i)][static_cast<size_t>(j)]
                != jh[static_cast<size_t>(i)][static_cast<size_t>(j)])
                same = false;
    std::cout << "matrices_equal=" << (same ? 1 : 0) << " (expected 1)\n";
    return 0;
}
