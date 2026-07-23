// Binary Tree Maximum Path Sum — https://leetcode.com/problems/binary-tree-maximum-path-sum/
// Max sum of any non-empty node-to-node path (edges downward).
#include <iostream>
#include <algorithm>
#include <climits>

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    explicit TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

int dfs(TreeNode* root, int& best) {
    if (!root) {
        return 0; // null contributes no gain
    }
    const int leftGain = std::max(0, dfs(root->left, best)); // clamp negative
    const int rightGain = std::max(0, dfs(root->right, best));
    best = std::max(best, root->val + leftGain + rightGain); // path through root
    return root->val + std::max(leftGain, rightGain); // one child upward
}

int maxPathSum(TreeNode* root) {
    int best = INT_MIN;
    dfs(root, best);
    return best;
}

int main() {
    TreeNode* root = new TreeNode(-10);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);
    std::cout << maxPathSum(root) << " (expected 42)\n";
    delete root->right->left;
    delete root->right->right;
    delete root->right;
    delete root->left;
    delete root;
    return 0;
}
