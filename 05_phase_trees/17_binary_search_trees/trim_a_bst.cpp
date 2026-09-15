// Trim a Binary Search Tree — https://leetcode.com/problems/trim-a-binary-search-tree/
#include <iostream>

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    explicit TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

TreeNode* trimBST(TreeNode* root, int low, int high) {
    if (!root) return nullptr;
    if (root->val < low) return trimBST(root->right, low, high);
    if (root->val > high) return trimBST(root->left, low, high);
    root->left = trimBST(root->left, low, high);
    root->right = trimBST(root->right, low, high);
    return root;
}

int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(0);
    root->right = new TreeNode(2);
    root = trimBST(root, 1, 2);
    std::cout << root->val << " (expected 1)\n";
    std::cout << (root->left == nullptr && root->right && root->right->val == 2 ? "ok" : "bad") << "\n";
    return 0;
}
