// Random Pick with Weight — https://leetcode.com/problems/random-pick-with-weight/
// Prefix sums of weights; pick a uniform r in [1, total] and upper_bound the prefix.
#include <cstdlib>
#include <iostream>
#include <numeric>
#include <vector>

class Solution {
    std::vector<int> prefix;

  public:
    explicit Solution(const std::vector<int>& w) : prefix(w) {
        std::partial_sum(prefix.begin(), prefix.end(), prefix.begin());
    }

    int pickIndex() const {
        const int total = prefix.back();
        const int r = 1 + (std::rand() % total); // 1..total inclusive
        int lo = 0;
        int hi = static_cast<int>(prefix.size()) - 1;
        while (lo < hi) {
            const int mid = lo + (hi - lo) / 2;
            if (prefix[static_cast<size_t>(mid)] >= r) {
                hi = mid;
            } else {
                lo = mid + 1;
            }
        }
        return lo;
    }
};

int main() {
    std::srand(1);
    Solution s({1, 3});
    int c0 = 0;
    int c1 = 0;
    for (int i = 0; i < 4000; ++i) {
        if (s.pickIndex() == 0) {
            ++c0;
        } else {
            ++c1;
        }
    }
    std::cout << "picks idx0=" << c0 << " idx1=" << c1 << " (expect idx1 ~ 3x idx0)\n";
    return 0;
}
