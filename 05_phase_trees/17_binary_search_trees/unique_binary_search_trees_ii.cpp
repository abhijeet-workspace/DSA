// Unique Binary Search Trees II — https://leetcode.com/problems/unique-binary-search-trees-ii/
#include <iostream>
#include <vector>

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    explicit TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

std::vector<TreeNode*> build(int lo, int hi) {
    if (lo > hi)
        return {nullptr};
    std::vector<TreeNode*> ans;
    for (int mid = lo; mid <= hi; ++mid) {
        auto L = build(lo, mid - 1);
        auto R = build(mid + 1, hi);
        for (TreeNode* l : L) {
            for (TreeNode* r : R) {
                TreeNode* root = new TreeNode(mid);
                root->left = l;
                root->right = r;
                ans.push_back(root);
            }
        }
    }
    return ans;
}

std::vector<TreeNode*> generateTrees(int n) {
    if (n == 0)
        return {};
    return build(1, n);
}

int main() {
    auto trees = generateTrees(3);
    std::cout << trees.size() << " (expected 5)\n";
    return 0;
}
