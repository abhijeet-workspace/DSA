// Maximum Average Subarray I — LC 643
// Fixed-size sliding window: track max sum of length k, then divide by k.
#include <algorithm>
#include <iostream>
#include <vector>

double findMaxAverage(const std::vector<int>& nums, int k) {
    const int n = static_cast<int>(nums.size());
    long long window = 0;
    for (int i = 0; i < k; ++i)
        window += nums[static_cast<size_t>(i)];
    long long best = window;
    for (int i = k; i < n; ++i) {
        window += nums[static_cast<size_t>(i)] - nums[static_cast<size_t>(i - k)];
        best = std::max(best, window);
    }
    return static_cast<double>(best) / static_cast<double>(k);
}

int main() {
    std::cout << findMaxAverage({1, 12, -5, -6, 50, 3}, 4) << " (expected 12.75)\n";
    std::cout << findMaxAverage({5}, 1) << " (expected 5)\n";
    return 0;
}
