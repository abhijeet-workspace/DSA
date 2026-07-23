// Quick Sort — local teaching demo
// Partition around a pivot, then recursively sort left/right parts.
#include <iostream>
#include <utility>
#include <vector>

class QuickSort {
private:
    int partition(std::vector<int>& arr, int low, int high) {
        int pivot = arr[high]; // last element as pivot
        int i = low - 1; // end of < pivot region
        for (int j = low; j < high; ++j) {
            if (arr[j] < pivot) {
                ++i;
                std::swap(arr[i], arr[j]);
            }
        }
        std::swap(arr[i + 1], arr[high]); // pivot final index
        return i + 1;
    }

public:
    void sort(std::vector<int>& arr, int low, int high) {
        if (low >= high) return;
        int pi = partition(arr, low, high);
        sort(arr, low, pi - 1);
        sort(arr, pi + 1, high);
    }
};

int main() {
    std::cout << "=== Test: Quick Sort ===\n";
    std::vector<int> arr = {10, 7, 8, 9, 1, 5};
    std::cout << "Original: ";
    for (int x : arr) std::cout << x << ' ';
    std::cout << '\n';

    QuickSort sorter;
    sorter.sort(arr, 0, static_cast<int>(arr.size()) - 1);

    std::cout << "Sorted: ";
    for (int x : arr) std::cout << x << ' ';
    std::cout << '\n';
    return 0;
}
