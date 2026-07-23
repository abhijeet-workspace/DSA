// Path Sum — https://leetcode.com/problems/path-sum/
// True if any root-to-leaf path sums to targetSum.
#include <iostream>

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    explicit TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

bool hasPathSum(TreeNode* root, int targetSum) {
    if (!root) {
        return false; // empty path invalid
    }
    if (!root->left && !root->right) {
        return targetSum == root->val; // leaf must match remainder
    }
    const int need = targetSum - root->val; // reduce target
    return hasPathSum(root->left, need) || hasPathSum(root->right, need);
}

int main() {
    TreeNode* root = new TreeNode(5);
    root->left = new TreeNode(4);
    root->right = new TreeNode(8);
    root->left->left = new TreeNode(11);
    std::cout << std::boolalpha
              << hasPathSum(root, 20) << " (expected true)\n"
              << hasPathSum(root, 10) << " (expected false)\n";
    delete root->left->left;
    delete root->left;
    delete root->right;
    delete root;
    return 0;
}
