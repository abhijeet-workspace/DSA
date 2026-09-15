// Nested List Weight Sum — https://leetcode.com/problems/nested-list-weight-sum/
// Sum integers weighted by depth (root depth=1). DFS over NestedInteger.
#include <iostream>
#include <vector>

class NestedInteger {
    bool is_int_;
    int val_ = 0;
    std::vector<NestedInteger> list_;

  public:
    explicit NestedInteger(int v) : is_int_(true), val_(v) {}
    explicit NestedInteger(std::vector<NestedInteger> list)
        : is_int_(false), list_(std::move(list)) {}
    bool isInteger() const { return is_int_; }
    int getInteger() const { return val_; }
    const std::vector<NestedInteger>& getList() const { return list_; }
};

int dfs(const std::vector<NestedInteger>& nested, int depth) {
    int sum = 0;
    for (const auto& ni : nested) {
        if (ni.isInteger()) {
            sum += ni.getInteger() * depth;
        } else {
            sum += dfs(ni.getList(), depth + 1);
        }
    }
    return sum;
}

int depthSum(const std::vector<NestedInteger>& nestedList) {
    return dfs(nestedList, 1);
}

int main() {
    // [[1,1],2,[1,1]] → 10
    std::vector<NestedInteger> a = {NestedInteger({NestedInteger(1), NestedInteger(1)}),
                                    NestedInteger(2),
                                    NestedInteger({NestedInteger(1), NestedInteger(1)})};
    std::cout << depthSum(a) << " (expected 10)\n";
    // [1,[4,[6]]] → 27
    std::vector<NestedInteger> b = {
        NestedInteger(1), NestedInteger({NestedInteger(4), NestedInteger({NestedInteger(6)})})};
    std::cout << depthSum(b) << " (expected 27)\n";
    return 0;
}
