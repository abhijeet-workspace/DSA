// Counting Sort — local teaching demo
// Count frequencies in value range, then write values back in order.
#include <algorithm>
#include <iostream>
#include <vector>

void countingSort(std::vector<int>& arr) {
    if (arr.empty()) return;
    int max_val = *std::max_element(arr.begin(), arr.end());
    int min_val = *std::min_element(arr.begin(), arr.end());
    int range = max_val - min_val + 1;

    std::vector<int> count(range, 0);
    std::vector<int> output(arr.size());

    for (int x : arr) ++count[x - min_val]; // frequencies
    for (size_t i = 1; i < count.size(); ++i) count[i] += count[i - 1]; // prefix

    for (int i = static_cast<int>(arr.size()) - 1; i >= 0; --i) { // stable place
        int x = arr[i];
        output[count[x - min_val] - 1] = x;
        --count[x - min_val];
    }
    arr = output;
}

int main() {
    std::cout << "=== Algorithm: Counting Sort ===\n";
    std::vector<int> arr = {4, 2, 2, 8, 3, 3, 1};
    countingSort(arr);
    std::cout << "Sorted: ";
    for (int x : arr) std::cout << x << ' ';
    std::cout << '\n';
    return 0;
}
