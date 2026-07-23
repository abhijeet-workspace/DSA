// Jump Game II — https://leetcode.com/problems/jump-game-ii/
// Min jumps to last index; greedy BFS layers on the array.
#include <iostream>
#include <vector>
#include <algorithm>

int jump(const std::vector<int>& nums) {
    int jumps = 0;
    int end = 0;  // end of current jump window
    int far = 0;  // farthest reachable in window
    for (int i = 0; i < static_cast<int>(nums.size()) - 1; ++i) {
        far = std::max(far, i + nums[static_cast<size_t>(i)]);
        if (i == end) { // must take another jump
            ++jumps;
            end = far;
        }
    }
    return jumps;
}

int main() {
    const std::vector<int> a = {2, 3, 1, 1, 4};
    std::cout << jump(a) << " (expected 2)\n";
    return 0;
}
