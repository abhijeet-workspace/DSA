// 3Sum Closest — LC 16
// Sort, fix i, two-pointer search for pair minimizing |sum - target|.
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>

int threeSumClosest(std::vector<int> nums, int target) {
    std::sort(nums.begin(), nums.end());
    int n = static_cast<int>(nums.size());
    int best = nums[0] + nums[1] + nums[2];
    for (int i = 0; i < n - 2; ++i) {
        int L = i + 1, R = n - 1;
        while (L < R) {
            int sum = nums[static_cast<size_t>(i)]
                    + nums[static_cast<size_t>(L)]
                    + nums[static_cast<size_t>(R)];
            if (std::abs(sum - target) < std::abs(best - target)) best = sum;
            if (sum == target) return sum;
            if (sum < target) ++L;
            else --R;
        }
    }
    return best;
}

int main() {
    std::cout << threeSumClosest({-1, 2, 1, -4}, 1) << " (expected 2)\n";
    std::cout << threeSumClosest({0, 0, 0}, 1) << " (expected 0)\n";
    return 0;
}
