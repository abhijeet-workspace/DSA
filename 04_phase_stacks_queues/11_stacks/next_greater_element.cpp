// Next Greater Element — nearest greater to the right (−1 if none)
// Monotonic increasing stack of indices while scanning left→right.
#include <iostream>
#include <stack>
#include <vector>

std::vector<int> nextGreaterElement(const std::vector<int>& nums) {
    const int n = static_cast<int>(nums.size());
    std::vector<int> res(static_cast<size_t>(n), -1);
    std::stack<int> st; // indices waiting for a greater value
    for (int i = 0; i < n; ++i) {
        while (!st.empty() &&
               nums[static_cast<size_t>(st.top())] < nums[static_cast<size_t>(i)]) {
            res[static_cast<size_t>(st.top())] = nums[static_cast<size_t>(i)];
            st.pop();
        }
        st.push(i);
    }
    return res;
}

int main() {
    const std::vector<int> nums = {4, 5, 2, 25};
    std::cout << "Next Greater:";
    for (int x : nextGreaterElement(nums)) {
        std::cout << ' ' << x;
    }
    std::cout << " (expected 5 25 25 -1)\n";
    return 0;
}
