#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

#include <utility>

std::pair<int, int> dfs(TreeNode* node) {
    if (!node)
        return {0, 0};
    auto L = dfs(node->left), R = dfs(node->right);
    const int rob = node->val + L.second + R.second;
    const int skip = std::max(L.first, L.second) + std::max(R.first, R.second);
    return {rob, skip};
}

int rob(TreeNode* root) {
    auto p = dfs(root);
    return std::max(p.first, p.second);
}

int main() {
    TreeNode a(3), b(2), c(3), d(3), e(1);
    a.left = &b;
    a.right = &c;
    b.right = &d;
    c.right = &e;
    std::cout << rob(&a) << " (expected 7)\n";
    return 0;
}
