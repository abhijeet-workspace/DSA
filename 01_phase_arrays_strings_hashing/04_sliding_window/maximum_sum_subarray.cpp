// Max Sum Subarray of Size K — fixed sliding window
// Maintain windowSum; slide by +in −out in O(1) per step.
#include <iostream>
#include <vector>
#include <algorithm>

int maxSumSubarray(const std::vector<int>& nums, int k) {
    if (static_cast<int>(nums.size()) < k) return -1;
    int windowSum = 0;
    for (int i = 0; i < k; ++i) windowSum += nums[static_cast<size_t>(i)];
    int maxSum = windowSum;
    for (int i = k; i < static_cast<int>(nums.size()); ++i) {
        windowSum += nums[static_cast<size_t>(i)] - nums[static_cast<size_t>(i - k)];
        maxSum = std::max(maxSum, windowSum);
    }
    return maxSum;
}

int main() {
    std::cout << maxSumSubarray({2, 1, 5, 1, 3, 2}, 3)
              << " (expected 9)\n";
    return 0;
}
