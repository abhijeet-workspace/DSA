// Find K Closest Elements — https://leetcode.com/problems/find-k-closest-elements/
// Sorted arr; return k closest to x as a sorted window. Binary-search the window start.
#include <iostream>
#include <vector>

std::vector<int> findClosestElements(const std::vector<int>& arr, int k, int x) {
    int lo = 0;
    int hi = static_cast<int>(arr.size()) - k;
    while (lo < hi) {
        const int mid = lo + (hi - lo) / 2;
        // window [mid, mid+k): prefer left if x is closer to mid than to mid+k
        if (x - arr[static_cast<size_t>(mid)] > arr[static_cast<size_t>(mid + k)] - x) {
            lo = mid + 1;
        } else {
            hi = mid;
        }
    }
    return {arr.begin() + lo, arr.begin() + lo + k};
}

int main() {
    const auto a = findClosestElements({1, 2, 3, 4, 5}, 4, 3);
    const auto b = findClosestElements({1, 1, 2, 3, 4, 5}, 4, -1);
    std::cout << a[0] << " " << a[1] << " " << a[2] << " " << a[3] << " (expected 1 2 3 4)\n";
    std::cout << b[0] << " " << b[1] << " " << b[2] << " " << b[3] << " (expected 1 1 2 3)\n";
    return 0;
}
