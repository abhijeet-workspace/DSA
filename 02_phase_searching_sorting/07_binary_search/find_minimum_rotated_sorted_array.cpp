// Find Minimum in Rotated Sorted Array — https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/
// Distinct rotated ascending nums; return the minimum value.
#include <iostream>
#include <vector>

int findMin(const std::vector<int>& nums) {
    int lo = 0;
    int hi = static_cast<int>(nums.size()) - 1;
    while (lo < hi) {
        const int mid = lo + (hi - lo) / 2;
        if (nums[static_cast<size_t>(mid)] > nums[static_cast<size_t>(hi)]) {
            lo = mid + 1; // min in (mid, hi]
        } else {
            hi = mid; // min in [lo, mid]
        }
    }
    return nums[static_cast<size_t>(lo)];
}

int main() {
    std::cout << findMin({3, 4, 5, 1, 2}) << " (expected 1)\n"
              << findMin({4, 5, 6, 7, 0, 1, 2}) << " (expected 0)\n"
              << findMin({11, 13, 15, 17}) << " (expected 11)\n";
    return 0;
}
