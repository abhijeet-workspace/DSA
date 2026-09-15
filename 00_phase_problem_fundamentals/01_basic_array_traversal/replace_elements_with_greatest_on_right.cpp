// Replace Elements with Greatest Element on Right Side — LC 1299
// ans[i] = max(arr[i+1..]); last becomes -1. Scan right → left.
#include <algorithm>
#include <iostream>
#include <vector>

std::vector<int> replaceElements(std::vector<int> arr) {
    int maxRight = -1;
    for (int i = static_cast<int>(arr.size()) - 1; i >= 0; --i) {
        const int cur = arr[static_cast<size_t>(i)];
        arr[static_cast<size_t>(i)] = maxRight;
        maxRight = std::max(maxRight, cur);
    }
    return arr;
}

int main() {
    for (int x : replaceElements({17, 18, 5, 4, 6, 1}))
        std::cout << x << " ";
    std::cout << "(expected 18 6 6 6 1 -1)\n";
    return 0;
}
