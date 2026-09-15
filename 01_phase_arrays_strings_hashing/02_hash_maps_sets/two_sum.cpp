// Two Sum — https://leetcode.com/problems/two-sum/
// Return indices of two numbers that add to target (exactly one solution).
#include <iostream>
#include <unordered_map>
#include <vector>

std::vector<int> twoSum(const std::vector<int>& nums, int target) {
    std::unordered_map<int, int> seen; // value -> index
    for (int i = 0; i < static_cast<int>(nums.size()); ++i) {
        const int need = target - nums[static_cast<size_t>(i)];
        auto it = seen.find(need);
        if (it != seen.end()) {
            return {it->second, i};
        }
        seen[nums[static_cast<size_t>(i)]] = i;
    }
    return {};
}

int main() {
    const auto a = twoSum({2, 7, 11, 15}, 9);
    std::cout << a[0] << " " << a[1] << " (expected 0 1)\n";
    const auto b = twoSum({3, 2, 4}, 6);
    std::cout << b[0] << " " << b[1] << " (expected 1 2)\n";
    return 0;
}
