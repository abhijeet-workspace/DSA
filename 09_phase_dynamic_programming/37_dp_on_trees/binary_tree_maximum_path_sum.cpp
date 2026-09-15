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

#include <climits>
int best = INT_MIN;
int gain(TreeNode* node) {
    if (!node)
        return 0;
    int L = std::max(0, gain(node->left));
    int R = std::max(0, gain(node->right));
    best = std::max(best, node->val + L + R);
    return node->val + std::max(L, R);
}

int maxPathSum(TreeNode* root) {
    best = INT_MIN;
    gain(root);
    return best;
}

int main() {
    TreeNode a(-10), b(9), c(20), d(15), e(7);
    a.left = &b;
    a.right = &c;
    c.left = &d;
    c.right = &e;
    std::cout << maxPathSum(&a) << " (expected 42)\n";
    return 0;
}
