// Majority Element — https://leetcode.com/problems/majority-element/
// Element appearing > floor(n/2) times; guaranteed to exist (Boyer-Moore vote).
#include <iostream>
#include <vector>

int majorityElement(const std::vector<int>& nums) {
    int candidate = 0;
    int count = 0;
    for (int x : nums) {
        if (count == 0) {
            candidate = x; // new vote leader
        }
        count += (x == candidate) ? 1 : -1; // match boosts; mismatch cancels
    }
    return candidate; // majority always survives cancellation
}

int main() {
    std::cout << majorityElement({3, 2, 3}) << " (expected 3)\n"
              << majorityElement({2, 2, 1, 1, 1, 2, 2}) << " (expected 2)\n";
    return 0;
}
