// Bubble Sort — classic O(N²) adjacent-swap sort
// Repeatedly swap out-of-order neighbors; largest sinks to the end each pass.
#include <iostream>
#include <utility>
#include <vector>

void bubbleSort(std::vector<int>& arr) {
    const int n = static_cast<int>(arr.size());
    for (int i = 0; i < n - 1; ++i) {
        bool swapped = false;
        for (int j = 0; j < n - i - 1; ++j) {
            if (arr[static_cast<size_t>(j)] > arr[static_cast<size_t>(j + 1)]) {
                std::swap(arr[static_cast<size_t>(j)], arr[static_cast<size_t>(j + 1)]);
                swapped = true; // mark pass as productive
            }
        }
        if (!swapped) { // already sorted
            break;
        }
    }
}

int main() {
    std::vector<int> arr = {64, 34, 25, 12, 22, 11, 90};
    bubbleSort(arr);
    for (size_t i = 0; i < arr.size(); ++i) {
        std::cout << arr[i] << (i + 1 < arr.size() ? " " : "");
    }
    std::cout << " (expected 11 12 22 25 34 64 90)\n";
    return 0;
}
