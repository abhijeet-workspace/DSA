// Exponential Search — local teaching demo
// Find a bounding range by doubling, then binary-search inside it.
#include <algorithm>
#include <iostream>
#include <vector>

int binarySearchHelper(const std::vector<int>& arr, int left, int right, int target) {
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == target) return mid;
        if (arr[mid] < target) left = mid + 1;
        else right = mid - 1;
    }
    return -1;
}

int exponentialSearch(const std::vector<int>& arr, int target) {
    if (arr.empty()) return -1;
    if (arr[0] == target) return 0;

    int i = 1;
    int n = static_cast<int>(arr.size());
    while (i < n && arr[i] <= target) { // double bound
        i *= 2;
    }

    return binarySearchHelper(arr, i / 2, std::min(i, n - 1), target);
}

int main() {
    std::cout << "=== Algorithm: Exponential Search ===\n";
    std::vector<int> arr = {5, 10, 15, 20, 25, 30, 35, 40, 45, 50};
    int target = 35;
    int index = exponentialSearch(arr, target);
    std::cout << "Searching for " << target << " -> Index: " << index << '\n';
    return 0;
}
