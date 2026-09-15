// Critical Connections in a Network —
// https://leetcode.com/problems/critical-connections-in-a-network/ Find bridges in an undirected
// connected graph (Tarjan DFS low-link).
#include <algorithm>
#include <iostream>
#include <vector>

class Solution {
    std::vector<std::vector<int>> adj_;
    std::vector<int> disc_, low_;
    std::vector<std::vector<int>> bridges_;
    int timer_ = 0;

    void dfs(int u, int parent) {
        disc_[static_cast<size_t>(u)] = low_[static_cast<size_t>(u)] = timer_++;
        for (int v : adj_[static_cast<size_t>(u)]) {
            if (v == parent) {
                continue;
            }
            if (disc_[static_cast<size_t>(v)] == -1) {
                dfs(v, u);
                low_[static_cast<size_t>(u)] =
                    std::min(low_[static_cast<size_t>(u)], low_[static_cast<size_t>(v)]);
                if (low_[static_cast<size_t>(v)] > disc_[static_cast<size_t>(u)]) {
                    bridges_.push_back({u, v});
                }
            } else {
                low_[static_cast<size_t>(u)] =
                    std::min(low_[static_cast<size_t>(u)], disc_[static_cast<size_t>(v)]);
            }
        }
    }

  public:
    std::vector<std::vector<int>>
    criticalConnections(int n, const std::vector<std::vector<int>>& connections) {
        adj_.assign(static_cast<size_t>(n), {});
        for (const auto& e : connections) {
            adj_[static_cast<size_t>(e[0])].push_back(e[1]);
            adj_[static_cast<size_t>(e[1])].push_back(e[0]);
        }
        disc_.assign(static_cast<size_t>(n), -1);
        low_.assign(static_cast<size_t>(n), 0);
        bridges_.clear();
        timer_ = 0;
        dfs(0, -1);
        return bridges_;
    }
};

int main() {
    Solution sol;
    const auto bridges = sol.criticalConnections(4, {{0, 1}, {1, 2}, {2, 0}, {1, 3}});
    for (const auto& b : bridges) {
        std::cout << b[0] << "-" << b[1] << ' ';
    }
    std::cout << "(expected 1-3)\n";
    return 0;
}
