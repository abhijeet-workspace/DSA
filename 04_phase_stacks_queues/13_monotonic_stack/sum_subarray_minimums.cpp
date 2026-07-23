// Sum of Subarray Minimums — https://leetcode.com/problems/sum-of-subarray-minimums/
// Sum min(subarray) over all contiguous subarrays, mod 1e9+7.
#include <iostream>
#include <stack>
#include <utility>
#include <vector>

int sumSubarrayMins(const std::vector<int>& arr) {
    const int n = static_cast<int>(arr.size());
    constexpr long long MOD = 1'000'000'007LL;
    std::vector<int> left(static_cast<size_t>(n));  // span to previous smaller
    std::vector<int> right(static_cast<size_t>(n)); // span to next smaller-or-equal
    std::stack<std::pair<int, int>> s1, s2;         // {value, count}

    for (int i = 0; i < n; ++i) {
        int count = 1;
        while (!s1.empty() && s1.top().first > arr[static_cast<size_t>(i)]) {
            count += s1.top().second;
            s1.pop();
        }
        s1.push({arr[static_cast<size_t>(i)], count});
        left[static_cast<size_t>(i)] = count;
    }
    for (int i = n - 1; i >= 0; --i) {
        int count = 1;
        while (!s2.empty() && s2.top().first >= arr[static_cast<size_t>(i)]) {
            count += s2.top().second;
            s2.pop();
        }
        s2.push({arr[static_cast<size_t>(i)], count});
        right[static_cast<size_t>(i)] = count;
    }

    long long result = 0;
    for (int i = 0; i < n; ++i) {
        const long long contrib =
            static_cast<long long>(left[static_cast<size_t>(i)]) *
            static_cast<long long>(right[static_cast<size_t>(i)]) % MOD;
        result = (result + static_cast<long long>(arr[static_cast<size_t>(i)]) * contrib) % MOD;
    }
    return static_cast<int>(result);
}

int main() {
    const std::vector<int> arr = {3, 1, 2, 4};
    std::cout << "Sum of subarray mins: " << sumSubarrayMins(arr)
              << " (expected 17)\n";
    return 0;
}
