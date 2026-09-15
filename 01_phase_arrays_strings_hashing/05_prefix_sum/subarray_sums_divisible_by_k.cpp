// Subarray Sums Divisible by K — LC 974
// Count pairs of prefixes with equal remainder mod k (handle negative mods).
#include <iostream>
#include <vector>
#include <unordered_map>

int subarraysDivByK(const std::vector<int>& nums, int k) {
    std::unordered_map<int, int> freq; // remainder → count
    freq[0] = 1;
    int sum = 0;
    int ans = 0;
    for (int x : nums) {
        sum += x;
        int rem = sum % k;
        if (rem < 0) rem += k; // normalize negative remainders
        ans += freq[rem];
        ++freq[rem];
    }
    return ans;
}

int main() {
    std::cout << subarraysDivByK({4, 5, 0, -2, -3, 1}, 5) << " (expected 7)\n";
    std::cout << subarraysDivByK({5}, 9) << " (expected 0)\n";
    return 0;
}
