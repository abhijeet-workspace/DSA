// Valid Triangle Number — https://leetcode.com/problems/valid-triangle-number/
// Count triplets that can form a triangle: a+b>c after sorting.
#include <algorithm>
#include <iostream>
#include <vector>

int triangleNumber(std::vector<int> nums) {
    std::sort(nums.begin(), nums.end());
    const int n = static_cast<int>(nums.size());
    int ans = 0;
    for (int c = n - 1; c >= 2; --c) {
        int lo = 0;
        int hi = c - 1;
        while (lo < hi) {
            if (nums[static_cast<size_t>(lo)] + nums[static_cast<size_t>(hi)] > nums[static_cast<size_t>(c)]) {
                ans += hi - lo; // all [lo, hi-1] work with hi
                --hi;
            } else {
                ++lo;
            }
        }
    }
    return ans;
}

int main() {
    std::cout << triangleNumber({2, 2, 3, 4}) << " (expected 3)\n"
              << triangleNumber({4, 2, 3, 4}) << " (expected 4)\n";
    return 0;
}
