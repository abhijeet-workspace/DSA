// Diameter of Binary Tree — https://leetcode.com/problems/diameter-of-binary-tree/
// Longest path length in edges between any two nodes.
#include <iostream>
#include <algorithm>

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    explicit TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

int maxDia = 0;

// Returns height; updates maxDia with path through this node (edges).
int height(TreeNode* node) {
    if (!node) {
        return 0;
    }
    const int lh = height(node->left);
    const int rh = height(node->right);
    maxDia = std::max(maxDia, lh + rh); // path via node
    return 1 + std::max(lh, rh);
}

int diameterOfBinaryTree(TreeNode* root) {
    maxDia = 0;
    height(root);
    return maxDia;
}

int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    std::cout << "Diameter: " << diameterOfBinaryTree(root)
              << " (expected 3)\n";

    delete root->left->left;
    delete root->left->right;
    delete root->left;
    delete root->right;
    delete root;
    return 0;
}
