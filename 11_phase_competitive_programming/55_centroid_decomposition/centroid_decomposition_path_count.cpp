// Centroid Decomposition Path Count — CP classic
// Count unordered pairs with dist(u,v) == K via CD + depth freq.
#include <iostream>
#include <vector>

struct PathCountCD {
    int n, K;
    std::vector<std::vector<int>> g;
    std::vector<int> sz, dead;
    long long ans = 0;

    PathCountCD(int n_, int K_) : n(n_), K(K_), g(n_ + 1), sz(n_ + 1), dead(n_ + 1, 0) {}

    void addEdge(int u, int v) {
        g[static_cast<size_t>(u)].push_back(v);
        g[static_cast<size_t>(v)].push_back(u);
    }

    int dfsSize(int v, int p) {
        sz[static_cast<size_t>(v)] = 1;
        for (int to : g[static_cast<size_t>(v)])
            if (to != p && !dead[static_cast<size_t>(to)])
                sz[static_cast<size_t>(v)] += dfsSize(to, v);
        return sz[static_cast<size_t>(v)];
    }

    int findCentroid(int v, int p, int comp) {
        for (int to : g[static_cast<size_t>(v)])
            if (to != p && !dead[static_cast<size_t>(to)] && sz[static_cast<size_t>(to)] > comp / 2)
                return findCentroid(to, v, comp);
        return v;
    }

    void collect(int v, int p, int d, std::vector<int>& depths) {
        if (d > K)
            return;
        depths.push_back(d);
        for (int to : g[static_cast<size_t>(v)])
            if (to != p && !dead[static_cast<size_t>(to)])
                collect(to, v, d + 1, depths);
    }

    void solveAt(int c) {
        std::vector<int> freq(static_cast<size_t>(K) + 1, 0);
        freq[0] = 1;
        for (int to : g[static_cast<size_t>(c)]) {
            if (dead[static_cast<size_t>(to)])
                continue;
            std::vector<int> depths;
            collect(to, c, 1, depths);
            for (int d : depths)
                if (d <= K)
                    ans += freq[static_cast<size_t>(K - d)];
            for (int d : depths)
                if (d <= K)
                    ++freq[static_cast<size_t>(d)];
        }
    }

    void build(int entry) {
        int comp = dfsSize(entry, -1);
        int c = findCentroid(entry, -1, comp);
        solveAt(c);
        dead[static_cast<size_t>(c)] = 1;
        for (int to : g[static_cast<size_t>(c)])
            if (!dead[static_cast<size_t>(to)])
                build(to);
    }

    long long count() {
        ans = 0;
        build(1);
        return ans;
    }
};

int main() {
    PathCountCD t(4, 2);
    t.addEdge(1, 2);
    t.addEdge(2, 3);
    t.addEdge(3, 4);
    std::cout << t.count() << " (expected 2)\n";
    return 0;
}
