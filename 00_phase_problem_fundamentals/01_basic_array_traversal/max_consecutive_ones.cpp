// Max Consecutive Ones — LC 485
// Longest run of 1s in a binary array.
#include <algorithm>
#include <iostream>
#include <vector>

int findMaxConsecutiveOnes(const std::vector<int>& nums) {
    int best = 0;
    int cur = 0;
    for (int x : nums) {
        if (x == 1) {
            ++cur;
            best = std::max(best, cur);
        } else {
            cur = 0;
        }
    }
    return best;
}

int main() {
    std::cout << findMaxConsecutiveOnes({1, 1, 0, 1, 1, 1}) << " (expected 3)\n";
    return 0;
}
