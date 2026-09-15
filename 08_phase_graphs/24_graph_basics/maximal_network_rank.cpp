// Maximal Network Rank — https://leetcode.com/problems/maximal-network-rank/
// Rank of cities a,b = deg(a)+deg(b) - (1 if edge a-b else 0). Maximize over pairs.
#include <iostream>
#include <vector>

int maximalNetworkRank(int n, const std::vector<std::vector<int>>& roads) {
    std::vector<int> deg(static_cast<size_t>(n), 0);
    std::vector<std::vector<char>> conn(static_cast<size_t>(n),
                                        std::vector<char>(static_cast<size_t>(n), 0));
    for (const auto& r : roads) {
        int a = r[0], b = r[1];
        ++deg[static_cast<size_t>(a)];
        ++deg[static_cast<size_t>(b)];
        conn[static_cast<size_t>(a)][static_cast<size_t>(b)] =
            conn[static_cast<size_t>(b)][static_cast<size_t>(a)] = 1;
    }
    int best = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            best =
                std::max(best, deg[static_cast<size_t>(i)] + deg[static_cast<size_t>(j)] -
                                   (conn[static_cast<size_t>(i)][static_cast<size_t>(j)] ? 1 : 0));
        }
    }
    return best;
}

int main() {
    std::cout << maximalNetworkRank(4, {{0, 1}, {0, 3}, {1, 2}, {1, 3}}) << " (expected 4)\n";
    return 0;
}
