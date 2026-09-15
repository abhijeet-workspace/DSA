// Array Nesting — https://leetcode.com/problems/array-nesting/
// Permutation nums forms disjoint cycles; nest size = cycle length; take the max.
#include <iostream>
#include <vector>

int arrayNesting(std::vector<int>& nums) {
    const int n = static_cast<int>(nums.size());
    int best = 0;
    for (int i = 0; i < n; ++i) {
        if (nums[static_cast<size_t>(i)] < 0)
            continue; // visited
        int len = 0;
        int j = i;
        while (nums[static_cast<size_t>(j)] >= 0) {
            const int next = nums[static_cast<size_t>(j)];
            nums[static_cast<size_t>(j)] = -1; // mark visited
            j = next;
            ++len;
        }
        if (len > best)
            best = len;
    }
    return best;
}

int main() {
    std::vector<int> nums = {5, 4, 0, 3, 1, 6, 2};
    std::cout << arrayNesting(nums) << " (expected 4)\n";
    return 0;
}
