// Maximum Number of Events That Can Be Attended II
// https://leetcode.com/problems/maximum-number-of-events-that-can-be-attended-ii/
// Attend at most k non-overlapping events; maximize value. DP + binary search next event.
#include <algorithm>
#include <iostream>
#include <vector>

int maxValue(std::vector<std::vector<int>>& events, int k) {
    std::sort(events.begin(), events.end()); // by start
    const int n = static_cast<int>(events.size());
    std::vector<int> starts(static_cast<size_t>(n));
    for (int i = 0; i < n; ++i) {
        starts[static_cast<size_t>(i)] = events[static_cast<size_t>(i)][0];
    }
    auto next_idx = [&](int i) {
        const int end = events[static_cast<size_t>(i)][1];
        int lo = i + 1;
        int hi = n;
        while (lo < hi) {
            const int mid = lo + (hi - lo) / 2;
            if (starts[static_cast<size_t>(mid)] > end) {
                hi = mid;
            } else {
                lo = mid + 1;
            }
        }
        return lo;
    };
    std::vector<std::vector<int>> dp(static_cast<size_t>(n + 1),
                                     std::vector<int>(static_cast<size_t>(k + 1), 0));
    for (int i = n - 1; i >= 0; --i) {
        const int nxt = next_idx(i);
        for (int t = 1; t <= k; ++t) {
            dp[static_cast<size_t>(i)][static_cast<size_t>(t)] =
                std::max(dp[static_cast<size_t>(i + 1)][static_cast<size_t>(t)],
                         events[static_cast<size_t>(i)][2] +
                             dp[static_cast<size_t>(nxt)][static_cast<size_t>(t - 1)]);
        }
    }
    return dp[0][static_cast<size_t>(k)];
}

int main() {
    std::vector<std::vector<int>> a = {{1, 2, 4}, {3, 4, 3}, {2, 3, 1}};
    std::vector<std::vector<int>> b = {{1, 2, 4}, {3, 4, 3}, {2, 3, 10}};
    std::cout << maxValue(a, 2) << " (expected 7)\n" << maxValue(b, 2) << " (expected 10)\n";
    return 0;
}
