// Largest Rectangle in Histogram — https://leetcode.com/problems/largest-rectangle-in-histogram/
// Monotonic stack of indices; sentinel 0 flushes remaining bars.
#include <algorithm>
#include <iostream>
#include <stack>
#include <vector>

int largestRectangleArea(std::vector<int> heights) {
    std::stack<int> st;
    int max_area = 0;
    heights.push_back(0); // flush remaining bars
    for (int i = 0; i < static_cast<int>(heights.size()); ++i) {
        while (!st.empty() &&
               heights[static_cast<size_t>(st.top())] >=
                   heights[static_cast<size_t>(i)]) {
            const int h = heights[static_cast<size_t>(st.top())];
            st.pop();
            const int w = st.empty() ? i : i - st.top() - 1;
            max_area = std::max(max_area, h * w);
        }
        st.push(i);
    }
    return max_area;
}

int main() {
    std::vector<int> heights = {2, 1, 5, 6, 2, 3};
    std::cout << "Max Rect Area: " << largestRectangleArea(heights)
              << " (expected 10)\n";
    return 0;
}
