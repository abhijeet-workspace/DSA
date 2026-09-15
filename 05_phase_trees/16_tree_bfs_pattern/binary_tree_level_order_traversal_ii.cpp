// Binary Tree Level Order Traversal II —
// https://leetcode.com/problems/binary-tree-level-order-traversal-ii/
#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    explicit TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

std::vector<std::vector<int>> levelOrderBottom(TreeNode* root) {
    std::vector<std::vector<int>> ans;
    if (!root)
        return ans;
    std::queue<TreeNode*> q;
    q.push(root);
    while (!q.empty()) {
        const int sz = static_cast<int>(q.size());
        std::vector<int> level;
        for (int i = 0; i < sz; ++i) {
            TreeNode* u = q.front();
            q.pop();
            level.push_back(u->val);
            if (u->left)
                q.push(u->left);
            if (u->right)
                q.push(u->right);
        }
        ans.push_back(std::move(level));
    }
    std::reverse(ans.begin(), ans.end());
    return ans;
}

int main() {
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);
    auto a = levelOrderBottom(root);
    std::cout << a[0][0] << "," << a[0][1] << " (expected 15,7)\n";
    return 0;
}
