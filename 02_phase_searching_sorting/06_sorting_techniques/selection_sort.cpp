// Selection Sort — classic O(N²) min-selection sort
// Place the minimum of the unsorted suffix at the next prefix index.
#include <iostream>
#include <utility>
#include <vector>

void selectionSort(std::vector<int>& arr) {
    const int n = static_cast<int>(arr.size());
    for (int i = 0; i < n - 1; ++i) {
        int minIdx = i;
        for (int j = i + 1; j < n; ++j) {
            if (arr[static_cast<size_t>(j)] < arr[static_cast<size_t>(minIdx)]) {
                minIdx = j; // track min in unsorted range
            }
        }
        std::swap(arr[static_cast<size_t>(i)], arr[static_cast<size_t>(minIdx)]);
    }
}

int main() {
    std::vector<int> arr = {64, 34, 25, 12, 22, 11, 90};
    selectionSort(arr);
    for (size_t i = 0; i < arr.size(); ++i) {
        std::cout << arr[i] << (i + 1 < arr.size() ? " " : "");
    }
    std::cout << " (expected 11 12 22 25 34 64 90)\n";
    return 0;
}
