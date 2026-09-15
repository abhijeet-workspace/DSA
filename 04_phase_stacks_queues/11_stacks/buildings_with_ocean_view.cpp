// Buildings With an Ocean View — https://leetcode.com/problems/buildings-with-an-ocean-view/
// Indices of buildings that can see the ocean to the right (strictly taller than all to the right).
#include <algorithm>
#include <iostream>
#include <vector>

std::vector<int> findBuildings(const std::vector<int>& heights) {
    std::vector<int> ans;
    int maxRight = 0;
    for (int i = static_cast<int>(heights.size()) - 1; i >= 0; --i) {
        if (heights[static_cast<size_t>(i)] > maxRight) {
            ans.push_back(i);
            maxRight = heights[static_cast<size_t>(i)];
        }
    }
    std::reverse(ans.begin(), ans.end());
    return ans;
}

int main() {
    const auto a = findBuildings({4, 2, 3, 1});
    for (size_t i = 0; i < a.size(); ++i) {
        if (i) std::cout << ' ';
        std::cout << a[i];
    }
    std::cout << " (expected 0 2 3)\n";
    const auto b = findBuildings({4, 3, 2, 1});
    for (size_t i = 0; i < b.size(); ++i) {
        if (i) std::cout << ' ';
        std::cout << b[i];
    }
    std::cout << " (expected 0 1 2 3)\n";
    return 0;
}
