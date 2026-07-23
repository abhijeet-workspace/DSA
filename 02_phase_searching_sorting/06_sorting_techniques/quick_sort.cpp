// Quick Sort — randomized-pivot Lomuto partition
// Partition around a pivot, then recursively sort both sides.
#include <cstdlib>
#include <iostream>
#include <utility>
#include <vector>

int partition(std::vector<int>& arr, int lo, int hi) {
    const int pivotIdx = lo + std::rand() % (hi - lo + 1);
    std::swap(arr[static_cast<size_t>(pivotIdx)], arr[static_cast<size_t>(hi)]);
    const int pivot = arr[static_cast<size_t>(hi)];
    int i = lo - 1;
    for (int j = lo; j < hi; ++j) {
        if (arr[static_cast<size_t>(j)] <= pivot) {
            std::swap(arr[static_cast<size_t>(++i)], arr[static_cast<size_t>(j)]);
        }
    }
    std::swap(arr[static_cast<size_t>(i + 1)], arr[static_cast<size_t>(hi)]); // pivot home
    return i + 1;
}

void quickSort(std::vector<int>& arr, int lo, int hi) {
    if (lo >= hi) {
        return;
    }
    const int pi = partition(arr, lo, hi);
    quickSort(arr, lo, pi - 1);
    quickSort(arr, pi + 1, hi);
}

int main() {
    std::srand(42);
    std::vector<int> arr = {64, 34, 25, 12, 22, 11, 90};
    quickSort(arr, 0, static_cast<int>(arr.size()) - 1);
    for (size_t i = 0; i < arr.size(); ++i) {
        std::cout << arr[i] << (i + 1 < arr.size() ? " " : "");
    }
    std::cout << " (expected 11 12 22 25 34 64 90)\n";
    return 0;
}
