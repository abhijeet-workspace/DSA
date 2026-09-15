// Minimum Number of Work Sessions to Finish the Tasks —
// https://leetcode.com/problems/minimum-number-of-work-sessions-to-finish-the-tasks/
#include <algorithm>
#include <iostream>
#include <vector>

int minSessions(std::vector<int>& tasks, int sessionTime) {
    const int n = static_cast<int>(tasks.size());
    const int N = 1 << n;
    std::vector<int> sum(N, 0);
    for (int mask = 1; mask < N; ++mask) {
        const int b = __builtin_ctz(static_cast<unsigned>(mask));
        sum[static_cast<size_t>(mask)] =
            sum[static_cast<size_t>(mask ^ (1 << b))] + tasks[static_cast<size_t>(b)];
    }
    std::vector<int> dp(N, n + 1);
    dp[0] = 0;
    for (int mask = 1; mask < N; ++mask) {
        for (int sub = mask; sub; sub = (sub - 1) & mask) {
            if (sum[static_cast<size_t>(sub)] <= sessionTime) {
                dp[static_cast<size_t>(mask)] = std::min(dp[static_cast<size_t>(mask)],
                                                         dp[static_cast<size_t>(mask ^ sub)] + 1);
            }
        }
    }
    return dp[static_cast<size_t>(N - 1)];
}

int main() {
    std::vector<int> tasks{1, 2, 3};
    std::cout << minSessions(tasks, 3) << " (expected 2)\n";
    return 0;
}
