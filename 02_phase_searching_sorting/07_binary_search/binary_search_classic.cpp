// Binary Search — https://leetcode.com/problems/binary-search/
// Sorted ascending nums; return index of target or -1 (iterative + recursive).
#include <iostream>
#include <vector>

int binarySearchIterative(const std::vector<int>& nums, int target) {
    int left = 0;
    int right = static_cast<int>(nums.size()) - 1;
    while (left <= right) {
        const int mid = left + (right - left) / 2; // avoid overflow
        if (nums[static_cast<size_t>(mid)] == target) {
            return mid;
        }
        if (nums[static_cast<size_t>(mid)] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return -1;
}

int binarySearchRecursiveHelper(const std::vector<int>& nums, int left, int right,
                                int target) {
    if (left > right) {
        return -1;
    }
    const int mid = left + (right - left) / 2;
    if (nums[static_cast<size_t>(mid)] == target) {
        return mid;
    }
    if (nums[static_cast<size_t>(mid)] < target) {
        return binarySearchRecursiveHelper(nums, mid + 1, right, target);
    }
    return binarySearchRecursiveHelper(nums, left, mid - 1, target);
}

int binarySearchRecursive(const std::vector<int>& nums, int target) {
    return binarySearchRecursiveHelper(nums, 0, static_cast<int>(nums.size()) - 1,
                                       target);
}

int main() {
    const std::vector<int> nums = {-1, 0, 3, 5, 9, 12};
    const int target = 9;
    std::cout << "Iterative: " << binarySearchIterative(nums, target)
              << " (expected 4)\n"
              << "Recursive: " << binarySearchRecursive(nums, target)
              << " (expected 4)\n";
    return 0;
}
