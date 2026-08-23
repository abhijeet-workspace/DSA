// Single Element in a Sorted Array — https://leetcode.com/problems/single-element-in-a-sorted-array/
// Every element appears twice except one; pairs occupy even/odd indices until the single.
#include <iostream>
#include <vector>

int singleNonDuplicate(const std::vector<int>& nums) {
    int lo = 0;
    int hi = static_cast<int>(nums.size()) - 1;
    while (lo < hi) {
        int mid = lo + (hi - lo) / 2;
        if (mid % 2 == 1) {
            --mid; // align to even index (start of a pair)
        }
        if (nums[static_cast<size_t>(mid)] == nums[static_cast<size_t>(mid + 1)]) {
            lo = mid + 2; // pair intact; single is right
        } else {
            hi = mid;
        }
    }
    return nums[static_cast<size_t>(lo)];
}

int main() {
    std::cout << singleNonDuplicate({1, 1, 2, 3, 3, 4, 4, 8, 8}) << " (expected 2)\n"
              << singleNonDuplicate({3, 3, 7, 7, 10, 11, 11}) << " (expected 10)\n";
    return 0;
}
