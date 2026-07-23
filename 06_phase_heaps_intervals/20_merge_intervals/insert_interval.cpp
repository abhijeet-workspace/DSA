// Insert Interval — https://leetcode.com/problems/insert-interval/
// Intervals sorted non-overlapping; insert newInterval and merge overlaps.
#include <algorithm>
#include <iostream>
#include <vector>

std::vector<std::vector<int>> insert(std::vector<std::vector<int>>& intervals,
                                     std::vector<int> neu) {
    std::vector<std::vector<int>> res;
    size_t i = 0;
    const size_t n = intervals.size();
    while (i < n && intervals[i][1] < neu[0]) { // strictly before
        res.push_back(intervals[i++]);
    }
    while (i < n && intervals[i][0] <= neu[1]) { // merge overlaps
        neu[0] = std::min(neu[0], intervals[i][0]);
        neu[1] = std::max(neu[1], intervals[i][1]);
        ++i;
    }
    res.push_back(neu);
    while (i < n) { // append rest
        res.push_back(intervals[i++]);
    }
    return res;
}

int main() {
    std::vector<std::vector<int>> a = {{1, 3}, {6, 9}};
    auto r = insert(a, {2, 5});
    for (const auto& x : r) {
        std::cout << "[" << x[0] << "," << x[1] << "] ";
    }
    std::cout << "(expected [1,5] [6,9])\n";
    return 0;
}
