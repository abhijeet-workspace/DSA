// Radix Sort — LSD base-10 via stable digit counting sorts
// Sort non-negative ints digit-by-digit from least to most significant.
#include <algorithm>
#include <iostream>
#include <vector>

void countingSortByDigit(std::vector<int>& arr, int exp) {
    const int n = static_cast<int>(arr.size());
    std::vector<int> output(static_cast<size_t>(n)), count(10, 0);
    for (int x : arr) {
        ++count[static_cast<size_t>((x / exp) % 10)];
    }
    for (int i = 1; i < 10; ++i) {
        count[static_cast<size_t>(i)] += count[static_cast<size_t>(i - 1)];
    }
    for (int i = n - 1; i >= 0; --i) {
        const int d = (arr[static_cast<size_t>(i)] / exp) % 10;
        output[static_cast<size_t>(--count[static_cast<size_t>(d)])] = arr[static_cast<size_t>(i)];
    }
    arr = output;
}

void radixSort(std::vector<int>& arr) {
    if (arr.empty()) {
        return;
    }
    const int maxVal = *std::max_element(arr.begin(), arr.end());
    for (int exp = 1; maxVal / exp > 0; exp *= 10) {
        countingSortByDigit(arr, exp); // one LSD pass
    }
}

int main() {
    std::vector<int> arr = {170, 45, 75, 90, 802, 24, 2, 66};
    radixSort(arr);
    for (size_t i = 0; i < arr.size(); ++i) {
        std::cout << arr[i] << (i + 1 < arr.size() ? " " : "");
    }
    std::cout << " (expected 2 24 45 66 75 90 170 802)\n";
    return 0;
}
