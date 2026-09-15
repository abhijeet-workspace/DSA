// Nested List Weight Sum II — https://leetcode.com/problems/nested-list-weight-sum-ii/
// Weight = maxDepth - depth + 1 (leaves deepest get weight 1). Two-pass or cumulative BFS trick.
#include <algorithm>
#include <iostream>
#include <vector>

class NestedInteger {
    bool is_int_;
    int val_ = 0;
    std::vector<NestedInteger> list_;

public:
    explicit NestedInteger(int v) : is_int_(true), val_(v) {}
    explicit NestedInteger(std::vector<NestedInteger> list) : is_int_(false), list_(std::move(list)) {}
    bool isInteger() const { return is_int_; }
    int getInteger() const { return val_; }
    const std::vector<NestedInteger>& getList() const { return list_; }
};

int maxDepth(const std::vector<NestedInteger>& nested) {
    int d = 1;
    for (const auto& ni : nested) {
        if (!ni.isInteger()) {
            d = std::max(d, 1 + maxDepth(ni.getList()));
        }
    }
    return d;
}

int dfs(const std::vector<NestedInteger>& nested, int depth, int maxD) {
    int sum = 0;
    for (const auto& ni : nested) {
        if (ni.isInteger()) {
            sum += ni.getInteger() * (maxD - depth + 1);
        } else {
            sum += dfs(ni.getList(), depth + 1, maxD);
        }
    }
    return sum;
}

int depthSumInverse(const std::vector<NestedInteger>& nestedList) {
    const int md = maxDepth(nestedList);
    return dfs(nestedList, 1, md);
}

int main() {
    // [[1,1],2,[1,1]] maxDepth=2 → 8
    std::vector<NestedInteger> a = {
        NestedInteger({NestedInteger(1), NestedInteger(1)}),
        NestedInteger(2),
        NestedInteger({NestedInteger(1), NestedInteger(1)})};
    std::cout << depthSumInverse(a) << " (expected 8)\n";
    // [1,[4,[6]]] → 17
    std::vector<NestedInteger> b = {
        NestedInteger(1),
        NestedInteger({NestedInteger(4), NestedInteger({NestedInteger(6)})})};
    std::cout << depthSumInverse(b) << " (expected 17)\n";
    return 0;
}
