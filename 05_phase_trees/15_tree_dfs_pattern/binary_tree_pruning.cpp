// Binary Tree Pruning — https://leetcode.com/problems/binary-tree-pruning/
#include <iostream>

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    explicit TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

TreeNode* pruneTree(TreeNode* root) {
    if (!root) {
        return nullptr;
    }
    root->left = pruneTree(root->left);
    root->right = pruneTree(root->right);
    if (root->val == 0 && !root->left && !root->right) {
        return nullptr;
    }
    return root;
}

int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(0);
    root->right = new TreeNode(1);
    root->left->left = new TreeNode(0);
    root->left->right = new TreeNode(0);
    root->right->left = new TreeNode(0);
    root->right->right = new TreeNode(1);
    root = pruneTree(root);
    std::cout << (root && root->val == 1 && !root->left && root->right
                  && root->right->right && root->right->right->val == 1
                  ? "ok" : "bad") << "\n";
    return 0;
}
