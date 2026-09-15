// House Robber III — https://leetcode.com/problems/house-robber-iii/
// Max money without robbing two adjacent tree nodes.
#include <algorithm>
#include <iostream>
#include <utility>

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    explicit TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// Returns {rob_this, skip_this}.
std::pair<int, int> dfs(TreeNode* n) {
    if (!n) {
        return {0, 0};
    }
    auto L = dfs(n->left);
    auto R = dfs(n->right);
    const int rob = n->val + L.second + R.second;
    const int skip = std::max(L.first, L.second) + std::max(R.first, R.second);
    return {rob, skip};
}

int rob(TreeNode* root) {
    auto p = dfs(root);
    return std::max(p.first, p.second);
}

int main() {
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->right = new TreeNode(3);
    root->right->right = new TreeNode(1);
    std::cout << rob(root) << " (expected 7)\n";
    return 0;
}
