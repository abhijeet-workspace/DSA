// Container With Most Water — LC 11
// Area = min(h[L],h[R])*(R-L); move the shorter wall inward.
#include <iostream>
#include <vector>
#include <algorithm>

int maxArea(const std::vector<int>& height) {
    int L = 0;
    int R = static_cast<int>(height.size()) - 1;
    int best = 0;
    while (L < R) {
        int h = std::min(height[static_cast<size_t>(L)], height[static_cast<size_t>(R)]);
        best = std::max(best, h * (R - L));
        if (height[static_cast<size_t>(L)] < height[static_cast<size_t>(R)]) ++L;
        else --R;
    }
    return best;
}

int main() {
    std::cout << maxArea({1, 8, 6, 2, 5, 4, 8, 3, 7}) << " (expected 49)\n";
    return 0;
}
