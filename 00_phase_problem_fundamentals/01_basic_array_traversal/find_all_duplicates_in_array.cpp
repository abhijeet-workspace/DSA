// Find All Duplicates in an Array — LC 442
// nums[i] in [1,n]; mark seen by negating nums[value-1]; second hit → duplicate.
#include <iostream>
#include <vector>
#include <cmath>

std::vector<int> findDuplicates(std::vector<int>& nums) {
    std::vector<int> ans;
    for (int x : nums) {
        const int v = std::abs(x);
        const size_t idx = static_cast<size_t>(v - 1);
        if (nums[idx] < 0) ans.push_back(v);
        else nums[idx] = -nums[idx];
    }
    return ans;
}

int main() {
    std::vector<int> a{4, 3, 2, 7, 8, 2, 3, 1};
    for (int x : findDuplicates(a)) std::cout << x << " ";
    std::cout << "(expected 2 3)\n";
    return 0;
}
