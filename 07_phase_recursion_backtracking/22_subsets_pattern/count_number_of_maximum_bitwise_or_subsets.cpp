// Count Number of Maximum Bitwise-OR Subsets
// https://leetcode.com/problems/count-number-of-maximum-bitwise-or-subsets/
#include <iostream>
#include <vector>

void dfs(const std::vector<int>& nums, int i, int cur, int target, int& ways) {
    if (i == static_cast<int>(nums.size())) {
        if (cur == target) ++ways;
        return;
    }
    dfs(nums, i + 1, cur, target, ways);
    dfs(nums, i + 1, cur | nums[static_cast<size_t>(i)], target, ways);
}

int countMaxOrSubsets(const std::vector<int>& nums) {
    int target = 0;
    for (int x : nums) target |= x;
    int ways = 0;
    dfs(nums, 0, 0, target, ways);
    return ways;
}

int main() {
    std::cout << countMaxOrSubsets({3, 1}) << " (expected 2)\n";
    std::cout << countMaxOrSubsets({2, 2, 2}) << " (expected 7)\n";
    return 0;
}
