// Parallel Courses II — https://leetcode.com/problems/parallel-courses-ii/
// n courses 1..n, prerequisites, take up to k per semester; min semesters.
#include <algorithm>
#include <iostream>
#include <vector>

int minNumberOfSemesters(int n, const std::vector<std::vector<int>>& relations, int k) {
    std::vector<int> prereq(static_cast<size_t>(n), 0);
    for (const auto& r : relations) {
        int a = r[0] - 1, b = r[1] - 1;
        prereq[static_cast<size_t>(b)] |= (1 << a);
    }
    const int full = 1 << n;
    std::vector<int> dp(static_cast<size_t>(full), n + 1);
    dp[0] = 0;
    for (int mask = 0; mask < full; ++mask) {
        if (dp[static_cast<size_t>(mask)] > n)
            continue;
        int available = 0;
        for (int i = 0; i < n; ++i) {
            if ((mask & (1 << i)) == 0 &&
                (prereq[static_cast<size_t>(i)] & mask) == prereq[static_cast<size_t>(i)])
                available |= (1 << i);
        }
        // enumerate submasks of available with popcount <= k
        for (int sub = available; sub > 0; sub = (sub - 1) & available) {
            if (__builtin_popcount(static_cast<unsigned>(sub)) <= k) {
                dp[static_cast<size_t>(mask | sub)] = std::min(dp[static_cast<size_t>(mask | sub)],
                                                               dp[static_cast<size_t>(mask)] + 1);
            }
        }
    }
    return dp[static_cast<size_t>(full - 1)];
}

int main() {
    std::cout << minNumberOfSemesters(4, {{2, 1}, {3, 1}, {1, 4}}, 2) << " (expected 3)\n";
    return 0;
}
