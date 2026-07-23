// Search Insert Position — https://leetcode.com/problems/search-insert-position/
// Sorted distinct nums; return index of target or insertion point.
#include <iostream>
#include <vector>

int searchInsert(const std::vector<int>& nums, int target) {
    int low = 0;
    int high = static_cast<int>(nums.size()) - 1;
    while (low <= high) {
        const int mid = low + (high - low) / 2;
        if (nums[static_cast<size_t>(mid)] == target) {
            return mid;
        }
        if (nums[static_cast<size_t>(mid)] < target) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return low; // first index where nums[i] >= target
}

int main() {
    const std::vector<int> nums = {1, 3, 5, 6};
    std::cout << "Insert 5: " << searchInsert(nums, 5) << " (expected 2)\n"
              << "Insert 2: " << searchInsert(nums, 2) << " (expected 1)\n";
    return 0;
}
