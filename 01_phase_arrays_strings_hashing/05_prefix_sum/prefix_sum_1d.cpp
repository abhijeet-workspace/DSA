// 1D Prefix Sum — https://leetcode.com/problems/range-sum-query-immutable/
// Preprocess array so sum(arr[l..r]) answers in O(1).
#include <iostream>
#include <vector>

class PrefixSum1D {
    std::vector<int> prefix; // prefix[i] = sum(arr[0..i-1]); prefix[0]=0
public:
    explicit PrefixSum1D(const std::vector<int>& arr) : prefix(arr.size() + 1, 0) {
        for (int i = 0; i < static_cast<int>(arr.size()); ++i) {
            prefix[i + 1] = prefix[i] + arr[i]; // cumulative sum
        }
    }
    int query(int l, int r) const {
        return prefix[r + 1] - prefix[l]; // sum[l..r] via telescoping
    }
};

int main() {
    PrefixSum1D ps({3, 1, 4, 1, 5, 9, 2, 6});
    std::cout << ps.query(0, 3) << " (expected 9)\n";
    std::cout << ps.query(2, 6) << " (expected 21)\n";
    return 0;
}
