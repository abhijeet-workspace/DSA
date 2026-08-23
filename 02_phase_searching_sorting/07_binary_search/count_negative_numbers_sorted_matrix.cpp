// Count Negative Numbers in a Sorted Matrix — https://leetcode.com/problems/count-negative-numbers-in-a-sorted-matrix/
// Each row (and column) is non-increasing; count negatives via per-row lower bound.
#include <iostream>
#include <vector>

int countNegatives(const std::vector<std::vector<int>>& grid) {
    int ans = 0;
    for (const auto& row : grid) {
        int lo = 0;
        int hi = static_cast<int>(row.size());
        while (lo < hi) {
            const int mid = lo + (hi - lo) / 2;
            if (row[static_cast<size_t>(mid)] < 0) {
                hi = mid; // first negative
            } else {
                lo = mid + 1;
            }
        }
        ans += static_cast<int>(row.size()) - lo;
    }
    return ans;
}

int main() {
    const std::vector<std::vector<int>> grid = {
        {4, 3, 2, -1},
        {3, 2, 1, -1},
        {1, 1, -1, -2},
        {-1, -1, -2, -3},
    };
    std::cout << countNegatives(grid) << " (expected 8)\n";
    return 0;
}
