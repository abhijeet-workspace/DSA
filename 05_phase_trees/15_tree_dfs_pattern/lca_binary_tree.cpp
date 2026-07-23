// Lowest Common Ancestor of a Binary Tree — https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/
// Find LCA of nodes p and q in a general binary tree (not a BST).
#include <iostream>

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    explicit TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    if (!root || root == p || root == q) {
        return root; // hit null or a target
    }
    TreeNode* left = lowestCommonAncestor(root->left, p, q);
    TreeNode* right = lowestCommonAncestor(root->right, p, q);
    if (left && right) {
        return root; // targets in different subtrees
    }
    return left ? left : right; // bubble non-null side
}

int main() {
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(5);
    root->right = new TreeNode(1);
    root->left->left = new TreeNode(6);
    root->left->right = new TreeNode(2);
    TreeNode* p = root->left;
    TreeNode* q = root->left->right;
    std::cout << lowestCommonAncestor(root, p, q)->val << " (expected 5)\n";
    return 0;
}
