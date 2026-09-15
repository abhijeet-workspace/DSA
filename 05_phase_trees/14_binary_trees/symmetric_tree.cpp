// Symmetric Tree — https://leetcode.com/problems/symmetric-tree/
// True iff left and right subtrees are mirror images.
#include <iostream>

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    explicit TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

bool isMirror(TreeNode* a, TreeNode* b) {
    if (!a || !b) {
        return a == b;
    }
    return a->val == b->val && isMirror(a->left, b->right)
        && isMirror(a->right, b->left);
}

bool isSymmetric(TreeNode* root) {
    return !root || isMirror(root->left, root->right);
}

int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(2);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(4);
    root->right->left = new TreeNode(4);
    root->right->right = new TreeNode(3);
    std::cout << std::boolalpha << isSymmetric(root) << " (expected true)\n";
    root->right->right->val = 5;
    std::cout << isSymmetric(root) << " (expected false)\n";
    return 0;
}
