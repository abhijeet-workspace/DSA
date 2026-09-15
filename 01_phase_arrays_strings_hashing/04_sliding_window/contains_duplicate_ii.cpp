// Contains Duplicate II — LC 219
// Sliding window of size at most k: keep last indices (or a set of values in window).
#include <iostream>
#include <vector>
#include <unordered_map>

bool containsNearbyDuplicate(const std::vector<int>& nums, int k) {
    std::unordered_map<int, int> last;
    for (int i = 0; i < static_cast<int>(nums.size()); ++i) {
        const int v = nums[static_cast<size_t>(i)];
        if (last.count(v) && i - last[v] <= k) return true;
        last[v] = i;
    }
    return false;
}

int main() {
    std::cout << std::boolalpha
              << containsNearbyDuplicate({1, 2, 3, 1}, 3)
              << " (expected true)\n"
              << containsNearbyDuplicate({1, 0, 1, 1}, 1)
              << " (expected true)\n"
              << containsNearbyDuplicate({1, 2, 3, 1, 2, 3}, 2)
              << " (expected false)\n";
    return 0;
}
