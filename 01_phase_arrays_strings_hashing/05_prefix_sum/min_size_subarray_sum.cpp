// Minimum Size Subarray Sum — https://leetcode.com/problems/minimum-size-subarray-sum/
// Smallest contiguous length with sum >= target (positive nums).
#include <algorithm>
#include <climits>
#include <iostream>
#include <vector>

int minSubarrayLen(int target, const std::vector<int>& nums) {
    int n = static_cast<int>(nums.size());
    int minLen = INT_MAX;
    int windowSum = 0;
    int left = 0;
    for (int right = 0; right < n; ++right) {
        windowSum += nums[right]; // expand
        while (windowSum >= target) {
            minLen = std::min(minLen, right - left + 1); // candidate length
            windowSum -= nums[left++]; // shrink from left
        }
    }
    return minLen == INT_MAX ? 0 : minLen;
}

int main() {
    std::cout << minSubarrayLen(7, {2, 3, 1, 2, 4, 3}) << " (expected 2)\n";
    return 0;
}
