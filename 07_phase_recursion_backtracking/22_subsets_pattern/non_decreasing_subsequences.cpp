// Non-decreasing Subsequences — https://leetcode.com/problems/non-decreasing-subsequences/
// Return all different non-decreasing subsequences of length >= 2.
#include <iostream>
#include <unordered_set>
#include <vector>

void dfs(const std::vector<int>& nums, int start, std::vector<int>& path,
         std::vector<std::vector<int>>& result) {
    if (path.size() >= 2)
        result.push_back(path);
    std::unordered_set<int> used;
    for (int i = start; i < static_cast<int>(nums.size()); ++i) {
        if (!path.empty() && nums[static_cast<size_t>(i)] < path.back())
            continue;
        if (used.count(nums[static_cast<size_t>(i)]))
            continue;
        used.insert(nums[static_cast<size_t>(i)]);
        path.push_back(nums[static_cast<size_t>(i)]);
        dfs(nums, i + 1, path, result);
        path.pop_back();
    }
}

std::vector<std::vector<int>> findSubsequences(const std::vector<int>& nums) {
    std::vector<std::vector<int>> result;
    std::vector<int> path;
    dfs(nums, 0, path, result);
    return result;
}

int main() {
    const auto r = findSubsequences({4, 6, 7, 7});
    std::cout << "count=" << r.size() << " (expected 8)\n";
    return 0;
}
