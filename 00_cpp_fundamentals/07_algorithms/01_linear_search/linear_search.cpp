// Linear Search — local teaching demo
// Find target index by scanning left to right; return -1 if absent.
#include <iostream>
#include <vector>

int linearSearch(const std::vector<int>& arr, int target) {
    for (int i = 0; i < static_cast<int>(arr.size()); ++i) { // scan each index
        if (arr[i] == target) {
            return i; // first hit
        }
    }
    return -1; // not found
}

int main() {
    std::cout << "=== Algorithm: Linear Search ===\n";
    std::vector<int> arr = {5, 3, 8, 4, 2, 7, 1, 9};
    int target = 4;

    int index = linearSearch(arr, target);
    std::cout << "Array: ";
    for (int x : arr) std::cout << x << ' ';
    std::cout << '\n';
    std::cout << "Searching for " << target << " -> Index: " << index << '\n';

    target = 10;
    index = linearSearch(arr, target);
    std::cout << "Searching for " << target << " -> Index: " << index << '\n';
    return 0;
}
