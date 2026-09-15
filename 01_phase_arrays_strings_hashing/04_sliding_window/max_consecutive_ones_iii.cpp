// Max Consecutive Ones III — LC 1004
// Longest window with at most k zeros (flip zeros to ones).
#include <iostream>
#include <vector>
#include <algorithm>

int longestOnes(const std::vector<int>& nums, int k) {
    int left = 0;
    int zeros = 0;
    int best = 0;
    for (int right = 0; right < static_cast<int>(nums.size()); ++right) {
        if (nums[static_cast<size_t>(right)] == 0) ++zeros;
        while (zeros > k) {
            if (nums[static_cast<size_t>(left)] == 0) --zeros;
            ++left;
        }
        best = std::max(best, right - left + 1);
    }
    return best;
}

int main() {
    std::cout << longestOnes({1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 0}, 2)
              << " (expected 6)\n";
    std::cout << longestOnes({0, 0, 1, 1, 0, 0, 1, 1, 1, 0, 1, 1, 0, 0, 0, 1, 1, 1, 1}, 3)
              << " (expected 10)\n";
    return 0;
}
