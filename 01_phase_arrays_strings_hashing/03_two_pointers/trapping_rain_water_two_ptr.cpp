// Trapping Rain Water — LC 42 (two pointers)
// Water at i = min(left_max,right_max)-h[i]; process the side with smaller height.
#include <iostream>
#include <vector>

int trap(const std::vector<int>& height) {
    if (height.empty()) return 0;
    int L = 0, R = static_cast<int>(height.size()) - 1;
    int left_max = 0, right_max = 0, water = 0;
    while (L < R) {
        if (height[static_cast<size_t>(L)] < height[static_cast<size_t>(R)]) {
            if (height[static_cast<size_t>(L)] >= left_max) left_max = height[static_cast<size_t>(L)];
            else water += left_max - height[static_cast<size_t>(L)];
            ++L;
        } else {
            if (height[static_cast<size_t>(R)] >= right_max) right_max = height[static_cast<size_t>(R)];
            else water += right_max - height[static_cast<size_t>(R)];
            --R;
        }
    }
    return water;
}

int main() {
    std::vector<int> height = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
    std::cout << "Trapped: " << trap(height) << " (expected 6)\n";
    return 0;
}
