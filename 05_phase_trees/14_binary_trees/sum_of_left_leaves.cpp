// Sum of Left Leaves — https://leetcode.com/problems/sum-of-left-leaves/
// Return the sum of all left leaves in the tree.
#include <iostream>

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    explicit TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

bool isLeaf(TreeNode* n) {
    return n && !n->left && !n->right;
}

int sumOfLeftLeaves(TreeNode* root) {
    if (!root) {
        return 0;
    }
    int sum = 0;
    if (isLeaf(root->left)) {
        sum += root->left->val;
    } else {
        sum += sumOfLeftLeaves(root->left);
    }
    sum += sumOfLeftLeaves(root->right);
    return sum;
}

int main() {
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);
    std::cout << sumOfLeftLeaves(root) << " (expected 24)\n";
    return 0;
}
