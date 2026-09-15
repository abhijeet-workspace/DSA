// Remove Covered Intervals — https://leetcode.com/problems/remove-covered-intervals/
// Count intervals not covered by another; sort by start asc, end desc.
#include <algorithm>
#include <iostream>
#include <vector>

int removeCoveredIntervals(std::vector<std::vector<int>> intervals) {
    std::sort(intervals.begin(), intervals.end(),
              [](const std::vector<int>& a, const std::vector<int>& b) {
                  if (a[0] != b[0]) {
                      return a[0] < b[0]; // start ascending
                  }
                  return a[1] > b[1]; // same start → longer first
              });
    int count = 0;
    int max_end = -1;
    for (const auto& iv : intervals) {
        if (iv[1] > max_end) { // not covered by any earlier (wider) interval
            ++count;
            max_end = iv[1];
        }
    }
    return count;
}

int main() {
    std::cout << removeCoveredIntervals({{1, 4}, {3, 6}, {2, 8}}) << " (expected 2)\n";
    std::cout << removeCoveredIntervals({{1, 4}, {2, 3}}) << " (expected 1)\n";
    std::cout << removeCoveredIntervals({{1, 2}, {1, 4}, {3, 4}}) << " (expected 1)\n";
    return 0;
}
