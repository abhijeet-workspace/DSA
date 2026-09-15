// Permutations II — https://leetcode.com/problems/permutations-ii/
// All unique permutations of an integer array that may contain duplicates.
#include <algorithm>
#include <iostream>
#include <vector>

void backtrack(std::vector<int>& nums, std::vector<bool>& used,
               std::vector<int>& path, std::vector<std::vector<int>>& result) {
    if (path.size() == nums.size()) {
        result.push_back(path);
        return;
    }
    for (int i = 0; i < static_cast<int>(nums.size()); ++i) {
        if (used[static_cast<size_t>(i)]) {
            continue;
        }
        // skip duplicate at same depth: only take first unused equal value
        if (i > 0 && nums[static_cast<size_t>(i)] == nums[static_cast<size_t>(i - 1)]
            && !used[static_cast<size_t>(i - 1)]) {
            continue;
        }
        used[static_cast<size_t>(i)] = true;
        path.push_back(nums[static_cast<size_t>(i)]);
        backtrack(nums, used, path, result);
        path.pop_back();
        used[static_cast<size_t>(i)] = false;
    }
}

std::vector<std::vector<int>> permuteUnique(std::vector<int>& nums) {
    std::sort(nums.begin(), nums.end());
    std::vector<std::vector<int>> result;
    std::vector<bool> used(nums.size(), false);
    std::vector<int> path;
    backtrack(nums, used, path, result);
    return result;
}

int main() {
    std::vector<int> nums = {1, 1, 2};
    const auto result = permuteUnique(nums);
    std::cout << "Unique permutations (" << result.size() << " expected 3):\n";
    for (const auto& perm : result) {
        std::cout << "[ ";
        for (int x : perm) {
            std::cout << x << " ";
        }
        std::cout << "]\n";
    }
    return 0;
}
