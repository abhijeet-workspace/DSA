// Longest Arithmetic Subsequence of Given Difference — https://leetcode.com/problems/longest-arithmetic-subsequence-of-given-difference/
#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>

int longestSubsequence(std::vector<int>& arr, int difference) {
    std::unordered_map<int, int> best;
    int ans = 0;
    for (int x : arr) {
        best[x] = (best.count(x - difference) ? best[x - difference] : 0) + 1;
        ans = std::max(ans, best[x]);
    }
    return ans;
}

int main() {
    std::vector<int> arr{1, 2, 3, 4};
    std::cout << longestSubsequence(arr, 1) << " (expected 4)\n";
    return 0;
}
