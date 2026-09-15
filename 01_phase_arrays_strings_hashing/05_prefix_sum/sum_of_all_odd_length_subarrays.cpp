// Sum of All Odd Length Subarrays — LC 1588
// Each arr[i] contributes to ((i+1)*(n-i)+1)/2 odd-length subarrays.
#include <iostream>
#include <vector>

int sumOddLengthSubarrays(const std::vector<int>& arr) {
    const int n = static_cast<int>(arr.size());
    int total = 0;
    for (int i = 0; i < n; ++i) {
        int endsLeft = i + 1;       // subarrays starting at ≤ i
        int endsRight = n - i;      // subarrays ending at ≥ i
        int count = (endsLeft * endsRight + 1) / 2; // odd-length ones containing i
        total += arr[static_cast<size_t>(i)] * count;
    }
    return total;
}

int main() {
    std::cout << sumOddLengthSubarrays({1, 4, 2, 5, 3}) << " (expected 58)\n";
    std::cout << sumOddLengthSubarrays({1, 2}) << " (expected 3)\n";
    std::cout << sumOddLengthSubarrays({10, 11, 12}) << " (expected 66)\n";
    return 0;
}
