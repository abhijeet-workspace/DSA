// Find Bottom Left Tree Value — https://leetcode.com/problems/find-bottom-left-tree-value/
#include <iostream>
#include <queue>

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    explicit TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

int findBottomLeftValue(TreeNode* root) {
    std::queue<TreeNode*> q;
    q.push(root);
    int ans = root->val;
    while (!q.empty()) {
        const int sz = static_cast<int>(q.size());
        for (int i = 0; i < sz; ++i) {
            TreeNode* u = q.front();
            q.pop();
            if (i == 0)
                ans = u->val; // leftmost of this level
            if (u->left)
                q.push(u->left);
            if (u->right)
                q.push(u->right);
        }
    }
    return ans;
}

int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->right->left = new TreeNode(5);
    root->right->right = new TreeNode(6);
    root->right->left->left = new TreeNode(7);
    std::cout << findBottomLeftValue(root) << " (expected 7)\n";
    return 0;
}
