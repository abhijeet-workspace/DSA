// Find the Smallest Divisor Given a Threshold — https://leetcode.com/problems/find-the-smallest-divisor-given-a-threshold/
// Minimize divisor d such that sum(ceil(nums[i]/d)) <= threshold.
#include <algorithm>
#include <iostream>
#include <vector>

bool ok(const std::vector<int>& nums, int threshold, int d) {
    long long s = 0;
    for (int x : nums) {
        s += (x + d - 1LL) / d;
        if (s > threshold) {
            return false;
        }
    }
    return true;
}

int smallestDivisor(const std::vector<int>& nums, int threshold) {
    int lo = 1;
    int hi = *std::max_element(nums.begin(), nums.end());
    int ans = hi;
    while (lo <= hi) {
        const int mid = lo + (hi - lo) / 2;
        if (ok(nums, threshold, mid)) {
            ans = mid;
            hi = mid - 1;
        } else {
            lo = mid + 1;
        }
    }
    return ans;
}

int main() {
    std::cout << smallestDivisor({1, 2, 5, 9}, 6) << " (expected 5)\n"
              << smallestDivisor({44, 22, 33, 11, 1}, 5) << " (expected 44)\n";
    return 0;
}
