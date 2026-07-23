// Kth Smallest in BST — https://leetcode.com/problems/kth-smallest-element-in-a-bst/
// Return k-th smallest (1-indexed) via early-stop inorder.
#include <iostream>

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    explicit TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

void inorder(TreeNode* root, int k, int& count, int& result) {
    if (!root || count >= k) {
        return; // prune once found
    }
    inorder(root->left, k, count, result);
    ++count;
    if (count == k) {
        result = root->val;
        return;
    }
    inorder(root->right, k, count, result);
}

int kthSmallest(TreeNode* root, int k) {
    int count = 0;
    int result = -1;
    inorder(root, k, count, result);
    return result;
}

int main() {
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(1);
    root->right = new TreeNode(4);
    root->left->right = new TreeNode(2);
    std::cout << kthSmallest(root, 1) << " (expected 1)\n"
              << kthSmallest(root, 3) << " (expected 3)\n";
    return 0;
}
