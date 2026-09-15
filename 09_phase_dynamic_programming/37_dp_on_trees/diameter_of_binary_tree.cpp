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
int height(TreeNode* node) {
    if (!node)
        return 0;
    int L = height(node->left), R = height(node->right);
    ans = std::max(ans, L + R);
    return 1 + std::max(L, R);
}

int diameterOfBinaryTree(TreeNode* root) {
    ans = 0;
    height(root);
    return ans;
}

int main() {
    TreeNode a(1), b(2), c(3), d(4), e(5);
    a.left = &b;
    a.right = &c;
    b.left = &d;
    b.right = &e;
    std::cout << diameterOfBinaryTree(&a) << " (expected 3)\n";
    return 0;
}
