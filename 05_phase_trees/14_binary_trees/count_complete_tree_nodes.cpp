// Count Complete Tree Nodes — https://leetcode.com/problems/count-complete-tree-nodes/
// Count nodes in a complete binary tree in better than O(N) when possible.
#include <iostream>

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    explicit TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

int heightLeft(TreeNode* n) {
    int h = 0;
    while (n) {
        ++h;
        n = n->left;
    }
    return h;
}

int heightRight(TreeNode* n) {
    int h = 0;
    while (n) {
        ++h;
        n = n->right;
    }
    return h;
}

int countNodes(TreeNode* root) {
    if (!root) {
        return 0;
    }
    const int lh = heightLeft(root);
    const int rh = heightRight(root);
    if (lh == rh) {
        return (1 << lh) - 1; // perfect subtree
    }
    return 1 + countNodes(root->left) + countNodes(root->right);
}

int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    std::cout << countNodes(root) << " (expected 6)\n";
    return 0;
}
