// Bubble Sort — local teaching demo
// Repeatedly swap adjacent out-of-order pairs until sorted.
#include <iostream>
#include <utility>
#include <vector>

std::vector<int> bubbleSort(std::vector<int> arr) {
    int n = static_cast<int>(arr.size());
    for (int i = 0; i < n - 1; ++i) { // n-1 passes
        for (int j = 0; j < n - i - 1; ++j) { // last i items already placed
            if (arr[j] > arr[j + 1]) {
                std::swap(arr[j], arr[j + 1]); // bubble larger right
            }
        }
    }
    return arr;
}

int main() {
    std::cout << "Implementing Bubble Sort\n";
    std::vector<int> arr = {5, 4, 6, 8, 2, 1};
    arr = bubbleSort(arr);
    std::cout << "Sorted Array:\n";
    for (int x : arr) std::cout << x << ' ';
    std::cout << '\n';
    return 0;
}
