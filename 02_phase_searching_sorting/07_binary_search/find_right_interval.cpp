// Find Right Interval — https://leetcode.com/problems/find-right-interval/
// For each interval i, find the interval with smallest start >= end_i (or -1).
#include <algorithm>
#include <iostream>
#include <vector>
#include <utility>

std::vector<int> findRightInterval(const std::vector<std::vector<int>>& intervals) {
    const int n = static_cast<int>(intervals.size());
    std::vector<std::pair<int, int>> starts; // {start, index}
    starts.reserve(static_cast<size_t>(n));
    for (int i = 0; i < n; ++i) {
        starts.push_back({intervals[static_cast<size_t>(i)][0], i});
    }
    std::sort(starts.begin(), starts.end());
    std::vector<int> ans(static_cast<size_t>(n), -1);
    for (int i = 0; i < n; ++i) {
        const int end = intervals[static_cast<size_t>(i)][1];
        int lo = 0;
        int hi = n;
        while (lo < hi) {
            const int mid = lo + (hi - lo) / 2;
            if (starts[static_cast<size_t>(mid)].first >= end) {
                hi = mid;
            } else {
                lo = mid + 1;
            }
        }
        if (lo < n) {
            ans[static_cast<size_t>(i)] = starts[static_cast<size_t>(lo)].second;
        }
    }
    return ans;
}

int main() {
    const auto a = findRightInterval({{1, 2}});
    const auto b = findRightInterval({{3, 4}, {2, 3}, {1, 2}});
    std::cout << a[0] << " (expected -1)\n"
              << b[0] << " " << b[1] << " " << b[2] << " (expected -1 0 1)\n";
    return 0;
}
