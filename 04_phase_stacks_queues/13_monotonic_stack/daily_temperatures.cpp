// Daily Temperatures — https://leetcode.com/problems/daily-temperatures/
// For each day, days until a warmer temperature (0 if none).
#include <iostream>
#include <vector>
#include <stack>

std::vector<int> dailyTemperatures(const std::vector<int>& temperatures) {
    const int n = static_cast<int>(temperatures.size());
    std::vector<int> res(static_cast<size_t>(n), 0);
    std::stack<int> st; // indices, temps decreasing top→bottom
    for (int i = 0; i < n; ++i) {
        while (!st.empty() &&
               temperatures[static_cast<size_t>(st.top())] < temperatures[static_cast<size_t>(i)]) {
            const int prev = st.top();
            st.pop();
            res[static_cast<size_t>(prev)] = i - prev;
        }
        st.push(i);
    }
    return res;
}

int main() {
    const std::vector<int> temps = {73, 74, 75, 71, 69, 72, 76, 73};
    const auto res = dailyTemperatures(temps);
    std::cout << "Days to wait:";
    for (int x : res) {
        std::cout << ' ' << x;
    }
    std::cout << " (expected 1 1 4 2 1 1 0 0)\n";
    return 0;
}
