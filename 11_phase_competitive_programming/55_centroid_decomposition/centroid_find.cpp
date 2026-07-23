// Centroid Find — CP classic
// Find all centroids of an undirected tree (component sizes ≤ N/2).
#include <algorithm>
#include <iostream>
#include <vector>

struct Tree {
    int n;
    std::vector<std::vector<int>> g;
    std::vector<int> sz;

    explicit Tree(int n_) : n(n_), g(n_ + 1), sz(n_ + 1, 0) {}

    void addEdge(int u, int v) {
        g[static_cast<size_t>(u)].push_back(v);
        g[static_cast<size_t>(v)].push_back(u);
    }

    void dfsSize(int v, int p) {
        sz[static_cast<size_t>(v)] = 1;
        for (int to : g[static_cast<size_t>(v)]) {
            if (to == p) continue;
            dfsSize(to, v);
            sz[static_cast<size_t>(v)] += sz[static_cast<size_t>(to)];
        }
    }

    int componentSize(int ban, int start) const {
        std::vector<char> seen(static_cast<size_t>(n) + 1, 0);
        seen[static_cast<size_t>(ban)] = 1;
        seen[static_cast<size_t>(start)] = 1;
        int cnt = 0;
        std::vector<int> st = {start};
        while (!st.empty()) {
            int u = st.back();
            st.pop_back();
            ++cnt;
            for (int w : g[static_cast<size_t>(u)]) {
                if (!seen[static_cast<size_t>(w)]) {
                    seen[static_cast<size_t>(w)] = 1;
                    st.push_back(w);
                }
            }
        }
        return cnt;
    }

    bool isCentroid(int v) const {
        for (int to : g[static_cast<size_t>(v)]) {
            if (componentSize(v, to) > n / 2) return false;
        }
        return true;
    }

    std::vector<int> findCentroids() {
        dfsSize(1, 0);
        int v = 1;
        int p = 0;
        while (true) { // walk toward any child with size > N/2
            int heavy = -1;
            for (int to : g[static_cast<size_t>(v)]) {
                if (to == p) continue;
                if (sz[static_cast<size_t>(to)] > n / 2) {
                    heavy = to;
                    break;
                }
            }
            if (heavy < 0) break;
            p = v;
            v = heavy;
        }
        std::vector<int> cents;
        if (isCentroid(v)) cents.push_back(v);
        for (int to : g[static_cast<size_t>(v)]) {
            if (isCentroid(to)) cents.push_back(to); // even N: second centroid
        }
        std::sort(cents.begin(), cents.end());
        cents.erase(std::unique(cents.begin(), cents.end()), cents.end());
        return cents;
    }
};

int main() {
    Tree path(5);
    path.addEdge(1, 2);
    path.addEdge(2, 3);
    path.addEdge(3, 4);
    path.addEdge(4, 5);
    auto c1 = path.findCentroids();
    std::cout << "path centroids:";
    for (int c : c1) std::cout << " " << c;
    std::cout << " (expected 3)\n";

    Tree edge(2);
    edge.addEdge(1, 2);
    auto c2 = edge.findCentroids();
    std::cout << "edge centroids:";
    for (int c : c2) std::cout << " " << c;
    std::cout << " (expected 1 2)\n";
    return 0;
}
