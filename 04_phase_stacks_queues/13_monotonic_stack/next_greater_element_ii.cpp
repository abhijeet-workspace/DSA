// Next Greater Element II — https://leetcode.com/problems/next-greater-element-ii/
// Circular array: next strictly greater to the right (wrapping around), or -1.
#include <iostream>
#include <stack>
#include <vector>

std::vector<int> nextGreaterElements(const std::vector<int>& nums) {
    const int n = static_cast<int>(nums.size());
    std::vector<int> res(static_cast<size_t>(n), -1);
    std::stack<int> st; // indices, decreasing values
    for (int k = 0; k < 2 * n; ++k) {
        const int i = k % n;
        while (!st.empty() &&
               nums[static_cast<size_t>(st.top())] < nums[static_cast<size_t>(i)]) {
            res[static_cast<size_t>(st.top())] = nums[static_cast<size_t>(i)];
            st.pop();
        }
        if (k < n) {
            st.push(i);
        }
    }
    return res;
}

int main() {
    const auto res = nextGreaterElements({1, 2, 1});
    std::cout << "NGE II:";
    for (int x : res) {
        std::cout << ' ' << x;
    }
    std::cout << " (expected 2 -1 2)\n";
    return 0;
}
