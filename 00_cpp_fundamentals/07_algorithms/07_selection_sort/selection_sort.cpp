// Selection Sort — local teaching demo
// Repeatedly select the minimum of the unsorted suffix and swap it into place.
#include <iostream>
#include <utility>
#include <vector>

void selectionSort(std::vector<int>& arr) {
    int n = static_cast<int>(arr.size());
    for (int i = 0; i < n - 1; ++i) {
        int smallIndex = i; // assume current prefix slot holds min
        for (int j = i + 1; j < n; ++j) {
            if (arr[j] < arr[smallIndex]) {
                smallIndex = j; // tighter minimum
            }
        }
        std::swap(arr[i], arr[smallIndex]); // lock position i
    }
}

void printSortedArray(const std::vector<int>& arr) {
    for (int x : arr) std::cout << x << ' ';
}

int main() {
    std::vector<int> arr = {5, 4, 2, 3, 1};
    std::cout << "Implementing Selection Sort\n";
    selectionSort(arr);
    std::cout << "Sorted Array: ";
    printSortedArray(arr);
    std::cout << '\n';
    return 0;
}
