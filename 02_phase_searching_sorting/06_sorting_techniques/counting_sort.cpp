// Counting Sort — stable non-comparison sort for small key range
// Count keys, prefix-sum to positions, place from the back for stability.
#include <algorithm>
#include <iostream>
#include <vector>

void countingSort(std::vector<int>& arr, int maxVal) {
    std::vector<int> count(static_cast<size_t>(maxVal) + 1, 0);
    for (int x : arr) {
        ++count[static_cast<size_t>(x)];
    }
    for (int i = 1; i <= maxVal; ++i) {
        count[static_cast<size_t>(i)] += count[static_cast<size_t>(i - 1)]; // prefix
    }
    std::vector<int> output(arr.size());
    for (int i = static_cast<int>(arr.size()) - 1; i >= 0; --i) {
        output[static_cast<size_t>(--count[static_cast<size_t>(arr[static_cast<size_t>(i)])])] =
            arr[static_cast<size_t>(i)]; // stable place
    }
    arr = output;
}

int main() {
    std::vector<int> arr = {4, 2, 2, 8, 3, 3, 1};
    const int maxVal = *std::max_element(arr.begin(), arr.end());
    countingSort(arr, maxVal);
    for (size_t i = 0; i < arr.size(); ++i) {
        std::cout << arr[i] << (i + 1 < arr.size() ? " " : "");
    }
    std::cout << " (expected 1 2 2 3 3 4 8)\n";
    return 0;
}
