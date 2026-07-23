// Merge Sort — classic stable O(N log N) divide-and-conquer
// Sort halves recursively, then merge two sorted runs in linear time.
#include <iostream>
#include <vector>

void merge(std::vector<int>& arr, int lo, int mid, int hi) {
    std::vector<int> left(arr.begin() + lo, arr.begin() + mid + 1);
    std::vector<int> right(arr.begin() + mid + 1, arr.begin() + hi + 1);
    int i = 0, j = 0, k = lo;
    while (i < static_cast<int>(left.size()) && j < static_cast<int>(right.size())) {
        arr[static_cast<size_t>(k++)] =
            (left[static_cast<size_t>(i)] <= right[static_cast<size_t>(j)])
                ? left[static_cast<size_t>(i++)]
                : right[static_cast<size_t>(j++)]; // <= keeps stable
    }
    while (i < static_cast<int>(left.size())) {
        arr[static_cast<size_t>(k++)] = left[static_cast<size_t>(i++)];
    }
    while (j < static_cast<int>(right.size())) {
        arr[static_cast<size_t>(k++)] = right[static_cast<size_t>(j++)];
    }
}

void mergeSort(std::vector<int>& arr, int lo, int hi) {
    if (lo >= hi) {
        return;
    }
    const int mid = lo + (hi - lo) / 2; // avoid overflow
    mergeSort(arr, lo, mid);
    mergeSort(arr, mid + 1, hi);
    merge(arr, lo, mid, hi);
}

int main() {
    std::vector<int> arr = {64, 34, 25, 12, 22, 11, 90};
    mergeSort(arr, 0, static_cast<int>(arr.size()) - 1);
    for (size_t i = 0; i < arr.size(); ++i) {
        std::cout << arr[i] << (i + 1 < arr.size() ? " " : "");
    }
    std::cout << " (expected 11 12 22 25 34 64 90)\n";
    return 0;
}
