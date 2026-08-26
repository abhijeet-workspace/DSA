// Find Missing and Repeated Values — LC 2965
// n×n grid holds 1..n² once each, except one value twice and one missing.
#include <iostream>
#include <vector>

std::vector<int> findMissingAndRepeatedValues(const std::vector<std::vector<int>>& grid) {
    const int n = static_cast<int>(grid.size());
    const int m = n * n;
    std::vector<int> cnt(static_cast<size_t>(m + 1), 0);
    int repeated = 0;

    for (const auto& row : grid) {
        for (int x : row) {
            if (++cnt[static_cast<size_t>(x)] == 2) {
                repeated = x;
            }
        }
    }

    int missing = 0;
    for (int v = 1; v <= m; ++v) {
        if (cnt[static_cast<size_t>(v)] == 0) {
            missing = v;
            break;
        }
    }
    return {repeated, missing};
}

int main() {
    std::vector<std::vector<int>> g1 = {{1, 3}, {2, 2}};
    auto a1 = findMissingAndRepeatedValues(g1);
    std::cout << a1[0] << " " << a1[1] << " (expected 2 4)\n";

    std::vector<std::vector<int>> g2 = {{9, 1, 7}, {8, 9, 2}, {3, 4, 6}};
    auto a2 = findMissingAndRepeatedValues(g2);
    std::cout << a2[0] << " " << a2[1] << " (expected 9 5)\n";
    return 0;
}
