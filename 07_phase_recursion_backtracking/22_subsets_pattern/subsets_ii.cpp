// Subsets II — https://leetcode.com/problems/subsets-ii/
// Power set of nums that may contain duplicates; no duplicate subsets.
#include <algorithm>
#include <iostream>
#include <vector>

void backtrack(const std::vector<int>& nums, int start, std::vector<int>& current,
               std::vector<std::vector<int>>& result) {
    result.push_back(current); // every path is a subset
    for (int i = start; i < static_cast<int>(nums.size()); ++i) {
        if (i > start && nums[static_cast<size_t>(i)] == nums[static_cast<size_t>(i - 1)]) {
            continue; // skip duplicate at same depth
        }
        current.push_back(nums[static_cast<size_t>(i)]);
        backtrack(nums, i + 1, current, result);
        current.pop_back();
    }
}

std::vector<std::vector<int>> subsetsWithDup(std::vector<int>& nums) {
    std::sort(nums.begin(), nums.end()); // group equals for skip
    std::vector<std::vector<int>> result;
    std::vector<int> current;
    backtrack(nums, 0, current, result);
    return result;
}

int main() {
    std::vector<int> nums = {1, 2, 2};
    const auto result = subsetsWithDup(nums);
    std::cout << "count=" << result.size() << " (expected 6)\n";
    for (const auto& subset : result) {
        std::cout << "[";
        for (size_t i = 0; i < subset.size(); ++i) {
            std::cout << subset[i] << (i + 1 < subset.size() ? " " : "");
        }
        std::cout << "]\n";
    }
    return 0;
}
