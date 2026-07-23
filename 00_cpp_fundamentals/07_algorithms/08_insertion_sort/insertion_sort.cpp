// Insertion Sort — local teaching demo
// Insert each element into the sorted prefix by shifting larger values right.
#include <iostream>
#include <vector>

std::vector<int> insertionSort(std::vector<int> arr) {
    int n = static_cast<int>(arr.size());
    for (int i = 1; i < n; ++i) {
        int key = arr[i]; // value to insert
        int j = i - 1;
        while (j >= 0 && arr[j] > key) { // shift right
            arr[j + 1] = arr[j];
            --j;
        }
        arr[j + 1] = key; // place key
    }
    return arr;
}

void printSortedArray(const std::vector<int>& arr) {
    for (int x : arr) std::cout << x << ' ';
}

int main() {
    std::vector<int> arr = {5, 4, 6, 8, 2, 1};
    arr = insertionSort(arr);
    std::cout << "Implementing Insertion Sort\n";
    std::cout << "Sorted Array:\n";
    printSortedArray(arr);
    std::cout << '\n';
    return 0;
}
