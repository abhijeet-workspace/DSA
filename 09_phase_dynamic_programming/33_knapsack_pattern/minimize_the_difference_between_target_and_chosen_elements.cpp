// Minimize the Difference Between Target and Chosen Elements —
// https://leetcode.com/problems/minimize-the-difference-between-target-and-chosen-elements/
#include <algorithm>
#include <cmath>
#include <iostream>
#include <unordered_set>
#include <vector>

int minimizeTheDifference(std::vector<std::vector<int>>& mat, int target) {
    std::unordered_set<int> reach{0};
    for (auto& row : mat) {
        std::unordered_set<int> next;
        int mx = *std::max_element(row.begin(), row.end());
        for (int s : reach) {
            for (int v : row) {
                const int ns = s + v;
                if (ns <= target + mx)
                    next.insert(ns);
            }
        }
        reach.swap(next);
    }
    int best = 1e9;
    for (int s : reach)
        best = std::min(best, std::abs(s - target));
    return best;
}

int main() {
    std::vector<std::vector<int>> mat{{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    std::cout << minimizeTheDifference(mat, 13) << " (expected 0)\n";
    return 0;
}
