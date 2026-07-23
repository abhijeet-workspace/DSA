// Tree Paths of Length K — CP classic (CSES / CF style)
// Count unordered pairs {u,v} with dist(u,v)==K via centroid decomposition.
#include <iostream>
#include <vector>

struct PathCountK {
    int n;
    int K;
    std::vector<std::vector<int>> g;
    std::vector<int> sz, dead;
    long long answer = 0;

    PathCountK(int n_, int K_)
        : n(n_), K(K_), g(n_ + 1), sz(n_ + 1, 0), dead(n_ + 1, 0) {}

    void addEdge(int u, int v) {
        g[static_cast<size_t>(u)].push_back(v);
        g[static_cast<size_t>(v)].push_back(u);
    }

    int dfsSize(int v, int p) {
        sz[static_cast<size_t>(v)] = 1;
        for (int to : g[static_cast<size_t>(v)]) {
            if (to == p || dead[static_cast<size_t>(to)]) continue;
            sz[static_cast<size_t>(v)] += dfsSize(to, v);
        }
        return sz[static_cast<size_t>(v)];
    }

    int findCentroid(int v, int p, int comp) {
        for (int to : g[static_cast<size_t>(v)]) {
            if (to == p || dead[static_cast<size_t>(to)]) continue;
            if (sz[static_cast<size_t>(to)] > comp / 2)
                return findCentroid(to, v, comp);
        }
        return v;
    }

    void collect(int v, int p, int depth, std::vector<int>& depths) {
        if (depth > K) return;
        depths.push_back(depth);
        for (int to : g[static_cast<size_t>(v)]) {
            if (to == p || dead[static_cast<size_t>(to)]) continue;
            collect(to, v, depth + 1, depths);
        }
    }

    void countThrough(int c) {
        std::vector<int> freq(static_cast<size_t>(K) + 1, 0);
        freq[0] = 1; // centroid at depth 0
        for (int to : g[static_cast<size_t>(c)]) {
            if (dead[static_cast<size_t>(to)]) continue;
            std::vector<int> depths;
            collect(to, c, 1, depths);
            for (int d : depths) { // pairs across different subtrees
                if (K - d >= 0 && K - d <= K) answer += freq[static_cast<size_t>(K - d)];
            }
            for (int d : depths) {
                if (d <= K) ++freq[static_cast<size_t>(d)];
            }
        }
    }

    void decompose(int entry) {
        int comp = dfsSize(entry, -1);
        int c = findCentroid(entry, -1, comp);
        countThrough(c);
        dead[static_cast<size_t>(c)] = 1;
        for (int to : g[static_cast<size_t>(c)]) {
            if (!dead[static_cast<size_t>(to)]) decompose(to);
        }
    }

    long long solve() {
        answer = 0;
        std::fill(dead.begin(), dead.end(), 0);
        decompose(1);
        return answer;
    }
};

int main() {
    PathCountK a(4, 2);
    a.addEdge(1, 2);
    a.addEdge(2, 3);
    a.addEdge(3, 4);
    std::cout << "paths_len_2=" << a.solve() << " (expected 2)\n";

    PathCountK b(4, 2);
    b.addEdge(1, 2);
    b.addEdge(1, 3);
    b.addEdge(1, 4);
    std::cout << "star_paths_len_2=" << b.solve() << " (expected 3)\n";
    return 0;
}
