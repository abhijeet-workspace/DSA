// Number of Longest Increasing Subsequence — https://leetcode.com/problems/number-of-longest-increasing-subsequence/
#include <algorithm>
#include <iostream>
#include <vector>

int findNumberOfLIS(std::vector<int>& nums) {
    const int n = static_cast<int>(nums.size());
    if (n == 0) return 0;
    std::vector<int> len(n, 1), cnt(n, 1);
    int maxLen = 1;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < i; ++j) {
            if (nums[static_cast<size_t>(j)] >= nums[static_cast<size_t>(i)]) continue;
            if (len[static_cast<size_t>(j)] + 1 > len[static_cast<size_t>(i)]) {
                len[static_cast<size_t>(i)] = len[static_cast<size_t>(j)] + 1;
                cnt[static_cast<size_t>(i)] = cnt[static_cast<size_t>(j)];
            } else if (len[static_cast<size_t>(j)] + 1 == len[static_cast<size_t>(i)]) {
                cnt[static_cast<size_t>(i)] += cnt[static_cast<size_t>(j)];
            }
        }
        maxLen = std::max(maxLen, len[static_cast<size_t>(i)]);
    }
    int ans = 0;
    for (int i = 0; i < n; ++i)
        if (len[static_cast<size_t>(i)] == maxLen) ans += cnt[static_cast<size_t>(i)];
    return ans;
}

int main() {
    std::vector<int> nums{1, 3, 5, 4, 7};
    std::cout << findNumberOfLIS(nums) << " (expected 2)\n";
    return 0;
}
