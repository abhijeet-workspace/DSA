// Most Frequent Even Element — LC 2404
#include <iostream>
#include <unordered_map>
#include <vector>

int mostFrequentEven(const std::vector<int>& nums) {
    std::unordered_map<int, int> freq;
    for (int x : nums)
        if (x % 2 == 0)
            ++freq[x];
    int ans = -1, best = 0;
    for (const auto& [v, c] : freq) {
        if (c > best || (c == best && v < ans)) {
            best = c;
            ans = v;
        }
    }
    return ans;
}

int main() {
    std::cout << mostFrequentEven({0, 1, 2, 2, 4, 4, 1}) << " (expected 2)\n";
    std::cout << mostFrequentEven({4, 4, 4, 9, 2, 4}) << " (expected 4)\n";
    std::cout << mostFrequentEven({29, 47, 21, 41, 13, 37, 25, 7}) << " (expected -1)\n";
    return 0;
}
