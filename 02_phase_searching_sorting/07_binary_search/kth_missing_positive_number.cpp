// Kth Missing Positive Number — https://leetcode.com/problems/kth-missing-positive-number/
// arr strictly increasing positives; missing count at i is arr[i]-(i+1). Binary search that.
#include <iostream>
#include <vector>

int findKthPositive(const std::vector<int>& arr, int k) {
    int lo = 0;
    int hi = static_cast<int>(arr.size()) - 1;
    while (lo <= hi) {
        const int mid = lo + (hi - lo) / 2;
        const int missing = arr[static_cast<size_t>(mid)] - (mid + 1);
        if (missing < k) {
            lo = mid + 1;
        } else {
            hi = mid - 1;
        }
    }
    return lo + k; // hi is last index with missing < k
}

int main() {
    std::cout << findKthPositive({2, 3, 4, 7, 11}, 5) << " (expected 9)\n"
              << findKthPositive({1, 2, 3, 4}, 2) << " (expected 6)\n";
    return 0;
}
