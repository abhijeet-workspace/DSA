// Maximum Binary Tree — https://leetcode.com/problems/maximum-binary-tree/
#include <iostream>
#include <vector>

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    explicit TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

TreeNode* build(const std::vector<int>& a, int lo, int hi) {
    if (lo >= hi) {
        return nullptr;
    }
    int mid = lo;
    for (int i = lo + 1; i < hi; ++i) {
        if (a[i] > a[mid]) {
            mid = i;
        }
    }
    TreeNode* n = new TreeNode(a[mid]);
    n->left = build(a, lo, mid);
    n->right = build(a, mid + 1, hi);
    return n;
}

TreeNode* constructMaximumBinaryTree(std::vector<int>& nums) {
    return build(nums, 0, static_cast<int>(nums.size()));
}

int main() {
    std::vector<int> nums{3, 2, 1, 6, 0, 5};
    TreeNode* root = constructMaximumBinaryTree(nums);
    std::cout << root->val << " (expected 6)\n";
    std::cout << root->left->val << " (expected 3)\n";
    std::cout << root->right->val << " (expected 5)\n";
    return 0;
}
