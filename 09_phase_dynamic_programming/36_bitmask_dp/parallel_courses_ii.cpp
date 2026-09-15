// Parallel Courses II — https://leetcode.com/problems/parallel-courses-ii/
#include <algorithm>
#include <iostream>
#include <vector>

int minNumberOfSemesters(int n, std::vector<std::vector<int>>& relations, int k) {
    std::vector<int> pre(n, 0);
    for (auto& r : relations) {
        const int u = r[0] - 1, v = r[1] - 1;
        pre[static_cast<size_t>(v)] |= 1 << u;
    }
    const int N = 1 << n;
    std::vector<int> dp(N, n + 1);
    dp[0] = 0;
    for (int mask = 0; mask < N; ++mask) {
        if (dp[static_cast<size_t>(mask)] > n) continue;
        int can = 0;
        for (int i = 0; i < n; ++i) {
            if ((mask & (1 << i)) == 0 && (pre[static_cast<size_t>(i)] & mask) == pre[static_cast<size_t>(i)])
                can |= 1 << i;
        }
        // enumerate non-empty submasks of can with popcount <= k via iterating subsets
        for (int sub = can; sub > 0; sub = (sub - 1) & can) {
            if (__builtin_popcount(static_cast<unsigned>(sub)) <= k) {
                dp[static_cast<size_t>(mask | sub)] =
                    std::min(dp[static_cast<size_t>(mask | sub)], dp[static_cast<size_t>(mask)] + 1);
            }
        }
    }
    return dp[static_cast<size_t>(N - 1)];
}

int main() {
    std::vector<std::vector<int>> rel{{2, 1}, {3, 1}, {1, 4}};
    std::cout << minNumberOfSemesters(4, rel, 2) << " (expected 3)\n";
    return 0;
}
