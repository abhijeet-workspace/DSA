// Next Greater Element I — https://leetcode.com/problems/next-greater-element-i/
// For each x in nums1, find the next greater element of x in nums2 (or -1).
#include <iostream>
#include <stack>
#include <unordered_map>
#include <vector>

std::vector<int> nextGreaterElement(const std::vector<int>& nums1, const std::vector<int>& nums2) {
    std::unordered_map<int, int> next_greater;
    std::stack<int> st; // decreasing values
    for (int x : nums2) {
        while (!st.empty() && st.top() < x) {
            next_greater[st.top()] = x;
            st.pop();
        }
        st.push(x);
    }
    std::vector<int> ans;
    ans.reserve(nums1.size());
    for (int x : nums1) {
        const auto it = next_greater.find(x);
        ans.push_back(it == next_greater.end() ? -1 : it->second);
    }
    return ans;
}

int main() {
    const auto res = nextGreaterElement({4, 1, 2}, {1, 3, 4, 2});
    std::cout << "NGE I:";
    for (int x : res) {
        std::cout << ' ' << x;
    }
    std::cout << " (expected -1 3 -1)\n";
    return 0;
}
