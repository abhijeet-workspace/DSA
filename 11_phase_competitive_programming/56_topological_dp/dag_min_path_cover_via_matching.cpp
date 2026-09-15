// DAG Minimum Path Cover via Bipartite Matching — teaching note+lab
// Split v -> L(v), R(v); edge u->v in DAG becomes L(u)->R(v); cover = n - matching.
#include <iostream>
#include <vector>

int nL, nR;
std::vector<std::vector<int>> bg;
std::vector<int> mt, vis;
int timer = 1;

bool tryKuhn(int v) {
    if (vis[static_cast<size_t>(v)] == timer)
        return false;
    vis[static_cast<size_t>(v)] = timer;
    for (int to : bg[static_cast<size_t>(v)]) {
        if (mt[static_cast<size_t>(to)] == -1 || tryKuhn(mt[static_cast<size_t>(to)])) {
            mt[static_cast<size_t>(to)] = v;
            return true;
        }
    }
    return false;
}

int minPathCoverDAG(int n, const std::vector<std::pair<int, int>>& edges) {
    nL = nR = n;
    bg.assign(static_cast<size_t>(n) + 1, {});
    for (auto [u, v] : edges)
        bg[static_cast<size_t>(u)].push_back(v);
    mt.assign(static_cast<size_t>(n) + 1, -1);
    vis.assign(static_cast<size_t>(n) + 1, 0);
    int match = 0;
    for (int v = 1; v <= n; ++v) {
        ++timer;
        if (tryKuhn(v))
            ++match;
    }
    return n - match;
}

int main() {
    // chain 1->2->3 : matching 2, cover 1
    std::cout << minPathCoverDAG(3, {{1, 2}, {2, 3}}) << " (expected 1)\n";
    // two edges disjoint 1->2, 3->4 : matching 2, cover 2
    std::cout << minPathCoverDAG(4, {{1, 2}, {3, 4}}) << " (expected 2)\n";
    return 0;
}
