// Linear search — find index of key in array
// Scan left to right; stop at first match.
#include <iostream>

int main() {
    int arr[] = {10, 20, 30, 40, 50}; // demo data
    int n = sizeof(arr) / sizeof(arr[0]); // length
    int searchKey = 0;
    int onIndex = -1; // sentinel: not found
    std::cout << "Enter element to search: ";
    std::cin >> searchKey;
    for (int i = 0; i < n; ++i) { // scan
        if (arr[i] == searchKey) {
            onIndex = i; // record hit
            break; // first match only
        }
    }
    if (onIndex != -1) {
        std::cout << "Element found at index: " << onIndex << std::endl;
    } else {
        std::cout << "Element not found in the array." << std::endl;
    }
    return 0;
}
