// Length of Longest Fibonacci Subsequence — https://leetcode.com/problems/length-of-longest-fibonacci-subsequence/
#include <algorithm>
#include <iostream>
#include <unordered_set>
#include <vector>

int lenLongestFibSubseq(std::vector<int>& arr) {
    std::unordered_set<int> s(arr.begin(), arr.end());
    int ans = 0;
    const int n = static_cast<int>(arr.size());
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            long long x = arr[static_cast<size_t>(i)], y = arr[static_cast<size_t>(j)];
            int len = 2;
            while (s.count(static_cast<int>(x + y))) {
                const long long z = x + y;
                x = y; y = z; ++len;
            }
            if (len >= 3) ans = std::max(ans, len);
        }
    }
    return ans;
}

int main() {
    std::vector<int> arr{1, 2, 3, 4, 5, 6, 7, 8};
    std::cout << lenLongestFibSubseq(arr) << " (expected 5)\n";
    return 0;
}
