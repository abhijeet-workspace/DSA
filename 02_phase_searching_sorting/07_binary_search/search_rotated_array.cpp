// Search in Rotated Sorted Array — https://leetcode.com/problems/search-in-rotated-sorted-array/
// Distinct rotated ascending array; return index of target or -1.
#include <iostream>
#include <vector>

int search(const std::vector<int>& nums, int target) {
    int left = 0;
    int right = static_cast<int>(nums.size()) - 1;
    while (left <= right) {
        const int mid = left + (right - left) / 2;
        if (nums[static_cast<size_t>(mid)] == target) {
            return mid;
        }
        if (nums[static_cast<size_t>(left)] <= nums[static_cast<size_t>(mid)]) {
            // left half sorted
            if (target >= nums[static_cast<size_t>(left)] &&
                target < nums[static_cast<size_t>(mid)]) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        } else {
            // right half sorted
            if (target > nums[static_cast<size_t>(mid)] &&
                target <= nums[static_cast<size_t>(right)]) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
    }
    return -1;
}

int main() {
    const std::vector<int> nums = {4, 5, 6, 7, 0, 1, 2};
    std::cout << search(nums, 0) << " (expected 4)\n"
              << search(nums, 3) << " (expected -1)\n";
    return 0;
}
