// Longest Increasing Subsequence (patience / tails) — https://leetcode.com/problems/longest-increasing-subsequence/
// tails[len] = smallest tail of an IS of length len+1; binary search the insert point.
#include <algorithm>
#include <iostream>
#include <vector>

int lengthOfLIS(const std::vector<int>& nums) {
    std::vector<int> tails;
    for (int x : nums) {
        auto it = std::lower_bound(tails.begin(), tails.end(), x);
        if (it == tails.end()) {
            tails.push_back(x);
        } else {
            *it = x;
        }
    }
    return static_cast<int>(tails.size());
}

int main() {
    std::cout << lengthOfLIS({10, 9, 2, 5, 3, 7, 101, 18}) << " (expected 4)\n"
              << lengthOfLIS({0, 1, 0, 3, 2, 3}) << " (expected 4)\n";
    return 0;
}
