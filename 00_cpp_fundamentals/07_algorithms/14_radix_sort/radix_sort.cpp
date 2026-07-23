// Radix sort (LSD) — digit-by-digit counting sort
// Stable per digit; non-negative ints in this demo.
#include <algorithm>
#include <iostream>
#include <vector>

void countingSortForRadix(std::vector<int>& arr, int exp) {
    int n = static_cast<int>(arr.size());
    std::vector<int> output(n);
    std::vector<int> count(10, 0); // digit buckets 0..9
    for (int i = 0; i < n; ++i) {
        count[(arr[i] / exp) % 10]++; // tally digit
    }
    for (int i = 1; i < 10; ++i) {
        count[i] += count[i - 1]; // prefix → positions
    }
    for (int i = n - 1; i >= 0; --i) { // stable place
        int d = (arr[i] / exp) % 10;
        output[count[d] - 1] = arr[i];
        count[d]--;
    }
    for (int i = 0; i < n; ++i) {
        arr[i] = output[i]; // copy back
    }
}

void radixSort(std::vector<int>& arr) {
    if (arr.empty()) {
        return;
    }
    int max_val = *std::max_element(arr.begin(), arr.end());
    for (int exp = 1; max_val / exp > 0; exp *= 10) { // LSD → MSD
        countingSortForRadix(arr, exp);
    }
}

int main() {
    std::cout << "=== Algorithm: Radix Sort ===" << std::endl;
    std::vector<int> arr = {170, 45, 75, 90, 802, 24, 2, 66};
    radixSort(arr);
    std::cout << "Sorted: ";
    for (int x : arr) {
        std::cout << x << " ";
    }
    std::cout << std::endl;
    return 0;
}
