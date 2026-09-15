// Permutation Sequence — https://leetcode.com/problems/permutation-sequence/
// Return the k-th permutation of [1..n] (1-indexed) without generating all.
#include <iostream>
#include <string>
#include <vector>

std::string getPermutation(int n, int k) {
    std::vector<int> nums;
    for (int i = 1; i <= n; ++i) nums.push_back(i);
    std::vector<int> fact(static_cast<size_t>(n), 1);
    for (int i = 1; i < n; ++i) fact[static_cast<size_t>(i)] = fact[static_cast<size_t>(i - 1)] * i;
    --k; // 0-index
    std::string ans;
    for (int i = n; i >= 1; --i) {
        const int f = fact[static_cast<size_t>(i - 1)];
        const int idx = k / f;
        ans.push_back(static_cast<char>('0' + nums[static_cast<size_t>(idx)]));
        nums.erase(nums.begin() + idx);
        k %= f;
    }
    return ans;
}

int main() {
    std::cout << getPermutation(3, 3) << " (expected 213)\n";
    std::cout << getPermutation(4, 9) << " (expected 2314)\n";
    return 0;
}
