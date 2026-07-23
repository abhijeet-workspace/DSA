// Balanced Binary Tree — https://leetcode.com/problems/balanced-binary-tree/
// Return true if height difference of every node's subtrees is at most 1.
#include <iostream>
#include <algorithm>
#include <cmath>

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    explicit TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// Returns height, or -1 if subtree is unbalanced.
int height(TreeNode* n) {
    if (!n) {
        return 0;
    }
    const int L = height(n->left);
    if (L < 0) {
        return -1; // left unbalanced
    }
    const int R = height(n->right);
    if (R < 0) {
        return -1; // right unbalanced
    }
    if (std::abs(L - R) > 1) {
        return -1; // local imbalance
    }
    return 1 + std::max(L, R);
}

bool isBalanced(TreeNode* root) {
    return height(root) >= 0;
}

int main() {
    TreeNode* r = new TreeNode(1);
    r->left = new TreeNode(2);
    r->left->left = new TreeNode(3);
    std::cout << std::boolalpha << isBalanced(r) << " (expected false)\n";
    delete r->left->left;
    delete r->left;
    delete r;
    return 0;
}
