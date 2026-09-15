// Minimum Swaps To Make Sequences Increasing — LeetCode 801
#include <algorithm>
#include <iostream>
#include <vector>

int minSwap(const std::vector<int>& A, const std::vector<int>& B) {
    int n = static_cast<int>(A.size());
    int keep = 0, swap = 1;
    for (int i = 1; i < n; ++i) {
        int nk = n + 1, ns = n + 1;
        if (A[static_cast<size_t>(i)] > A[static_cast<size_t>(i - 1)] &&
            B[static_cast<size_t>(i)] > B[static_cast<size_t>(i - 1)]) {
            nk = std::min(nk, keep);
            ns = std::min(ns, swap + 1);
        }
        if (A[static_cast<size_t>(i)] > B[static_cast<size_t>(i - 1)] &&
            B[static_cast<size_t>(i)] > A[static_cast<size_t>(i - 1)]) {
            nk = std::min(nk, swap);
            ns = std::min(ns, keep + 1);
        }
        keep = nk;
        swap = ns;
    }
    return std::min(keep, swap);
}

int main() {
    std::cout << minSwap({1, 3, 5, 4}, {1, 2, 3, 7}) << " (expected 1)\n";
    return 0;
}
