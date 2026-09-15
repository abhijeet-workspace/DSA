// Distribute Coins in Binary Tree — https://leetcode.com/problems/distribute-coins-in-binary-tree/
#include <iostream>
#include <cstdlib>

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    explicit TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

int moves = 0;

int dfs(TreeNode* n) {
    if (!n) {
        return 0;
    }
    const int L = dfs(n->left);
    const int R = dfs(n->right);
    moves += std::abs(L) + std::abs(R);
    return n->val + L + R - 1; // excess to parent
}

int distributeCoins(TreeNode* root) {
    moves = 0;
    dfs(root);
    return moves;
}

int main() {
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(0);
    root->right = new TreeNode(0);
    std::cout << distributeCoins(root) << " (expected 2)\n";
    return 0;
}
