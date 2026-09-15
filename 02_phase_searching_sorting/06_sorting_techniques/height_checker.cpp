// Height Checker — LC 1051
// Count students not standing at expected height after nondecreasing sort.
#include <algorithm>
#include <iostream>
#include <vector>

int heightChecker(std::vector<int> heights) {
    std::vector<int> expected = heights;
    std::sort(expected.begin(), expected.end());
    int mismatch = 0;
    for (size_t i = 0; i < heights.size(); ++i) {
        if (heights[i] != expected[i]) {
            ++mismatch;
        }
    }
    return mismatch;
}

int main() {
    std::cout << heightChecker({1, 1, 4, 2, 1, 3}) << " (expected 3)\n";
    std::cout << heightChecker({5, 1, 2, 3, 4}) << " (expected 5)\n";
    std::cout << heightChecker({1, 2, 3, 4, 5}) << " (expected 0)\n";
    return 0;
}
