// Find Lucky Integer in an Array — LC 1394
#include <algorithm>
#include <iostream>
#include <vector>

int findLucky(const std::vector<int>& arr) {
    int freq[501] = {};
    for (int x : arr)
        ++freq[x];
    for (int v = 500; v >= 1; --v)
        if (freq[v] == v)
            return v;
    return -1;
}

int main() {
    std::cout << findLucky({2, 2, 3, 4}) << " (expected 2)\n";
    std::cout << findLucky({1, 2, 2, 3, 3, 3}) << " (expected 3)\n";
    std::cout << findLucky({2, 2, 2, 3, 3}) << " (expected -1)\n";
    return 0;
}
