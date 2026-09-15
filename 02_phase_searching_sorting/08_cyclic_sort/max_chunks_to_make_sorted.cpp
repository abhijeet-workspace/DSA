// Max Chunks To Make Sorted — https://leetcode.com/problems/max-chunks-to-make-sorted/
// Permutation of 0..n-1: cut whenever running max equals index (prefix closed under homes).
#include <iostream>
#include <vector>
#include <algorithm>

int maxChunksToSorted(std::vector<int>& arr) {
    int mx = 0;
    int chunks = 0;
    for (int i = 0; i < static_cast<int>(arr.size()); ++i) {
        mx = std::max(mx, arr[static_cast<size_t>(i)]);
        if (mx == i) ++chunks;
    }
    return chunks;
}

int main() {
    std::vector<int> a = {1, 0, 2, 3, 4};
    std::vector<int> b = {4, 3, 2, 1, 0};
    std::cout << maxChunksToSorted(a) << " (expected 4)\n"
              << maxChunksToSorted(b) << " (expected 1)\n";
    return 0;
}
