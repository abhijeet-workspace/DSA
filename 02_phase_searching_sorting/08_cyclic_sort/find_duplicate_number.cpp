// Find the Duplicate Number — https://leetcode.com/problems/find-the-duplicate-number/
// n+1 ints in [1,n]; exactly one duplicate — return it (cyclic-sort placement).
#include <iostream>
#include <vector>
#include <utility>

int findDuplicate(std::vector<int>& nums) {
    int i = 0;
    const int n = static_cast<int>(nums.size());
    while (i < n) {
        const int correct = nums[static_cast<size_t>(i)] - 1; // value v belongs at v-1
        if (nums[static_cast<size_t>(i)] != nums[static_cast<size_t>(correct)]) {
            std::swap(nums[static_cast<size_t>(i)], nums[static_cast<size_t>(correct)]);
        } else {
            ++i;
        }
    }
    return nums.back(); // after placement, duplicate sits at the end
}

int main() {
    std::vector<int> nums = {1, 3, 4, 2, 2};
    std::cout << "Duplicate: " << findDuplicate(nums) << " (expected 2)\n";
    return 0;
}
