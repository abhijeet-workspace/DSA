// Rotate Array — LC 189
// Rotate right by k using reverse: rev all, rev [0,k), rev [k,n).
#include <iostream>
#include <vector>
#include <algorithm>

void rotate(std::vector<int>& nums, int k) {
    const int n = static_cast<int>(nums.size());
    if (n == 0) return;
    k %= n;
    std::reverse(nums.begin(), nums.end());
    std::reverse(nums.begin(), nums.begin() + k);
    std::reverse(nums.begin() + k, nums.end());
}

int main() {
    std::vector<int> a{1, 2, 3, 4, 5, 6, 7};
    rotate(a, 3);
    for (int x : a) std::cout << x << " ";
    std::cout << "(expected 5 6 7 1 2 3 4)\n";
    return 0;
}
