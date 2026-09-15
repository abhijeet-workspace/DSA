#include <algorithm>
#include <iostream>
#include <vector>

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

long long total = 0, best = 0;
long long sum(TreeNode* node) {
    if (!node)
        return 0;
    return node->val + sum(node->left) + sum(node->right);
}
long long dfs(TreeNode* node) {
    if (!node)
        return 0;
    long long s = node->val + dfs(node->left) + dfs(node->right);
    best = std::max(best, s * (total - s));
    return s;
}

int maxProduct(TreeNode* root) {
    total = sum(root);
    best = 0;
    dfs(root);
    return static_cast<int>(best % 1'000'000'007);
}

int main() {
    TreeNode a(1), b(2), c(3), d(4), e(5), f(6);
    a.left = &b;
    a.right = &c;
    b.left = &d;
    b.right = &e;
    c.left = &f;
    std::cout << maxProduct(&a) << " (expected 110)\n";
    return 0;
}
