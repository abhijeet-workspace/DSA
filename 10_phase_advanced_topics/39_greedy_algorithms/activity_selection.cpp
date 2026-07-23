// Activity Selection — max non-overlapping intervals (greedy by earliest end)
// Related: https://leetcode.com/problems/non-overlapping-intervals/
#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>

int activitySelection(std::vector<std::pair<int, int>> intervals) {
    if (intervals.empty()) return 0;
    std::sort(intervals.begin(), intervals.end(),
              [](const auto& a, const auto& b) { return a.second < b.second; });
    int count = 1;
    int lastEnd = intervals[0].second;
    for (size_t i = 1; i < intervals.size(); ++i) {
        if (intervals[i].first >= lastEnd) { // no overlap
            lastEnd = intervals[i].second;
            ++count;
        }
    }
    return count;
}

int main() {
    std::cout << activitySelection({{1, 3}, {2, 4}, {3, 5}, {0, 6}}) << " (expected 2)\n";
    return 0;
}
