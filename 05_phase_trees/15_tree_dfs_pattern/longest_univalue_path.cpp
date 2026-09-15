// Longest Univalue Path — https://leetcode.com/problems/longest-univalue-path/
#include <algorithm>
#include <iostream>

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    explicit TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

int bestEdges = 0;

int dfs(TreeNode* n) {
    if (!n) {
        return 0;
    }
    const int L = dfs(n->left);
    const int R = dfs(n->right);
    int left = 0, right = 0;
    if (n->left && n->left->val == n->val) {
        left = L + 1;
    }
    if (n->right && n->right->val == n->val) {
        right = R + 1;
    }
    bestEdges = std::max(bestEdges, left + right);
    return std::max(left, right);
}

int longestUnivaluePath(TreeNode* root) {
    bestEdges = 0;
    dfs(root);
    return bestEdges;
}

int main() {
    TreeNode* root = new TreeNode(5);
    root->left = new TreeNode(4);
    root->right = new TreeNode(5);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(1);
    root->right->right = new TreeNode(5);
    std::cout << longestUnivaluePath(root) << " (expected 2)\n";
    return 0;
}
