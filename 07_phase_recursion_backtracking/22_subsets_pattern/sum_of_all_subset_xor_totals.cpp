// Sum of All Subset XOR Totals — https://leetcode.com/problems/sum-of-all-subset-xor-totals/
// Return sum of XOR-totals of every subset of nums.
#include <iostream>
#include <vector>

void dfs(const std::vector<int>& nums, int i, int curXor, int& sum) {
    if (i == static_cast<int>(nums.size())) {
        sum += curXor;
        return;
    }
    dfs(nums, i + 1, curXor, sum);                                // exclude
    dfs(nums, i + 1, curXor ^ nums[static_cast<size_t>(i)], sum); // include
}

int subsetXORSum(const std::vector<int>& nums) {
    int sum = 0;
    dfs(nums, 0, 0, sum);
    return sum;
}

int main() {
    std::cout << subsetXORSum({1, 3}) << " (expected 6)\n";
    std::cout << subsetXORSum({5, 1, 6}) << " (expected 28)\n";
    return 0;
}
