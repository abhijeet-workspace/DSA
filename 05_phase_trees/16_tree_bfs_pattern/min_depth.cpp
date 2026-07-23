// Minimum Depth of Binary Tree — https://leetcode.com/problems/minimum-depth-of-binary-tree/
// Shortest root-to-leaf path length (node count).
#include <iostream>
#include <queue>
#include <utility>

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    explicit TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

int minDepth(TreeNode* root) {
    if (!root) {
        return 0;
    }
    std::queue<std::pair<TreeNode*, int>> q; // {node, depth}
    q.push({root, 1});
    while (!q.empty()) {
        auto [curr, depth] = q.front();
        q.pop();
        if (!curr->left && !curr->right) { // first leaf = min depth
            return depth;
        }
        if (curr->left) {
            q.push({curr->left, depth + 1});
        }
        if (curr->right) {
            q.push({curr->right, depth + 1});
        }
    }
    return 0;
}

int main() {
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);
    std::cout << minDepth(root) << " (expected 2)\n";
    return 0;
}
