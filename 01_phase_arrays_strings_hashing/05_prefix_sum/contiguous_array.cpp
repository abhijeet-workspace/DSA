// Contiguous Array — LC 525
// Map 0→-1; first index of each prefix sum; longest span with sum 0.
#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

int findMaxLength(const std::vector<int>& nums) {
    std::unordered_map<int, int> firstIndex; // prefix sum → earliest index
    firstIndex[0] = -1; // empty prefix before index 0
    int sum = 0;
    int best = 0;
    for (int i = 0; i < static_cast<int>(nums.size()); ++i) {
        sum += (nums[static_cast<size_t>(i)] == 0 ? -1 : 1);
        auto it = firstIndex.find(sum);
        if (it != firstIndex.end()) {
            best = std::max(best, i - it->second);
        } else {
            firstIndex[sum] = i;
        }
    }
    return best;
}

int main() {
    std::cout << findMaxLength({0, 1}) << " (expected 2)\n";
    std::cout << findMaxLength({0, 1, 0}) << " (expected 2)\n";
    std::cout << findMaxLength({0, 1, 0, 1}) << " (expected 4)\n";
    return 0;
}
