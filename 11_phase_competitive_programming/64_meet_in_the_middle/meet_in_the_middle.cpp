// Meet in the Middle — subset-sum style for N ≈ 40
// Split into two halves, enumerate 2^(N/2) each, then match complements.
#include <algorithm>
#include <iostream>
#include <vector>

void enumerateSums(const std::vector<int>& a, std::vector<long long>& out) {
    const int n = static_cast<int>(a.size());
    const int total = 1 << n;
    out.resize(static_cast<size_t>(total));
    for (int mask = 0; mask < total; ++mask) {
        long long sum = 0;
        for (int i = 0; i < n; ++i) {
            if (mask & (1 << i))
                sum += a[static_cast<size_t>(i)];
        }
        out[static_cast<size_t>(mask)] = sum;
    }
}

bool meetInTheMiddle(const std::vector<int>& arr, long long target) {
    const int n = static_cast<int>(arr.size());
    std::vector<int> left(arr.begin(), arr.begin() + n / 2);
    std::vector<int> right(arr.begin() + n / 2, arr.end());

    std::vector<long long> sumsL, sumsR;
    enumerateSums(left, sumsL);
    enumerateSums(right, sumsR);
    std::sort(sumsR.begin(), sumsR.end());

    for (long long s : sumsL) {
        long long need = target - s;
        if (std::binary_search(sumsR.begin(), sumsR.end(), need))
            return true;
    }
    return false;
}

int main() {
    std::vector<int> arr = {3, 34, 4, 12, 5, 2};
    long long target = 9;
    std::cout << "Subset sum " << target << "? " << (meetInTheMiddle(arr, target) ? "yes" : "no")
              << "\n"; // yes (4+5)
    target = 30;
    std::cout << "Subset sum " << target << "? " << (meetInTheMiddle(arr, target) ? "yes" : "no")
              << "\n"; // no
    return 0;
}
