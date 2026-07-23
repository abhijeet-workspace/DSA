// Maximum Product Subarray — https://leetcode.com/problems/maximum-product-subarray/
// Contiguous subarray with largest product; return that product.
#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>

int maxProduct(const std::vector<int>& nums) {
    int best = nums[0];
    int curMax = nums[0]; // best product ending here
    int curMin = nums[0]; // worst product ending here (for negatives)
    for (size_t i = 1; i < nums.size(); ++i) {
        const int x = nums[i];
        if (x < 0) std::swap(curMax, curMin); // negative flips extremes
        curMax = std::max(x, curMax * x); // restart or extend
        curMin = std::min(x, curMin * x);
        best = std::max(best, curMax);
    }
    return best;
}

int main() {
    std::cout << maxProduct({2, 3, -2, 4}) << " (expected 6)\n"
              << maxProduct({-2, 0, -1}) << " (expected 0)\n";
    return 0;
}
