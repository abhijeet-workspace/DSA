// Two Sum Less Than K — https://leetcode.com/problems/two-sum-less-than-k/
// Max nums[i]+nums[j] (i<j) that is < k, or -1. Sort + binary search companion.
#include <algorithm>
#include <iostream>
#include <vector>

int twoSumLessThanK(std::vector<int> nums, int k) {
    std::sort(nums.begin(), nums.end());
    int ans = -1;
    for (int i = 0; i < static_cast<int>(nums.size()); ++i) {
        const int need = k - nums[static_cast<size_t>(i)];
        int lo = i + 1;
        int hi = static_cast<int>(nums.size()) - 1;
        int best = -1;
        while (lo <= hi) {
            const int mid = lo + (hi - lo) / 2;
            if (nums[static_cast<size_t>(mid)] < need) {
                best = mid;
                lo = mid + 1;
            } else {
                hi = mid - 1;
            }
        }
        if (best != -1) {
            ans = std::max(ans, nums[static_cast<size_t>(i)] + nums[static_cast<size_t>(best)]);
        }
    }
    return ans;
}

int main() {
    std::cout << twoSumLessThanK({34, 23, 1, 24, 75, 33, 54, 8}, 60) << " (expected 58)\n"
              << twoSumLessThanK({10, 20, 30}, 15) << " (expected -1)\n";
    return 0;
}
