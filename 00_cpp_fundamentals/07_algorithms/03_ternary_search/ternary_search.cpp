// Ternary Search — local teaching demo
// Divide sorted range into three parts using two midpoints.
#include <iostream>
#include <vector>

int ternarySearch(const std::vector<int>& arr, int target) {
    int left = 0;
    int right = static_cast<int>(arr.size()) - 1;

    while (left <= right) {
        int mid1 = left + (right - left) / 3;
        int mid2 = right - (right - left) / 3;

        if (arr[mid1] == target) return mid1;
        if (arr[mid2] == target) return mid2;

        if (target < arr[mid1]) {
            right = mid1 - 1;
        } else if (target > arr[mid2]) {
            left = mid2 + 1;
        } else {
            left = mid1 + 1;
            right = mid2 - 1;
        }
    }
    return -1;
}

int main() {
    std::cout << "=== Algorithm: Ternary Search ===\n";
    std::vector<int> arr = {10, 20, 30, 40, 50, 60, 70};
    int target = 60;
    int index = ternarySearch(arr, target);
    std::cout << "Searching for " << target << " -> Index: " << index << '\n';
    return 0;
}
