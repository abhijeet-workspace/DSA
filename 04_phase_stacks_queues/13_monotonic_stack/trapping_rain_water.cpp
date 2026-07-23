// Trapping Rain Water — https://leetcode.com/problems/trapping-rain-water/
// Compute how much water can be trapped between bars.
#include <algorithm>
#include <iostream>
#include <stack>
#include <vector>

int trap(const std::vector<int>& height) {
    std::stack<int> st; // indices, heights decreasing
    int water = 0;
    for (int i = 0; i < static_cast<int>(height.size()); ++i) {
        while (!st.empty() &&
               height[static_cast<size_t>(st.top())] < height[static_cast<size_t>(i)]) {
            const int bottom = st.top();
            st.pop();
            if (st.empty()) {
                break; // no left wall
            }
            const int left = st.top();
            const int w = i - left - 1;
            const int h = std::min(height[static_cast<size_t>(left)], height[static_cast<size_t>(i)]) -
                          height[static_cast<size_t>(bottom)];
            water += w * h;
        }
        st.push(i);
    }
    return water;
}

int main() {
    const std::vector<int> height = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
    std::cout << "Trapped water: " << trap(height) << " (expected 6)\n";
    return 0;
}
