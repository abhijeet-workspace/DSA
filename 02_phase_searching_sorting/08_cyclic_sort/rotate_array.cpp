// Rotate Array — https://leetcode.com/problems/rotate-array/
// Cycle-following: i maps to (i+k)%n; walk each cycle of the rotation permutation.
#include <iostream>
#include <utility>
#include <vector>

void rotate(std::vector<int>& nums, int k) {
    const int n = static_cast<int>(nums.size());
    if (n == 0)
        return;
    k %= n;
    if (k == 0)
        return;

    int count = 0;
    for (int start = 0; count < n; ++start) {
        int cur = start;
        int prev = nums[static_cast<size_t>(start)];
        do {
            const int next = (cur + k) % n;
            std::swap(nums[static_cast<size_t>(next)], prev);
            cur = next;
            ++count;
        } while (cur != start);
    }
}

int main() {
    std::vector<int> nums = {1, 2, 3, 4, 5, 6, 7};
    rotate(nums, 3);
    for (int x : nums)
        std::cout << x << ' ';
    std::cout << "(expected 5 6 7 1 2 3 4)\n";
    return 0;
}
