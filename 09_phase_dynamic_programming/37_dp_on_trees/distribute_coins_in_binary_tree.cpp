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

int moves = 0;
int dfs(TreeNode* node) {
    if (!node) return 0;
    int L = dfs(node->left), R = dfs(node->right);
    moves += std::abs(L) + std::abs(R);
    return node->val - 1 + L + R;
}

int distributeCoins(TreeNode* root) {
    moves = 0;
    dfs(root);
    return moves;
}

int main() {
    TreeNode a(3), b(0), c(0);
    a.left = &b; a.right = &c;
    std::cout << distributeCoins(&a) << " (expected 2)\n";
    return 0;
}
