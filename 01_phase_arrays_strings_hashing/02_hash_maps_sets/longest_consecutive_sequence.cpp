// Longest Consecutive Sequence — LC 128
// Start streaks only where x-1 missing; expand with set lookups.
#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>

int longestConsecutive(const std::vector<int>& nums) {
    std::unordered_set<int> s(nums.begin(), nums.end());
    int best = 0;
    for (int x : s) {
        if (s.count(x - 1)) continue; // not a streak start
        int y = x, len = 1;
        while (s.count(y + 1)) { ++y; ++len; }
        best = std::max(best, len);
    }
    return best;
}

int main() {
    std::cout << longestConsecutive({100, 4, 200, 1, 3, 2})
              << " (expected 4)\n";
    return 0;
}
