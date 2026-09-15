// Partition to K Equal Sum Subsets —
// https://leetcode.com/problems/partition-to-k-equal-sum-subsets/
#include <algorithm>
#include <functional>
#include <iostream>
#include <numeric>
#include <vector>

bool canPartitionKSubsets(std::vector<int>& nums, int k) {
    const int total = std::accumulate(nums.begin(), nums.end(), 0);
    if (total % k)
        return false;
    const int target = total / k;
    std::sort(nums.begin(), nums.end(), std::greater<int>());
    if (nums[0] > target)
        return false;
    std::vector<int> bucket(static_cast<size_t>(k), 0);
    std::function<bool(int)> dfs = [&](int i) -> bool {
        if (i == static_cast<int>(nums.size()))
            return true;
        for (int b = 0; b < k; ++b) {
            if (bucket[static_cast<size_t>(b)] + nums[static_cast<size_t>(i)] > target)
                continue;
            bucket[static_cast<size_t>(b)] += nums[static_cast<size_t>(i)];
            if (dfs(i + 1))
                return true;
            bucket[static_cast<size_t>(b)] -= nums[static_cast<size_t>(i)];
            if (bucket[static_cast<size_t>(b)] == 0)
                break;
        }
        return false;
    };
    return dfs(0);
}

int main() {
    std::vector<int> nums{4, 3, 2, 3, 5, 2, 1};
    std::cout << std::boolalpha << canPartitionKSubsets(nums, 4) << " (expected true)\n";
    return 0;
}
