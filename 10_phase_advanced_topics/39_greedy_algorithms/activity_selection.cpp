// Non-overlapping Intervals — min removals = n − max kept (greedy by earliest end)
// https://leetcode.com/problems/non-overlapping-intervals/
#include <iostream>
#include <vector>
#include <algorithm>

int eraseOverlapIntervals(std::vector<std::vector<int>> intervals) {
    if (intervals.empty()) return 0;
    std::sort(intervals.begin(), intervals.end(),
              [](const auto& a, const auto& b) { return a[1] < b[1]; });
    int keep = 1;
    int lastEnd = intervals[0][1];
    for (size_t i = 1; i < intervals.size(); ++i) {
        if (intervals[i][0] >= lastEnd) { // touch at endpoint = non-overlapping
            lastEnd = intervals[i][1];
            ++keep;
        }
    }
    return static_cast<int>(intervals.size()) - keep;
}

int main() {
    std::cout << eraseOverlapIntervals({{1, 2}, {2, 3}, {3, 4}, {1, 3}})
              << " (expected 1)\n";
    std::cout << eraseOverlapIntervals({{1, 2}, {1, 2}, {1, 2}})
              << " (expected 2)\n";
    std::cout << eraseOverlapIntervals({{1, 2}, {2, 3}})
              << " (expected 0)\n";
    return 0;
}
