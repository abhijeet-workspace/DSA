// Subarray Product Less Than K — LC 713
// Count subarrays: expand right, shrink while product >= k; add (right-left+1).
#include <iostream>
#include <vector>

int numSubarrayProductLessThanK(const std::vector<int>& nums, int k) {
    if (k <= 1) return 0;
    long long product = 1;
    int left = 0;
    int count = 0;
    for (int right = 0; right < static_cast<int>(nums.size()); ++right) {
        product *= nums[static_cast<size_t>(right)];
        while (product >= k) {
            product /= nums[static_cast<size_t>(left)];
            ++left;
        }
        count += right - left + 1;
    }
    return count;
}

int main() {
    std::cout << numSubarrayProductLessThanK({10, 5, 2, 6}, 100)
              << " (expected 8)\n"
              << numSubarrayProductLessThanK({1, 2, 3}, 0)
              << " (expected 0)\n";
    return 0;
}
