// Distance-K Nodes via Centroid — teaching lab
// Count unordered pairs at exact distance K (related to LC 863 framing).
#include <iostream>
#include <vector>

struct DistK {
    int n, K;
    std::vector<std::vector<int>> g;
    std::vector<int> sz, dead;
    long long total_pairs = 0;

    DistK(int n_, int K_) : n(n_), K(K_), g(n_ + 1), sz(n_ + 1), dead(n_ + 1, 0) {}
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
    void collect(int v, int p, int d, std::vector<int>& dep) {
        if (d > K)
            return;
        dep.push_back(d);
        for (int to : g[static_cast<size_t>(v)])
            if (to != p && !dead[static_cast<size_t>(to)])
                collect(to, v, d + 1, dep);
    }
    void at(int c) {
        std::vector<long long> freq(static_cast<size_t>(K) + 1, 0);
        freq[0] = 1;
        for (int to : g[static_cast<size_t>(c)]) {
            if (dead[static_cast<size_t>(to)])
                continue;
            std::vector<int> dep;
            collect(to, c, 1, dep);
            for (int d : dep)
                if (d <= K)
                    total_pairs += freq[static_cast<size_t>(K - d)];
            for (int d : dep)
                if (d <= K)
                    ++freq[static_cast<size_t>(d)];
        }
    }
    void build(int e) {
        int comp = dfsSize(e, -1);
        int c = findCentroid(e, -1, comp);
        at(c);
        dead[static_cast<size_t>(c)] = 1;
        for (int to : g[static_cast<size_t>(c)])
            if (!dead[static_cast<size_t>(to)])
                build(to);
    }
    long long countPairs() {
        total_pairs = 0;
        std::fill(dead.begin(), dead.end(), 0);
        build(1);
        return total_pairs;
    }
};

int main() {
    DistK t(5, 2);
    t.addEdge(1, 2);
    t.addEdge(1, 3);
    t.addEdge(1, 4);
    t.addEdge(1, 5);
    std::cout << t.countPairs() << " (expected 6)\n";
    return 0;
}
