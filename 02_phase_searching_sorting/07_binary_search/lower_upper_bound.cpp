// Lower / Upper Bound — first index with nums[i] >= target / nums[i] > target.
// Half-open [left, right) binary search; mirrors std::lower_bound / upper_bound.
#include <iostream>
#include <vector>
#include <algorithm>

int customLowerBound(const std::vector<int>& nums, int target) {
    int left = 0;
    int right = static_cast<int>(nums.size()); // exclusive
    while (left < right) {
        const int mid = left + (right - left) / 2;
        if (nums[static_cast<size_t>(mid)] >= target) {
            right = mid; // keep mid as candidate
        } else {
            left = mid + 1;
        }
    }
    return left;
}

int customUpperBound(const std::vector<int>& nums, int target) {
    int left = 0;
    int right = static_cast<int>(nums.size());
    while (left < right) {
        const int mid = left + (right - left) / 2;
        if (nums[static_cast<size_t>(mid)] > target) {
            right = mid;
        } else {
            left = mid + 1;
        }
    }
    return left;
}

int main() {
    const std::vector<int> nums = {1, 2, 4, 4, 4, 6, 7};
    const int target = 4;
    const int lb = customLowerBound(nums, target);
    const int ub = customUpperBound(nums, target);
    const auto stl_lb =
        std::lower_bound(nums.begin(), nums.end(), target) - nums.begin();
    const auto stl_ub =
        std::upper_bound(nums.begin(), nums.end(), target) - nums.begin();
    std::cout << "Lower: " << lb << " (STL " << stl_lb << ", expected 2)\n"
              << "Upper: " << ub << " (STL " << stl_ub << ", expected 5)\n";
    return 0;
}
