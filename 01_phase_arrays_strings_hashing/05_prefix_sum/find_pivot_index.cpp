// Find Pivot Index — LC 724
// Total sum once; left accumulates; pivot when left == total - left - nums[i].
#include <iostream>
#include <numeric>
#include <vector>

int pivotIndex(const std::vector<int>& nums) {
    const int total = std::accumulate(nums.begin(), nums.end(), 0);
    int left = 0;
    for (int i = 0; i < static_cast<int>(nums.size()); ++i) {
        int right = total - left - nums[static_cast<size_t>(i)];
        if (left == right)
            return i;
        left += nums[static_cast<size_t>(i)];
    }
    return -1;
}

int main() {
    std::cout << pivotIndex({1, 7, 3, 6, 5, 6}) << " (expected 3)\n";
    std::cout << pivotIndex({1, 2, 3}) << " (expected -1)\n";
    std::cout << pivotIndex({2, 1, -1}) << " (expected 0)\n";
    return 0;
}
