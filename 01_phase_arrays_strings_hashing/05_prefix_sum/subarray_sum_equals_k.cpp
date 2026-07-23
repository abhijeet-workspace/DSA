// Subarray Sum Equals K — https://leetcode.com/problems/subarray-sum-equals-k/
// Count contiguous subarrays whose sum equals k (handles negatives).
#include <iostream>
#include <unordered_map>
#include <vector>

int subarraySumEqualsK(const std::vector<int>& nums, int k) {
    std::unordered_map<int, int> freq; // prefixSum -> how many times seen
    freq[0] = 1; // empty prefix so subarrays from index 0 count
    int count = 0;
    int prefixSum = 0;
    for (int x : nums) {
        prefixSum += x;
        count += freq[prefixSum - k]; // prior prefixes that complete sum k
        ++freq[prefixSum]; // record current prefix after querying
    }
    return count;
}

int main() {
    std::cout << subarraySumEqualsK({1, 1, 1}, 2) << " (expected 2)\n";
    std::cout << subarraySumEqualsK({1, 2, 3}, 3) << " (expected 2)\n";
    return 0;
}
