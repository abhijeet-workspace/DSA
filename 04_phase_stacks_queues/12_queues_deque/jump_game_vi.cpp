// Jump Game VI — https://leetcode.com/problems/jump-game-vi/
// dp[i] = nums[i] + max(dp[i-k..i-1]); monotonic deque of dp indices.
#include <deque>
#include <iostream>
#include <vector>

int maxResult(const std::vector<int>& nums, int k) {
    const int n = static_cast<int>(nums.size());
    std::vector<int> dp(static_cast<size_t>(n));
    std::deque<int> dq; // indices, dp decreasing
    dp[0] = nums[0];
    dq.push_back(0);
    for (int i = 1; i < n; ++i) {
        while (!dq.empty() && dq.front() < i - k) {
            dq.pop_front();
        }
        dp[static_cast<size_t>(i)] = nums[static_cast<size_t>(i)] + dp[static_cast<size_t>(dq.front())];
        while (!dq.empty() && dp[static_cast<size_t>(dq.back())] <= dp[static_cast<size_t>(i)]) {
            dq.pop_back();
        }
        dq.push_back(i);
    }
    return dp[static_cast<size_t>(n - 1)];
}

int main() {
    std::cout << maxResult({1, -1, -2, 4, -7, 3}, 2) << " (expected 7)\n";
    std::cout << maxResult({10, -5, -2, 4, 0, 3}, 3) << " (expected 17)\n";
    std::cout << maxResult({1, -5, -20, 4, -1, 3, -6, -3}, 2) << " (expected 0)\n";
    return 0;
}
