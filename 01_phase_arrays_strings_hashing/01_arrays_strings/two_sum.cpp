// Two Sum — https://leetcode.com/problems/two-sum/
// Given nums and target, return indices of two numbers that add to target.
#include <iostream>
#include <vector>
#include <unordered_map>

std::vector<int> twoSum(const std::vector<int>& nums, int target) {
    std::unordered_map<int, int> seen; // value -> index
    for (int i = 0; i < static_cast<int>(nums.size()); ++i) { // scan once
        const int need = target - nums[static_cast<size_t>(i)]; // complement
        auto it = seen.find(need);
        if (it != seen.end()) { // pair found
            return {it->second, i};
        }
        seen[nums[static_cast<size_t>(i)]] = i; // remember current
    }
    return {};
}

int main() {
    const std::vector<int> nums = {2, 7, 11, 15};
    const auto res = twoSum(nums, 9);
    std::cout << "Two Sum indices: [" << res[0] << ", " << res[1]
              << "] (expected [0, 1])\n";
    return 0;
}
