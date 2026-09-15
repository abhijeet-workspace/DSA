// Fibonacci Search — local teaching demo
// Narrow a sorted range using Fibonacci numbers instead of midpoints.
#include <algorithm>
#include <iostream>
#include <vector>

int fibonacciSearch(const std::vector<int>& arr, int target) {
    const int n = static_cast<int>(arr.size());
    if (n == 0)
        return -1;

    int fibMMm2 = 0;              // F(k-2)
    int fibMMm1 = 1;              // F(k-1)
    int fibM = fibMMm1 + fibMMm2; // F(k)

    while (fibM < n) {
        fibMMm2 = fibMMm1;
        fibMMm1 = fibM;
        fibM = fibMMm1 + fibMMm2;
    }

    int offset = -1;
    while (fibM > 1) {
        int i = std::min(offset + fibMMm2, n - 1);
        if (arr[i] < target) {
            fibM = fibMMm1;
            fibMMm1 = fibMMm2;
            fibMMm2 = fibM - fibMMm1;
            offset = i;
        } else if (arr[i] > target) {
            fibM = fibMMm2;
            fibMMm1 = fibMMm1 - fibMMm2;
            fibMMm2 = fibM - fibMMm1;
        } else {
            return i;
        }
    }

    if (fibMMm1 && offset + 1 < n && arr[offset + 1] == target) {
        return offset + 1;
    }
    return -1;
}

int main() {
    std::cout << "=== Algorithm: Fibonacci Search ===\n";
    std::vector<int> arr = {10, 22, 35, 40, 45, 50, 80, 82, 85, 90, 100};
    int target = 85;
    int index = fibonacciSearch(arr, target);
    std::cout << "Searching for " << target << " -> Index: " << index << '\n';
    return 0;
}
