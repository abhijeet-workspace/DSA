// Binary Search — local teaching demo
// Locate target in a sorted array by repeatedly halving the search space.
#include <iostream>
#include <vector>

int binarySearch(const std::vector<int>& arr, int target) {
    int left = 0;
    int right = static_cast<int>(arr.size()) - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2; // avoid overflow
        if (arr[mid] == target) {
            return mid;
        }
        if (arr[mid] < target) {
            left = mid + 1; // go right
        } else {
            right = mid - 1; // go left
        }
    }
    return -1;
}

int main() {
    std::cout << "=== Algorithm: Binary Search ===\n";
    std::vector<int> arr = {10, 20, 30, 40, 50, 60};
    int target = 40;

    int index = binarySearch(arr, target);
    std::cout << "Array: ";
    for (int x : arr) std::cout << x << ' ';
    std::cout << '\n';
    std::cout << "Searching for " << target << " -> Index: " << index << '\n';
    return 0;
}
