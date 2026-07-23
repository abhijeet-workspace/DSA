// Advanced Stack Apps — next greater element + stock span
// Monotonic stack for next-greater-right and span lengths.
#include <iostream>
#include <stack>
#include <vector>

std::vector<int> nextGreaterElement(const std::vector<int>& arr) {
    const int n = static_cast<int>(arr.size());
    std::vector<int> result(static_cast<size_t>(n), -1);
    std::stack<int> st; // values to the right, decreasing
    for (int i = n - 1; i >= 0; --i) {
        while (!st.empty() && st.top() <= arr[static_cast<size_t>(i)]) {
            st.pop();
        }
        if (!st.empty()) {
            result[static_cast<size_t>(i)] = st.top();
        }
        st.push(arr[static_cast<size_t>(i)]);
    }
    return result;
}

std::vector<int> stockSpan(const std::vector<int>& prices) {
    const int n = static_cast<int>(prices.size());
    std::vector<int> span(static_cast<size_t>(n));
    std::stack<int> st; // indices of prior stricter greater prices
    for (int i = 0; i < n; ++i) {
        while (!st.empty() &&
               prices[static_cast<size_t>(st.top())] <= prices[static_cast<size_t>(i)]) {
            st.pop();
        }
        span[static_cast<size_t>(i)] = st.empty() ? i + 1 : i - st.top();
        st.push(i);
    }
    return span;
}

int main() {
    const std::vector<int> arr1 = {1, 5, 0, 3, 4, 5};
    std::cout << "NGE:";
    for (int x : nextGreaterElement(arr1)) {
        std::cout << ' ' << x;
    }
    std::cout << " (expected 5 -1 3 4 5 -1)\n";

    const std::vector<int> arr2 = {6, 0, 8, 1, 3};
    std::cout << "NGE:";
    for (int x : nextGreaterElement(arr2)) {
        std::cout << ' ' << x;
    }
    std::cout << " (expected 8 8 -1 3 -1)\n";

    const std::vector<int> prices = {100, 80, 60, 70, 60, 75, 85};
    std::cout << "span:";
    for (int s : stockSpan(prices)) {
        std::cout << ' ' << s;
    }
    std::cout << " (expected 1 1 1 2 1 4 6)\n";
    return 0;
}
