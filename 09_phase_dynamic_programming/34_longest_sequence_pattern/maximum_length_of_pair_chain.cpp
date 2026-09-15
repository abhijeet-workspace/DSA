// Maximum Length of Pair Chain — https://leetcode.com/problems/maximum-length-of-pair-chain/
#include <algorithm>
#include <climits>
#include <iostream>
#include <vector>

int findLongestChain(std::vector<std::vector<int>>& pairs) {
    std::sort(pairs.begin(), pairs.end(), [](const auto& a, const auto& b) { return a[1] < b[1]; });
    int ans = 0, end = INT_MIN;
    for (auto& p : pairs) {
        if (p[0] > end) {
            ++ans;
            end = p[1];
        }
    }
    return ans;
}

int main() {
    std::vector<std::vector<int>> pairs{{1, 2}, {2, 3}, {3, 4}};
    std::cout << findLongestChain(pairs) << " (expected 2)\n";
    return 0;
}
