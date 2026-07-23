// Jump Game — https://leetcode.com/problems/jump-game/
// From 0, nums[i] = max jump; true if last index reachable.
#include <iostream>
#include <vector>
#include <algorithm>

bool canJump(const std::vector<int>& nums) {
    int maxReach = 0;
    const int n = static_cast<int>(nums.size());
    for (int i = 0; i < n; ++i) {
        if (i > maxReach) {
            return false; // stuck before i
        }
        maxReach = std::max(maxReach, i + nums[static_cast<size_t>(i)]);
        if (maxReach >= n - 1) {
            return true;
        }
    }
    return true;
}

int main() {
    std::cout << std::boolalpha
              << canJump({2, 3, 1, 1, 4}) << " (expected true)\n"
              << canJump({3, 2, 1, 0, 4}) << " (expected false)\n";
    return 0;
}
