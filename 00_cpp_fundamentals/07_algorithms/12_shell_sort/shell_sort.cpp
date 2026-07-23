// Shell Sort — local teaching demo
// Insertion-sort with diminishing gaps so far-apart elements move sooner.
#include <iostream>
#include <vector>

void shellSort(std::vector<int>& arr) {
    int n = static_cast<int>(arr.size());
    for (int gap = n / 2; gap > 0; gap /= 2) { // gap sequence
        for (int i = gap; i < n; ++i) {
            int temp = arr[i];
            int j = i;
            while (j >= gap && arr[j - gap] > temp) {
                arr[j] = arr[j - gap]; // gapped shift
                j -= gap;
            }
            arr[j] = temp;
        }
    }
}

int main() {
    std::cout << "=== Algorithm: Shell Sort ===\n";
    std::vector<int> arr = {12, 34, 54, 2, 3};
    shellSort(arr);
    std::cout << "Sorted: ";
    for (int x : arr) std::cout << x << ' ';
    std::cout << '\n';
    return 0;
}
