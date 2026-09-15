// Total Hamming Distance — https://leetcode.com/problems/total-hamming-distance/
// Per bit: c set and (n-c) unset contribute c*(n-c).
#include <iostream>
#include <vector>

int totalHammingDistance(const std::vector<int>& nums) {
    const int n = static_cast<int>(nums.size());
    int ans = 0;
    for (int b = 0; b < 32; ++b) {
        int c = 0;
        for (int x : nums)
            c += (x >> b) & 1;
        ans += c * (n - c);
    }
    return ans;
}

int main() {
    std::cout << totalHammingDistance({4, 14, 2}) << " (expected 6)\n"
              << totalHammingDistance({4, 14, 4}) << " (expected 4)\n";
    return 0;
}
