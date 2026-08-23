// Successful Pairs of Spells and Potions — https://leetcode.com/problems/successful-pairs-of-spells-and-potions/
// Count potions with spell*potion >= success; sort potions and lower-bound per spell.
#include <algorithm>
#include <iostream>
#include <vector>

std::vector<int> successfulPairs(const std::vector<int>& spells, std::vector<int> potions,
                                 long long success) {
    std::sort(potions.begin(), potions.end());
    const int m = static_cast<int>(potions.size());
    std::vector<int> ans;
    ans.reserve(spells.size());
    for (int s : spells) {
        const long long need = (success + s - 1) / s; // ceil(success / s)
        int lo = 0;
        int hi = m;
        while (lo < hi) {
            const int mid = lo + (hi - lo) / 2;
            if (potions[static_cast<size_t>(mid)] >= need) {
                hi = mid;
            } else {
                lo = mid + 1;
            }
        }
        ans.push_back(m - lo);
    }
    return ans;
}

int main() {
    const auto a = successfulPairs({5, 1, 3}, {1, 2, 3, 4, 5}, 7);
    std::cout << a[0] << " " << a[1] << " " << a[2] << " (expected 4 0 3)\n";
    return 0;
}
