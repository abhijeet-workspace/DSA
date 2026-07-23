// Maximum Depth of Binary Tree — https://leetcode.com/problems/maximum-depth-of-binary-tree/
// Depth = nodes on longest root-to-leaf path; empty tree depth 0.
#include <iostream>
#include <algorithm>

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    explicit TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

int maxDepth(TreeNode* root) {
    if (!root) {
        return 0;
    }
    return 1 + std::max(maxDepth(root->left), maxDepth(root->right));
}

int main() {
    TreeNode* r = new TreeNode(3);
    r->left = new TreeNode(9);
    r->right = new TreeNode(20);
    r->right->left = new TreeNode(15);
    r->right->right = new TreeNode(7);
    std::cout << maxDepth(r) << " (expected 3)\n";
    delete r->right->left;
    delete r->right->right;
    delete r->right;
    delete r->left;
    delete r;
    return 0;
}
