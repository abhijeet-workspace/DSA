// Split Array Largest Sum — https://leetcode.com/problems/split-array-largest-sum/
// Split nums into k contiguous subarrays; minimize the largest subarray sum.
#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>

bool canSplit(const std::vector<int>& nums, int k, int cap) {
    int parts = 1;
    long long cur = 0;
    for (int x : nums) {
        if (cur + x > cap) {
            ++parts;
            cur = 0;
        }
        cur += x;
        if (parts > k) {
            return false;
        }
    }
    return true;
}

int splitArray(const std::vector<int>& nums, int k) {
    int lo = *std::max_element(nums.begin(), nums.end());
    int hi = std::accumulate(nums.begin(), nums.end(), 0);
    int ans = hi;
    while (lo <= hi) {
        const int mid = lo + (hi - lo) / 2;
        if (canSplit(nums, k, mid)) {
            ans = mid;
            hi = mid - 1;
        } else {
            lo = mid + 1;
        }
    }
    return ans;
}

int main() {
    std::cout << splitArray({7, 2, 5, 10, 8}, 2) << " (expected 18)\n"
              << splitArray({1, 2, 3, 4, 5}, 2) << " (expected 9)\n";
    return 0;
}
