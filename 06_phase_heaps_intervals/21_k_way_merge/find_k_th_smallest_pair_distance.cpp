// Find K-th Smallest Pair Distance — https://leetcode.com/problems/find-k-th-smallest-pair-distance/
// Sort + binary search on distance; count pairs with diff <= mid (two pointers).
#include <algorithm>
#include <iostream>
#include <vector>

int smallestDistancePair(std::vector<int>& nums, int k) {
    std::sort(nums.begin(), nums.end());
    int lo = 0, hi = nums.back() - nums.front();
    auto countLE = [&](int mid) {
        int cnt = 0, j = 0;
        for (int i = 0; i < static_cast<int>(nums.size()); ++i) {
            while (j < static_cast<int>(nums.size()) && nums[static_cast<size_t>(j)] - nums[static_cast<size_t>(i)] <= mid) ++j;
            cnt += j - i - 1;
        }
        return cnt;
    };
    while (lo < hi) {
        int mid = lo + (hi - lo) / 2;
        if (countLE(mid) >= k) hi = mid;
        else lo = mid + 1;
    }
    return lo;
}

int main() {
    std::vector<int> nums = {1, 3, 1};
    std::cout << smallestDistancePair(nums, 1) << " (expected 0)\n";
    return 0;
}
