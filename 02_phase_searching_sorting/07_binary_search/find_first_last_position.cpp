// Find First and Last Position — https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/
// Sorted nums; return [first, last] index of target, or [-1, -1].
#include <iostream>
#include <vector>

int findBound(const std::vector<int>& nums, int target, bool isFirst) {
    int left = 0;
    int right = static_cast<int>(nums.size()) - 1;
    int bound = -1;
    while (left <= right) {
        const int mid = left + (right - left) / 2;
        if (nums[static_cast<size_t>(mid)] == target) {
            bound = mid;
            if (isFirst) {
                right = mid - 1; // keep searching left
            } else {
                left = mid + 1; // keep searching right
            }
        } else if (nums[static_cast<size_t>(mid)] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return bound;
}

std::vector<int> searchRange(const std::vector<int>& nums, int target) {
    const int first = findBound(nums, target, true);
    if (first == -1) {
        return {-1, -1};
    }
    return {first, findBound(nums, target, false)};
}

int main() {
    const std::vector<int> nums = {5, 7, 7, 8, 8, 10};
    const auto res = searchRange(nums, 8);
    std::cout << "Range: [" << res[0] << ", " << res[1] << "] (expected [3, 4])\n";
    return 0;
}
