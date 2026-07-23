// Contains Duplicate — LC 217
// True if any value appears twice; unordered_set for O(1) avg membership.
#include <iostream>
#include <vector>
#include <unordered_set>

bool containsDuplicate(const std::vector<int>& nums) {
    std::unordered_set<int> seen;
    for (int x : nums) {
        if (!seen.insert(x).second) return true; // already present
    }
    return false;
}

int main() {
    std::cout << std::boolalpha
              << containsDuplicate({1, 2, 3, 1}) << " (expected true)\n"
              << containsDuplicate({1, 2, 3, 4}) << " (expected false)\n";
    return 0;
}
