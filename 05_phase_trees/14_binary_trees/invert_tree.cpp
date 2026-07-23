// Invert Binary Tree — https://leetcode.com/problems/invert-binary-tree/
// Swap every left/right child throughout the tree; return root.
#include <iostream>

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    explicit TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

TreeNode* invertTree(TreeNode* root) {
    if (!root) {
        return nullptr;
    }
    TreeNode* left = invertTree(root->left);   // invert left
    TreeNode* right = invertTree(root->right); // invert right
    root->left = right;  // swap
    root->right = left;
    return root;
}

void printPreorder(TreeNode* node) {
    if (!node) {
        return;
    }
    std::cout << node->val << " ";
    printPreorder(node->left);
    printPreorder(node->right);
}

int main() {
    TreeNode* root = new TreeNode(4);
    root->left = new TreeNode(2);
    root->right = new TreeNode(7);
    invertTree(root);
    std::cout << "preorder: ";
    printPreorder(root);
    std::cout << "(expected 4 7 2 )\n";
    delete root->left;
    delete root->right;
    delete root;
    return 0;
}
