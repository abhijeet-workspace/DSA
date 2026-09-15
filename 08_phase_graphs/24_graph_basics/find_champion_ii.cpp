// Find Champion II — https://leetcode.com/problems/find-champion-ii/
// Directed edges u→v mean u is stronger than v. Champion beats all (directly/indirectly): unique indegree-0.
#include <iostream>
#include <vector>

int findChampion(int n, const std::vector<std::vector<int>>& edges) {
    std::vector<int> indeg(static_cast<size_t>(n), 0);
    for (const auto& e : edges) ++indeg[static_cast<size_t>(e[1])];
    int champ = -1;
    for (int i = 0; i < n; ++i) {
        if (indeg[static_cast<size_t>(i)] == 0) {
            if (champ != -1) return -1; // more than one source
            champ = i;
        }
    }
    return champ;
}

int main() {
    std::cout << findChampion(3, {{0, 1}, {1, 2}}) << " (expected 0)\n";
    std::cout << findChampion(4, {{0, 2}, {1, 3}, {1, 2}}) << " (expected -1)\n";
    return 0;
}
