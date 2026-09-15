// Wiggle Subsequence — https://leetcode.com/problems/wiggle-subsequence/
#include <algorithm>
#include <iostream>
#include <vector>

int wiggleMaxLength(std::vector<int>& nums) {
    if (nums.empty())
        return 0;
    int up = 1, down = 1;
    for (size_t i = 1; i < nums.size(); ++i) {
        if (nums[i] > nums[i - 1])
            up = down + 1;
        else if (nums[i] < nums[i - 1])
            down = up + 1;
    }
    return std::max(up, down);
}

int main() {
    std::vector<int> nums{1, 7, 4, 9, 2, 5};
    std::cout << wiggleMaxLength(nums) << " (expected 6)\n";
    return 0;
}
