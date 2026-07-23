// Subsets — https://leetcode.com/problems/subsets/
// Return the power set of nums (all subsets); nums has distinct elements.
#include <iostream>
#include <vector>

void backtrack(const std::vector<int>& nums, int start, std::vector<int>& curr,
               std::vector<std::vector<int>>& result) {
    result.push_back(curr); // record every prefix path
    for (int i = start; i < static_cast<int>(nums.size()); ++i) {
        curr.push_back(nums[static_cast<size_t>(i)]);
        backtrack(nums, i + 1, curr, result); // choose later indices only
        curr.pop_back();
    }
}

std::vector<std::vector<int>> subsets(const std::vector<int>& nums) {
    std::vector<std::vector<int>> result;
    std::vector<int> curr;
    backtrack(nums, 0, curr, result);
    return result;
}

int main() {
    const auto result = subsets({1, 2, 3});
    std::cout << "count=" << result.size() << " (expected 8)\n";
    for (const auto& set : result) {
        std::cout << "[";
        for (size_t i = 0; i < set.size(); ++i) {
            std::cout << set[i] << (i + 1 < set.size() ? " " : "");
        }
        std::cout << "]\n";
    }
    return 0;
}
