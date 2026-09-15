// Maximal Rectangle — https://leetcode.com/problems/maximal-rectangle/
#include <algorithm>
#include <iostream>
#include <stack>
#include <vector>

int largestRectangleArea(const std::vector<int>& heights) {
    const int n = static_cast<int>(heights.size());
    std::stack<int> st;
    int best = 0;
    for (int i = 0; i <= n; ++i) {
        const int h = i == n ? 0 : heights[static_cast<size_t>(i)];
        while (!st.empty() && heights[static_cast<size_t>(st.top())] > h) {
            const int height = heights[static_cast<size_t>(st.top())];
            st.pop();
            const int left = st.empty() ? -1 : st.top();
            best = std::max(best, height * (i - left - 1));
        }
        st.push(i);
    }
    return best;
}

int maximalRectangle(std::vector<std::vector<char>>& matrix) {
    if (matrix.empty()) return 0;
    const int n = static_cast<int>(matrix[0].size());
    std::vector<int> heights(n, 0);
    int best = 0;
    for (auto& row : matrix) {
        for (int j = 0; j < n; ++j) {
            heights[static_cast<size_t>(j)] = row[static_cast<size_t>(j)] == '1'
                                                 ? heights[static_cast<size_t>(j)] + 1 : 0;
        }
        best = std::max(best, largestRectangleArea(heights));
    }
    return best;
}

int main() {
    std::vector<std::vector<char>> m{{'1', '0', '1', '0', '0'},
                                     {'1', '0', '1', '1', '1'},
                                     {'1', '1', '1', '1', '1'},
                                     {'1', '0', '0', '1', '0'}};
    std::cout << maximalRectangle(m) << " (expected 6)\n";
    return 0;
}
