// Longest Turbulent Subarray — https://leetcode.com/problems/longest-turbulent-subarray/
#include <algorithm>
#include <iostream>
#include <vector>

int maxTurbulenceSize(std::vector<int>& arr) {
    const int n = static_cast<int>(arr.size());
    int ans = 1, up = 1, down = 1;
    for (int i = 1; i < n; ++i) {
        if (arr[static_cast<size_t>(i)] > arr[static_cast<size_t>(i - 1)]) {
            up = down + 1;
            down = 1;
        } else if (arr[static_cast<size_t>(i)] < arr[static_cast<size_t>(i - 1)]) {
            down = up + 1;
            up = 1;
        } else {
            up = down = 1;
        }
        ans = std::max({ans, up, down});
    }
    return ans;
}

int main() {
    std::vector<int> arr{9, 4, 2, 10, 7, 8, 8, 1, 9};
    std::cout << maxTurbulenceSize(arr) << " (expected 5)\n";
    return 0;
}
