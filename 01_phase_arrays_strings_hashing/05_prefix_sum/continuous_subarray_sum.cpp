// Continuous Subarray Sum — LC 523
// Same prefix mod k at indices ≥ 2 apart ⇒ subarray length ≥ 2 divisible by k.
#include <iostream>
#include <unordered_map>
#include <vector>

bool checkSubarraySum(const std::vector<int>& nums, int k) {
    std::unordered_map<int, int> firstIndex; // remainder → earliest index
    firstIndex[0] = -1;
    int sum = 0;
    for (int i = 0; i < static_cast<int>(nums.size()); ++i) {
        sum += nums[static_cast<size_t>(i)];
        int rem = sum % k;
        if (rem < 0)
            rem += k; // normalize if negatives appear in variants
        auto it = firstIndex.find(rem);
        if (it != firstIndex.end()) {
            if (i - it->second >= 2)
                return true;
        } else {
            firstIndex[rem] = i;
        }
    }
    return false;
}

int main() {
    std::cout << std::boolalpha << checkSubarraySum({23, 2, 4, 6, 7}, 6) << " (expected true)\n"
              << checkSubarraySum({23, 2, 6, 4, 7}, 6) << " (expected true)\n"
              << checkSubarraySum({23, 2, 6, 4, 7}, 13) << " (expected false)\n"
              << checkSubarraySum({1, 0}, 2) << " (expected false)\n";
    return 0;
}
