// Non-overlapping Intervals — https://leetcode.com/problems/non-overlapping-intervals/
// Min removals so remaining intervals do not overlap.
#include <algorithm>
#include <climits>
#include <iostream>
#include <vector>

int eraseOverlapIntervals(std::vector<std::vector<int>>& intervals) {
    std::sort(intervals.begin(), intervals.end(),
              [](const auto& a, const auto& b) { return a[1] < b[1]; }); // by end
    int keep = 0;
    int end = INT_MIN;
    for (const auto& it : intervals) {
        if (it[0] >= end) { // non-overlapping with last kept
            ++keep;
            end = it[1];
        }
    }
    return static_cast<int>(intervals.size()) - keep;
}

int main() {
    std::vector<std::vector<int>> a = {{1, 2}, {2, 3}, {3, 4}, {1, 3}};
    std::cout << eraseOverlapIntervals(a) << " (expected 1)\n";
    return 0;
}
