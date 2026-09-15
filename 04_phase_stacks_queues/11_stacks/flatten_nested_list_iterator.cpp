// Flatten Nested List Iterator — https://leetcode.com/problems/flatten-nested-list-iterator/
// Iterator over nested integers; next/hasNext flatten nested lists lazily with a stack.
#include <iostream>
#include <stack>
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

class NestedIterator {
    std::stack<NestedInteger> st_;

    void skipToInteger() {
        while (!st_.empty() && !st_.top().isInteger()) {
            auto list = st_.top().getList();
            st_.pop();
            for (int i = static_cast<int>(list.size()) - 1; i >= 0; --i) {
                st_.push(list[static_cast<size_t>(i)]);
            }
        }
    }

  public:
    explicit NestedIterator(const std::vector<NestedInteger>& nestedList) {
        for (int i = static_cast<int>(nestedList.size()) - 1; i >= 0; --i) {
            st_.push(nestedList[static_cast<size_t>(i)]);
        }
        skipToInteger();
    }

    int next() {
        const int v = st_.top().getInteger();
        st_.pop();
        skipToInteger();
        return v;
    }

    bool hasNext() { return !st_.empty(); }
};

int main() {
    // [[1,1],2,[1,1]]
    std::vector<NestedInteger> nested = {NestedInteger({NestedInteger(1), NestedInteger(1)}),
                                         NestedInteger(2),
                                         NestedInteger({NestedInteger(1), NestedInteger(1)})};
    NestedIterator it(nested);
    std::vector<int> out;
    while (it.hasNext()) {
        out.push_back(it.next());
    }
    for (size_t i = 0; i < out.size(); ++i) {
        if (i)
            std::cout << ' ';
        std::cout << out[i];
    }
    std::cout << " (expected 1 1 2 1 1)\n";
    return 0;
}
