// Maximal Rectangle — https://leetcode.com/problems/maximal-rectangle/
// Largest rectangle of 1s in a binary matrix (histogram largest-rectangle per row).
#include <algorithm>
#include <iostream>
#include <stack>
#include <vector>

int largestRectangleArea(std::vector<int>& heights) {
    std::stack<int> st;
    int max_area = 0;
    heights.push_back(0); // sentinel flush
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
    heights.pop_back();
    return max_area;
}

int maximalRectangle(const std::vector<std::vector<char>>& matrix) {
    if (matrix.empty() || matrix[0].empty()) {
        return 0;
    }
    const int cols = static_cast<int>(matrix[0].size());
    std::vector<int> heights(static_cast<size_t>(cols), 0);
    int best = 0;
    for (const auto& row : matrix) {
        for (int j = 0; j < cols; ++j) {
            heights[static_cast<size_t>(j)] =
                row[static_cast<size_t>(j)] == '1'
                    ? heights[static_cast<size_t>(j)] + 1
                    : 0;
        }
        best = std::max(best, largestRectangleArea(heights));
    }
    return best;
}

int main() {
    const std::vector<std::vector<char>> matrix = {
        {'1', '0', '1', '0', '0'},
        {'1', '0', '1', '1', '1'},
        {'1', '1', '1', '1', '1'},
        {'1', '0', '0', '1', '0'},
    };
    std::cout << maximalRectangle(matrix) << " (expected 6)\n";
    return 0;
}
