// Kuhn Maximum Matching — CP classic
// Maximum bipartite matching via DFS augmenting paths (O(VE)).
#include <iostream>
#include <vector>

int nL, nR;
std::vector<std::vector<int>> g;
std::vector<int> mt, vis;
int timer = 1;

bool tryKuhn(int v) {
    if (vis[static_cast<size_t>(v)] == timer) return false;
    vis[static_cast<size_t>(v)] = timer;
    for (int to : g[static_cast<size_t>(v)]) {
        if (mt[static_cast<size_t>(to)] == -1 || tryKuhn(mt[static_cast<size_t>(to)])) {
            mt[static_cast<size_t>(to)] = v;
            return true;
        }
    }
    return false;
}

int maxMatching() {
    mt.assign(static_cast<size_t>(nR) + 1, -1);
    vis.assign(static_cast<size_t>(nL) + 1, 0);
    int match = 0;
    for (int v = 1; v <= nL; ++v) {
        ++timer; // fresh visit stamp per left attempt
        if (tryKuhn(v)) ++match;
    }
    return match;
}

int main() {
    nL = 2;
    nR = 2;
    g.assign(static_cast<size_t>(nL) + 1, {});
    g[1] = {1, 2};
    g[2] = {2};
    std::cout << maxMatching() << " (expected 2)\n";
    return 0;
}
