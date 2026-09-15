// Count Elements With Maximum Frequency — LC 3005
#include <algorithm>
#include <iostream>
#include <vector>

int maxFrequencyElements(const std::vector<int>& nums) {
    int freq[101] = {};
    int best = 0;
    for (int x : nums)
        best = std::max(best, ++freq[x]);
    int ans = 0;
    for (int c : freq)
        if (c == best)
            ans += c;
    return ans;
}

int main() {
    std::cout << maxFrequencyElements({1, 2, 2, 3, 1, 4}) << " (expected 4)\n";
    std::cout << maxFrequencyElements({1, 2, 3, 4, 5}) << " (expected 5)\n";
    return 0;
}
