// Minimum Size Subarray Sum — LC 209
// Shrink-while-valid variable window: smallest length with sum >= target.
#include <algorithm>
#include <climits>
#include <iostream>
#include <vector>

int minSubArrayLen(int target, const std::vector<int>& nums) {
    int left = 0;
    long long sum = 0;
    int best = INT_MAX;
    for (int right = 0; right < static_cast<int>(nums.size()); ++right) {
        sum += nums[static_cast<size_t>(right)];
        while (sum >= target) {
            best = std::min(best, right - left + 1);
            sum -= nums[static_cast<size_t>(left)];
            ++left;
        }
    }
    return best == INT_MAX ? 0 : best;
}

int main() {
    std::cout << minSubArrayLen(7, {2, 3, 1, 2, 4, 3}) << " (expected 2)\n"
              << minSubArrayLen(4, {1, 4, 4}) << " (expected 1)\n"
              << minSubArrayLen(11, {1, 1, 1, 1, 1, 1, 1, 1}) << " (expected 0)\n";
    return 0;
}
