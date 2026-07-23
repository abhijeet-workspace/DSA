// Two Sum II — sorted array (LC 167)
// Opposite pointers; move side that shrinks/grows sum toward target.
#include <iostream>
#include <vector>

std::vector<int> twoSumSorted(const std::vector<int>& nums, int target) {
    int L = 0, R = static_cast<int>(nums.size()) - 1;
    while (L < R) {
        int sum = nums[static_cast<size_t>(L)] + nums[static_cast<size_t>(R)];
        if (sum == target) return {L, R};
        if (sum < target) ++L;
        else --R;
    }
    return {};
}

int main() {
    std::vector<int> nums = {1, 2, 4, 5, 6, 7, 10};
    int target = 9;
    auto res = twoSumSorted(nums, target);
    if (!res.empty()) {
        std::cout << "Indices: [" << res[0] << ", " << res[1] << "] values ["
                  << nums[static_cast<size_t>(res[0])] << ", "
                  << nums[static_cast<size_t>(res[1])] << "]\n";
    } else {
        std::cout << "No pair found.\n";
    }
    return 0;
}
