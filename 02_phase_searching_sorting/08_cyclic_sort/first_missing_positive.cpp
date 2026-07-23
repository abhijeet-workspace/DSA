// First Missing Positive — https://leetcode.com/problems/first-missing-positive/
// Smallest missing positive integer; cyclic-sort values in [1,n] in-place.
#include <iostream>
#include <vector>
#include <utility>

int firstMissingPositive(std::vector<int>& nums) {
    const int n = static_cast<int>(nums.size());
    int i = 0;
    while (i < n) {
        const int v = nums[static_cast<size_t>(i)];
        if (v > 0 && v <= n && v != nums[static_cast<size_t>(v - 1)]) {
            std::swap(nums[static_cast<size_t>(i)], nums[static_cast<size_t>(v - 1)]);
        } else {
            ++i;
        }
    }
    for (i = 0; i < n; ++i) {
        if (nums[static_cast<size_t>(i)] != i + 1) {
            return i + 1;
        }
    }
    return n + 1;
}

int main() {
    std::vector<int> nums = {3, 4, -1, 1};
    std::cout << "First Missing Positive: " << firstMissingPositive(nums)
              << " (expected 2)\n";
    return 0;
}
