// Cyclic Sort — place each value v at index v-1 (range 1..N).
// In-place O(N) sort when numbers are a permutation of 1..N.
#include <iostream>
#include <vector>
#include <utility>

void cyclicSort(std::vector<int>& arr) {
    const int n = static_cast<int>(arr.size());
    int i = 0;
    while (i < n) {
        const int correct = arr[static_cast<size_t>(i)] - 1; // target index
        if (arr[static_cast<size_t>(i)] != arr[static_cast<size_t>(correct)]) {
            std::swap(arr[static_cast<size_t>(i)], arr[static_cast<size_t>(correct)]);
        } else {
            ++i;
        }
    }
}

int main() {
    std::vector<int> arr = {5, 4, 2, 3, 1};
    cyclicSort(arr);
    std::cout << "Sorted:";
    for (int x : arr) {
        std::cout << ' ' << x;
    }
    std::cout << " (expected 1 2 3 4 5)\n";
    return 0;
}
