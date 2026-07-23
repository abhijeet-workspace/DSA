// Binary Tree Level Order Traversal — https://leetcode.com/problems/binary-tree-level-order-traversal/
// Return node values level by level, left to right.
#include <iostream>
#include <queue>
#include <vector>

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    explicit TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

std::vector<std::vector<int>> levelOrder(TreeNode* root) {
    std::vector<std::vector<int>> result;
    if (!root) {
        return result;
    }
    std::queue<TreeNode*> q;
    q.push(root);
    while (!q.empty()) {
        const int size = static_cast<int>(q.size()); // snapshot level width
        std::vector<int> level;
        level.reserve(static_cast<size_t>(size));
        for (int i = 0; i < size; ++i) {
            TreeNode* cur = q.front();
            q.pop();
            level.push_back(cur->val);
            if (cur->left) {
                q.push(cur->left);
            }
            if (cur->right) {
                q.push(cur->right);
            }
        }
        result.push_back(std::move(level));
    }
    return result;
}

int main() {
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);
    const auto levels = levelOrder(root);
    std::cout << "levels=" << levels.size() << " (expected 3)\n";
    for (const auto& lvl : levels) {
        std::cout << "[";
        for (size_t i = 0; i < lvl.size(); ++i) {
            std::cout << lvl[i] << (i + 1 < lvl.size() ? " " : "");
        }
        std::cout << "]\n";
    }
    return 0;
}
