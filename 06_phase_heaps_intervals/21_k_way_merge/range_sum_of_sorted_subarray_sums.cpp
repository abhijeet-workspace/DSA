// Range Sum of Sorted Subarray Sums —
// https://leetcode.com/problems/range-sum-of-sorted-subarray-sums/ Generate all subarray sums,
// sort, sum nums[left..right] (1-indexed) mod 1e9+7.
#include <algorithm>
#include <iostream>
#include <vector>

int rangeSum(std::vector<int>& nums, int n, int left, int right) {
    std::vector<int> sums;
    sums.reserve(static_cast<size_t>(n * (n + 1) / 2));
    for (int i = 0; i < n; ++i) {
        int s = 0;
        for (int j = i; j < n; ++j) {
            s += nums[static_cast<size_t>(j)];
            sums.push_back(s);
        }
    }
    std::sort(sums.begin(), sums.end());
    const int MOD = 1'000'000'007;
    long long ans = 0;
    for (int i = left - 1; i <= right - 1; ++i) {
        ans = (ans + sums[static_cast<size_t>(i)]) % MOD;
    }
    return static_cast<int>(ans);
}

int main() {
    std::vector<int> nums = {1, 2, 3, 4};
    std::cout << rangeSum(nums, 4, 1, 5) << " (expected 13)\n";
    return 0;
}
