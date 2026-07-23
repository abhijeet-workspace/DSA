// Insertion Sort — classic adaptive O(N²)/O(N) sort
// Grow a sorted prefix by inserting each next key into its place.
#include <iostream>
#include <vector>

void insertionSort(std::vector<int>& arr) {
    const int n = static_cast<int>(arr.size());
    for (int i = 1; i < n; ++i) {
        const int key = arr[static_cast<size_t>(i)];
        int j = i - 1;
        while (j >= 0 && arr[static_cast<size_t>(j)] > key) {
            arr[static_cast<size_t>(j + 1)] = arr[static_cast<size_t>(j)]; // shift right
            --j;
        }
        arr[static_cast<size_t>(j + 1)] = key; // insert hole
    }
}

int main() {
    std::vector<int> arr = {64, 34, 25, 12, 22, 11, 90};
    insertionSort(arr);
    for (size_t i = 0; i < arr.size(); ++i) {
        std::cout << arr[i] << (i + 1 < arr.size() ? " " : "");
    }
    std::cout << " (expected 11 12 22 25 34 64 90)\n";
    return 0;
}
