// Largest Divisible Subset — https://leetcode.com/problems/largest-divisible-subset/
#include <algorithm>
#include <iostream>
#include <vector>

std::vector<int> largestDivisibleSubset(std::vector<int>& nums) {
    std::sort(nums.begin(), nums.end());
    const int n = static_cast<int>(nums.size());
    std::vector<int> dp(n, 1), prev(n, -1);
    int best = 0, end = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < i; ++j) {
            if (nums[static_cast<size_t>(i)] % nums[static_cast<size_t>(j)] == 0 &&
                dp[static_cast<size_t>(j)] + 1 > dp[static_cast<size_t>(i)]) {
                dp[static_cast<size_t>(i)] = dp[static_cast<size_t>(j)] + 1;
                prev[static_cast<size_t>(i)] = j;
            }
        }
        if (dp[static_cast<size_t>(i)] > best) {
            best = dp[static_cast<size_t>(i)];
            end = i;
        }
    }
    std::vector<int> ans;
    for (int i = end; i >= 0; i = prev[static_cast<size_t>(i)]) {
        ans.push_back(nums[static_cast<size_t>(i)]);
        if (prev[static_cast<size_t>(i)] == -1) break;
    }
    std::reverse(ans.begin(), ans.end());
    return ans;
}

int main() {
    std::vector<int> nums{1, 2, 3};
    for (int x : largestDivisibleSubset(nums)) std::cout << x << ' ';
    std::cout << "(expected 1 2 or 1 3)\n";
    return 0;
}
