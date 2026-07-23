// Merge Intervals — https://leetcode.com/problems/merge-intervals/
// Merge all overlapping intervals; return non-overlapping cover.
#include <algorithm>
#include <iostream>
#include <vector>

std::vector<std::vector<int>> merge(std::vector<std::vector<int>> intervals) {
    if (intervals.empty()) {
        return {};
    }
    std::sort(intervals.begin(), intervals.end()); // by start
    std::vector<std::vector<int>> merged;
    merged.push_back(intervals[0]);
    for (size_t i = 1; i < intervals.size(); ++i) {
        if (intervals[i][0] <= merged.back()[1]) { // overlap / touch
            merged.back()[1] = std::max(merged.back()[1], intervals[i][1]);
        } else {
            merged.push_back(intervals[i]);
        }
    }
    return merged;
}

int main() {
    auto r = merge({{1, 3}, {2, 6}, {8, 10}, {15, 18}});
    for (const auto& x : r) {
        std::cout << "[" << x[0] << "," << x[1] << "] ";
    }
    std::cout << "(expected [1,6] [8,10] [15,18])\n";
    return 0;
}
