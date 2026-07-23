// Heap Sort — local teaching demo
// Build a max-heap, then repeatedly extract the max into the sorted suffix.
#include <iostream>
#include <utility>
#include <vector>

void heapify(std::vector<int>& arr, int n, int i) {
    int largest = i; // subtree root candidate
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    if (left < n && arr[left] > arr[largest]) largest = left;
    if (right < n && arr[right] > arr[largest]) largest = right;
    if (largest != i) {
        std::swap(arr[i], arr[largest]);
        heapify(arr, n, largest); // fix child
    }
}

void heapSort(std::vector<int>& arr) {
    int n = static_cast<int>(arr.size());
    for (int i = n / 2 - 1; i >= 0; --i) { // build heap
        heapify(arr, n, i);
    }
    for (int i = n - 1; i > 0; --i) {
        std::swap(arr[0], arr[i]); // move max to end
        heapify(arr, i, 0); // restore heap on shrink
    }
}

int main() {
    std::cout << "=== Algorithm: Heap Sort ===\n";
    std::vector<int> arr = {12, 11, 13, 5, 6, 7};
    heapSort(arr);
    std::cout << "Sorted: ";
    for (int x : arr) std::cout << x << ' ';
    std::cout << '\n';
    return 0;
}
