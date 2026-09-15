// Concatenation of Array — LC 1929
// ans = nums followed by nums again (length 2n).
#include <iostream>
#include <vector>

std::vector<int> getConcatenation(const std::vector<int>& nums) {
    const int n = static_cast<int>(nums.size());
    std::vector<int> ans(static_cast<size_t>(2 * n));
    for (int i = 0; i < n; ++i) {
        ans[static_cast<size_t>(i)] = nums[static_cast<size_t>(i)];
        ans[static_cast<size_t>(i + n)] = nums[static_cast<size_t>(i)];
    }
    return ans;
}

int main() {
    for (int x : getConcatenation({1, 2, 1}))
        std::cout << x << " ";
    std::cout << "(expected 1 2 1 1 2 1)\n";
    return 0;
}
