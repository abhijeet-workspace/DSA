// Sum Root to Leaf Numbers — https://leetcode.com/problems/sum-root-to-leaf-numbers/
// Each root-to-leaf path forms a decimal number; return the sum of all such numbers.
#include <iostream>

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    explicit TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

int dfs(TreeNode* node, int cur) {
    if (!node) {
        return 0;
    }
    cur = cur * 10 + node->val;
    if (!node->left && !node->right) {
        return cur; // leaf number
    }
    return dfs(node->left, cur) + dfs(node->right, cur);
}

int sumNumbers(TreeNode* root) {
    return dfs(root, 0);
}

int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    std::cout << sumNumbers(root) << " (expected 25)\n";
    return 0;
}
