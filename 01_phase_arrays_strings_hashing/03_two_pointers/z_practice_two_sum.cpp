// Practice: Two Sum on sorted array
// Opposite pointers toward target sum.
#include <iostream>
#include <vector>

std::vector<int> twoSum(const std::vector<int>& nums, int target) {
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
    std::vector<int> nums = {1, 2, 3, 4, 6};
    int target = 6;
    auto ans = twoSum(nums, target);
    std::cout << "[" << ans[0] << ", " << ans[1] << "]\n"; // expected [1, 3] -> 2+4
    return 0;
}
