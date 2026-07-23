// Product of Array Except Self — https://leetcode.com/problems/product-of-array-except-self/
// answer[i] = product of all nums except nums[i]; division not allowed.
#include <iostream>
#include <vector>

std::vector<int> productExceptSelf(const std::vector<int>& nums) {
    const int n = static_cast<int>(nums.size());
    std::vector<int> ans(static_cast<size_t>(n), 1); // output buffer
    int left = 1;
    for (int i = 0; i < n; ++i) { // prefix products into ans
        ans[static_cast<size_t>(i)] = left;
        left *= nums[static_cast<size_t>(i)];
    }
    int right = 1;
    for (int i = n - 1; i >= 0; --i) { // multiply by suffix products
        ans[static_cast<size_t>(i)] *= right;
        right *= nums[static_cast<size_t>(i)];
    }
    return ans;
}

int main() {
    auto ans = productExceptSelf({1, 2, 3, 4});
    std::cout << "productExceptSelf:";
    for (int x : ans) std::cout << " " << x;
    std::cout << " (expected 24 12 8 6)\n";
    return 0;
}
