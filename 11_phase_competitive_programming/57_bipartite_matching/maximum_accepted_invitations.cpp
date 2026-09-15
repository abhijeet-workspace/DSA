// Maximum Number of Accepted Invitations — LeetCode 1820 (premium)
// Pure bipartite matching boys->girls.
#include <iostream>
#include <vector>

int timer = 1;
std::vector<std::vector<int>> g;
std::vector<int> mt, vis;
bool tryKuhn(int v) {
    if (vis[static_cast<size_t>(v)] == timer)
        return false;
    vis[static_cast<size_t>(v)] = timer;
    for (int to : g[static_cast<size_t>(v)]) {
        if (mt[static_cast<size_t>(to)] == -1 || tryKuhn(mt[static_cast<size_t>(to)])) {
            mt[static_cast<size_t>(to)] = v;
            return true;
        }
    }
    return false;
}

int maximumInvitations(const std::vector<std::vector<int>>& grid) {
    int m = static_cast<int>(grid.size()), n = static_cast<int>(grid[0].size());
    g.assign(static_cast<size_t>(m), {});
    for (int i = 0; i < m; ++i)
        for (int j = 0; j < n; ++j)
            if (grid[static_cast<size_t>(i)][static_cast<size_t>(j)])
                g[static_cast<size_t>(i)].push_back(j);
    mt.assign(static_cast<size_t>(n), -1);
    vis.assign(static_cast<size_t>(m), 0);
    int match = 0;
    for (int i = 0; i < m; ++i) {
        ++timer;
        if (tryKuhn(i))
            ++match;
    }
    return match;
}

int main() {
    std::cout << maximumInvitations({{1, 1, 1}, {1, 0, 1}, {0, 0, 1}}) << " (expected 3)\n";
    return 0;
}
