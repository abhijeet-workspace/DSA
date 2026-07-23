// Permutations — https://leetcode.com/problems/permutations/
// Return all permutations of a distinct-integer array.
#include <iostream>
#include <utility>
#include <vector>

void backtrack(std::vector<int>& nums, int start,
               std::vector<std::vector<int>>& result) {
    if (start == static_cast<int>(nums.size())) { // fixed a full perm
        result.push_back(nums);
        return;
    }
    for (int i = start; i < static_cast<int>(nums.size()); ++i) {
        std::swap(nums[static_cast<size_t>(start)], nums[static_cast<size_t>(i)]); // choose
        backtrack(nums, start + 1, result);
        std::swap(nums[static_cast<size_t>(start)], nums[static_cast<size_t>(i)]); // undo
    }
}

std::vector<std::vector<int>> permute(std::vector<int>& nums) {
    std::vector<std::vector<int>> result;
    backtrack(nums, 0, result);
    return result;
}

int main() {
    std::vector<int> nums = {1, 2, 3};
    const auto result = permute(nums);
    std::cout << "Permutations (" << result.size() << " expected 6):\n";
    for (const auto& perm : result) {
        std::cout << "[ ";
        for (int x : perm) std::cout << x << " ";
        std::cout << "]\n";
    }
    return 0;
}
