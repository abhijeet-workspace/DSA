// Maximum Profit in Job Scheduling —
// https://leetcode.com/problems/maximum-profit-in-job-scheduling/ Weighted interval scheduling:
// sort by end; DP + binary search previous compatible job.
#include <algorithm>
#include <iostream>
#include <tuple>
#include <vector>

int jobScheduling(std::vector<int> startTime, std::vector<int> endTime, std::vector<int> profit) {
    const int n = static_cast<int>(startTime.size());
    std::vector<std::tuple<int, int, int>> jobs;
    jobs.reserve(static_cast<size_t>(n));
    for (int i = 0; i < n; ++i) {
        jobs.emplace_back(endTime[static_cast<size_t>(i)], startTime[static_cast<size_t>(i)],
                          profit[static_cast<size_t>(i)]);
    }
    std::sort(jobs.begin(), jobs.end()); // by end time
    std::vector<int> ends(static_cast<size_t>(n));
    for (int i = 0; i < n; ++i) {
        ends[static_cast<size_t>(i)] = std::get<0>(jobs[static_cast<size_t>(i)]);
    }
    std::vector<int> dp(static_cast<size_t>(n));
    for (int i = 0; i < n; ++i) {
        const int start = std::get<1>(jobs[static_cast<size_t>(i)]);
        const int p = std::get<2>(jobs[static_cast<size_t>(i)]);
        int lo = 0;
        int hi = i - 1;
        int prev = -1;
        while (lo <= hi) {
            const int mid = lo + (hi - lo) / 2;
            if (ends[static_cast<size_t>(mid)] <= start) {
                prev = mid;
                lo = mid + 1;
            } else {
                hi = mid - 1;
            }
        }
        const int take = p + (prev == -1 ? 0 : dp[static_cast<size_t>(prev)]);
        const int skip = i == 0 ? 0 : dp[static_cast<size_t>(i - 1)];
        dp[static_cast<size_t>(i)] = std::max(take, skip);
    }
    return dp[static_cast<size_t>(n - 1)];
}

int main() {
    std::cout << jobScheduling({1, 2, 3, 3}, {3, 4, 5, 6}, {50, 10, 40, 70}) << " (expected 120)\n"
              << jobScheduling({1, 2, 3, 4, 6}, {3, 5, 10, 6, 9}, {20, 20, 100, 70, 60})
              << " (expected 150)\n";
    return 0;
}
