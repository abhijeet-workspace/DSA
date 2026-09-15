// Dot Product of Two Sparse Vectors — https://leetcode.com/problems/dot-product-of-two-sparse-vectors/
// Store only non-zero pairs; dot by intersecting indices.
#include <iostream>
#include <unordered_map>
#include <utility>
#include <vector>

class SparseVector {
public:
    std::vector<std::pair<int, int>> nz; // (index, value)

    explicit SparseVector(const std::vector<int>& nums) {
        for (int i = 0; i < static_cast<int>(nums.size()); ++i) {
            if (nums[static_cast<size_t>(i)] != 0) {
                nz.emplace_back(i, nums[static_cast<size_t>(i)]);
            }
        }
    }

    int dotProduct(const SparseVector& other) const {
        int i = 0, j = 0, ans = 0;
        while (i < static_cast<int>(nz.size()) && j < static_cast<int>(other.nz.size())) {
            if (nz[static_cast<size_t>(i)].first == other.nz[static_cast<size_t>(j)].first) {
                ans += nz[static_cast<size_t>(i)].second * other.nz[static_cast<size_t>(j)].second;
                ++i;
                ++j;
            } else if (nz[static_cast<size_t>(i)].first < other.nz[static_cast<size_t>(j)].first) {
                ++i;
            } else {
                ++j;
            }
        }
        return ans;
    }
};

int main() {
    SparseVector v1({1, 0, 0, 2, 3});
    SparseVector v2({0, 3, 0, 4, 0});
    std::cout << v1.dotProduct(v2) << " (expected 8)\n";
    SparseVector v3({0, 1, 0, 0, 0});
    SparseVector v4({0, 0, 0, 0, 2});
    std::cout << v3.dotProduct(v4) << " (expected 0)\n";
    return 0;
}
