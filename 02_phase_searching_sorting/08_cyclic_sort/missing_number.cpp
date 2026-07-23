// Missing Number — https://leetcode.com/problems/missing-number/
// nums holds n distinct values in [0,n]; return the missing one.
#include <iostream>
#include <vector>
#include <utility>

int missingNumber(std::vector<int>& nums) {
    const int n = static_cast<int>(nums.size());
    int i = 0;
    while (i < n) {
        const int v = nums[static_cast<size_t>(i)];
        if (v < n && v != nums[static_cast<size_t>(v)]) { // place v at index v
            std::swap(nums[static_cast<size_t>(i)], nums[static_cast<size_t>(v)]);
        } else {
            ++i;
        }
    }
    for (i = 0; i < n; ++i) {
        if (nums[static_cast<size_t>(i)] != i) {
            return i;
        }
    }
    return n;
}

int main() {
    std::vector<int> a = {3, 0, 1};
    std::vector<int> b = {0, 1};
    std::vector<int> c = {9, 6, 4, 2, 3, 5, 7, 0, 1};
    std::cout << missingNumber(a) << " (expected 2)\n"
              << missingNumber(b) << " (expected 2)\n"
              << missingNumber(c) << " (expected 8)\n";
    return 0;
}
