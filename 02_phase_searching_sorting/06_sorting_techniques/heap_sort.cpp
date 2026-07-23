// Heap Sort — classic guaranteed O(N log N) in-place sort
// Build a max-heap, then repeatedly extract the maximum to the end.
#include <iostream>
#include <utility>
#include <vector>

void heapify(std::vector<int>& arr, int n, int root) {
    int largest = root;
    const int left = 2 * root + 1;
    const int right = 2 * root + 2;
    if (left < n && arr[static_cast<size_t>(left)] > arr[static_cast<size_t>(largest)]) {
        largest = left;
    }
    if (right < n && arr[static_cast<size_t>(right)] > arr[static_cast<size_t>(largest)]) {
        largest = right;
    }
    if (largest != root) {
        std::swap(arr[static_cast<size_t>(root)], arr[static_cast<size_t>(largest)]);
        heapify(arr, n, largest); // sift down
    }
}

void heapSort(std::vector<int>& arr) {
    const int n = static_cast<int>(arr.size());
    for (int i = n / 2 - 1; i >= 0; --i) {
        heapify(arr, n, i); // build max-heap
    }
    for (int i = n - 1; i > 0; --i) {
        std::swap(arr[0], arr[static_cast<size_t>(i)]); // extract max
        heapify(arr, i, 0);
    }
}

int main() {
    std::vector<int> arr = {64, 34, 25, 12, 22, 11, 90};
    heapSort(arr);
    for (size_t i = 0; i < arr.size(); ++i) {
        std::cout << arr[i] << (i + 1 < arr.size() ? " " : "");
    }
    std::cout << " (expected 11 12 22 25 34 64 90)\n";
    return 0;
}
