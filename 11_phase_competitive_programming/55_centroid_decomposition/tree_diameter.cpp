// Tree Diameter — LeetCode 1245 / CP classic
#include <iostream>
#include <vector>

std::pair<int, int> farthest(int src, const std::vector<std::vector<int>>& g) {
    int n = static_cast<int>(g.size());
    std::vector<int> dist(static_cast<size_t>(n), -1);
    std::vector<int> st = {src};
    dist[static_cast<size_t>(src)] = 0;
    int best = src;
    while (!st.empty()) {
        int u = st.back();
        st.pop_back();
        if (dist[static_cast<size_t>(u)] > dist[static_cast<size_t>(best)])
            best = u;
        for (int to : g[static_cast<size_t>(u)])
            if (dist[static_cast<size_t>(to)] < 0) {
                dist[static_cast<size_t>(to)] = dist[static_cast<size_t>(u)] + 1;
                st.push_back(to);
            }
    }
    return {best, dist[static_cast<size_t>(best)]};
}

int treeDiameter(const std::vector<std::vector<int>>& edges) {
    int n = static_cast<int>(edges.size()) + 1;
    std::vector<std::vector<int>> g(static_cast<size_t>(n));
    for (const auto& e : edges) {
        g[static_cast<size_t>(e[0])].push_back(e[1]);
        g[static_cast<size_t>(e[1])].push_back(e[0]);
    }
    auto [u, _] = farthest(0, g);
    auto [v, d] = farthest(u, g);
    (void)v;
    return d;
}

int main() {
    std::cout << treeDiameter({{0, 1}, {1, 2}, {2, 3}, {1, 4}}) << " (expected 3)\n";
    std::cout << treeDiameter({{0, 1}, {0, 2}}) << " (expected 2)\n";
    return 0;
}
