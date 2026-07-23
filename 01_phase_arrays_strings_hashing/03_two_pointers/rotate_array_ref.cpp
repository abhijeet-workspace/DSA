// Rotate Array by k — LC 189 (reversal)
// Reverse all, then reverse [0,k) and [k,n).
#include <iostream>
#include <vector>
#include <utility>

void reverseRange(std::vector<int>& nums, int L, int R) {
    while (L < R) std::swap(nums[static_cast<size_t>(L++)], nums[static_cast<size_t>(R--)]);
}

void rotate(std::vector<int>& nums, int k) {
    int n = static_cast<int>(nums.size());
    if (n == 0) return;
    k %= n;
    if (k == 0) return;
    reverseRange(nums, 0, n - 1);
    reverseRange(nums, 0, k - 1);
    reverseRange(nums, k, n - 1);
}

int main() {
    std::vector<int> nums = {1, 2, 3, 4, 5, 6, 7};
    rotate(nums, 3);
    for (int x : nums) std::cout << x << " ";
    std::cout << "\n"; // expected 5 6 7 1 2 3 4
    return 0;
}
