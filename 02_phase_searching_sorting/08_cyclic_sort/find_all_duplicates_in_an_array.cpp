// Find All Duplicates in an Array — https://leetcode.com/problems/find-all-duplicates-in-an-array/
// Cyclic place v at index v-1; values sitting off-home after placement are duplicates.
#include <iostream>
#include <vector>
#include <utility>

std::vector<int> findDuplicates(std::vector<int>& nums) {
    const int n = static_cast<int>(nums.size());
    int i = 0;
    while (i < n) {
        const int correct = nums[static_cast<size_t>(i)] - 1;
        if (nums[static_cast<size_t>(i)] != nums[static_cast<size_t>(correct)]) {
            std::swap(nums[static_cast<size_t>(i)], nums[static_cast<size_t>(correct)]);
        } else {
            ++i;
        }
    }
    std::vector<int> ans;
    for (i = 0; i < n; ++i) {
        if (nums[static_cast<size_t>(i)] != i + 1) {
            ans.push_back(nums[static_cast<size_t>(i)]);
        }
    }
    return ans;
}

int main() {
    std::vector<int> nums = {4, 3, 2, 7, 8, 2, 3, 1};
    for (int x : findDuplicates(nums)) std::cout << x << ' ';
    std::cout << "(expected 2 3)\n";
    return 0;
}
