// Find Minimum in Rotated Sorted Array II — https://leetcode.com/problems/find-minimum-in-rotated-sorted-array-ii/
// Rotated with duplicates; shrink linearly when nums[mid] == nums[hi].
#include <iostream>
#include <vector>

int findMin(const std::vector<int>& nums) {
    int lo = 0;
    int hi = static_cast<int>(nums.size()) - 1;
    while (lo < hi) {
        const int mid = lo + (hi - lo) / 2;
        if (nums[static_cast<size_t>(mid)] > nums[static_cast<size_t>(hi)]) {
            lo = mid + 1;
        } else if (nums[static_cast<size_t>(mid)] < nums[static_cast<size_t>(hi)]) {
            hi = mid;
        } else {
            --hi; // duplicates: cannot tell which side
        }
    }
    return nums[static_cast<size_t>(lo)];
}

int main() {
    std::cout << findMin({1, 3, 5}) << " (expected 1)\n"
              << findMin({2, 2, 2, 0, 1}) << " (expected 0)\n";
    return 0;
}
