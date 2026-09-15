// Binary Subarrays With Sum — LC 930
// atMost(goal) - atMost(goal-1) on a binary array (or prefix hashmap).
#include <iostream>
#include <vector>

int atMost(const std::vector<int>& nums, int goal) {
    if (goal < 0)
        return 0;
    int left = 0;
    int sum = 0;
    int count = 0;
    for (int right = 0; right < static_cast<int>(nums.size()); ++right) {
        sum += nums[static_cast<size_t>(right)];
        while (sum > goal) {
            sum -= nums[static_cast<size_t>(left)];
            ++left;
        }
        count += right - left + 1; // windows ending at right with sum ≤ goal
    }
    return count;
}

int numSubarraysWithSum(const std::vector<int>& nums, int goal) {
    return atMost(nums, goal) - atMost(nums, goal - 1);
}

int main() {
    std::cout << numSubarraysWithSum({1, 0, 1, 0, 1}, 2) << " (expected 4)\n";
    std::cout << numSubarraysWithSum({0, 0, 0, 0, 0}, 0) << " (expected 15)\n";
    return 0;
}
