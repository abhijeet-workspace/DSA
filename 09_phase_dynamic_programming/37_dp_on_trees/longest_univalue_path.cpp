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

int ans = 0;
int dfs(TreeNode* node) {
    if (!node)
        return 0;
    int L = dfs(node->left), R = dfs(node->right);
    int left = 0, right = 0;
    if (node->left && node->left->val == node->val)
        left = L + 1;
    if (node->right && node->right->val == node->val)
        right = R + 1;
    ans = std::max(ans, left + right);
    return std::max(left, right);
}

int longestUnivaluePath(TreeNode* root) {
    ans = 0;
    dfs(root);
    return ans;
}

int main() {
    TreeNode a(5), b(4), c(5), d(1), e(1), f(5);
    a.left = &b;
    a.right = &c;
    b.left = &d;
    b.right = &e;
    c.right = &f;
    std::cout << longestUnivaluePath(&a) << " (expected 2)\n";
    return 0;
}
