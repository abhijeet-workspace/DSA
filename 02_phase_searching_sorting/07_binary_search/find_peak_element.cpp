// Find Peak Element — https://leetcode.com/problems/find-peak-element/
// Any peak: binary search on slope — climb toward a higher neighbor.
#include <iostream>
#include <vector>

int findPeakElement(const std::vector<int>& nums) {
    int lo = 0;
    int hi = static_cast<int>(nums.size()) - 1;
    while (lo < hi) {
        const int mid = lo + (hi - lo) / 2;
        if (nums[static_cast<size_t>(mid)] < nums[static_cast<size_t>(mid + 1)]) {
            lo = mid + 1; // ascending — peak is to the right
        } else {
            hi = mid; // descending or peak — keep mid
        }
    }
    return lo;
}

int main() {
    std::cout << findPeakElement({1, 2, 3, 1}) << " (expected 2)\n";
    std::cout << findPeakElement({1, 2, 1, 3, 5, 6, 4}) << " (expected 1 or 5)\n";
    std::cout << findPeakElement({1}) << " (expected 0)\n";
    return 0;
}
