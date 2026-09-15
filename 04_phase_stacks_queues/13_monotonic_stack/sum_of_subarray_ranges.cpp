// Sum of Subarray Ranges — https://leetcode.com/problems/sum-of-subarray-ranges/
// Sum (max - min) over every contiguous subarray.
#include <iostream>
#include <stack>
#include <vector>

long long contribution(const std::vector<int>& nums, bool want_max) {
    const int n = static_cast<int>(nums.size());
    std::vector<int> left(static_cast<size_t>(n));
    std::vector<int> right(static_cast<size_t>(n));
    std::stack<int> st;

    for (int i = 0; i < n; ++i) {
        while (!st.empty()) {
            const int v = nums[static_cast<size_t>(st.top())];
            const int cur = nums[static_cast<size_t>(i)];
            const bool pop = want_max ? (v < cur) : (v > cur);
            if (!pop) {
                break;
            }
            st.pop();
        }
        left[static_cast<size_t>(i)] = st.empty() ? i + 1 : i - st.top();
        st.push(i);
    }
    while (!st.empty()) {
        st.pop();
    }
    for (int i = n - 1; i >= 0; --i) {
        while (!st.empty()) {
            const int v = nums[static_cast<size_t>(st.top())];
            const int cur = nums[static_cast<size_t>(i)];
            // asymmetric bound to handle ties once
            const bool pop = want_max ? (v <= cur) : (v >= cur);
            if (!pop) {
                break;
            }
            st.pop();
        }
        right[static_cast<size_t>(i)] = st.empty() ? n - i : st.top() - i;
        st.push(i);
    }

    long long sum = 0;
    for (int i = 0; i < n; ++i) {
        sum += static_cast<long long>(nums[static_cast<size_t>(i)]) * left[static_cast<size_t>(i)] *
               right[static_cast<size_t>(i)];
    }
    return sum;
}

long long subArrayRanges(const std::vector<int>& nums) {
    return contribution(nums, true) - contribution(nums, false);
}

int main() {
    std::cout << subArrayRanges({1, 2, 3}) << " (expected 4)\n";
    std::cout << subArrayRanges({1, 3, 3}) << " (expected 4)\n";
    return 0;
}
