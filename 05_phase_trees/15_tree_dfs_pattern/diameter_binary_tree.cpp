// Diameter of Binary Tree — https://leetcode.com/problems/diameter-of-binary-tree/
// Longest path length (edge count) between any two nodes.
#include <iostream>
#include <algorithm>

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    explicit TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

int heightAndDiameter(TreeNode* root, int& diameter) {
    if (!root) {
        return 0; // null height
    }
    const int leftH = heightAndDiameter(root->left, diameter);
    const int rightH = heightAndDiameter(root->right, diameter);
    diameter = std::max(diameter, leftH + rightH); // path through root
    return 1 + std::max(leftH, rightH); // height in nodes
}

int diameterOfBinaryTree(TreeNode* root) {
    int diameter = 0;
    heightAndDiameter(root, diameter);
    return diameter;
}

int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    std::cout << diameterOfBinaryTree(root)
              << " (expected 3)\n";
    delete root->left->left;
    delete root->left->right;
    delete root->left;
    delete root->right;
    delete root;
    return 0;
}
