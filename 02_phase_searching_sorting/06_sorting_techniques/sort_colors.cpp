// Sort Colors — https://leetcode.com/problems/sort-colors/
// Partition nums of 0/1/2 in-place via Dutch National Flag three pointers.
#include <iostream>
#include <utility>
#include <vector>

void sortColors(std::vector<int>& nums) {
    int low = 0, mid = 0;
    int high = static_cast<int>(nums.size()) - 1;
    while (mid <= high) {
        if (nums[static_cast<size_t>(mid)] == 0) {
            std::swap(nums[static_cast<size_t>(low++)], nums[static_cast<size_t>(mid++)]);
        } else if (nums[static_cast<size_t>(mid)] == 1) {
            ++mid; // already in middle band
        } else {
            std::swap(nums[static_cast<size_t>(mid)], nums[static_cast<size_t>(high--)]);
        }
    }
}

int main() {
    std::vector<int> nums = {2, 0, 2, 1, 1, 0};
    sortColors(nums);
    for (size_t i = 0; i < nums.size(); ++i) {
        std::cout << nums[i] << (i + 1 < nums.size() ? " " : "");
    }
    std::cout << " (expected 0 0 1 1 2 2)\n";
    return 0;
}
