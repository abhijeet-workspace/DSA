// Running Sum of 1d Array — LC 1480
// runningSum[i] = sum of nums[0..i]; accumulate left to right.
#include <iostream>
#include <vector>

std::vector<int> runningSum(std::vector<int> nums) {
    for (size_t i = 1; i < nums.size(); ++i) {
        nums[i] += nums[i - 1];
    }
    return nums;
}

int main() {
    for (int x : runningSum({1, 2, 3, 4}))
        std::cout << x << " ";
    std::cout << "(expected 1 3 6 10)\n";
    return 0;
}
