// Search in a Binary Search Tree — https://leetcode.com/problems/search-in-a-binary-search-tree/
#include <iostream>

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    explicit TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

TreeNode* searchBST(TreeNode* root, int val) {
    while (root && root->val != val) {
        root = (val < root->val) ? root->left : root->right;
    }
    return root;
}

int main() {
    TreeNode* root = new TreeNode(4);
    root->left = new TreeNode(2);
    root->right = new TreeNode(7);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(3);
    TreeNode* found = searchBST(root, 2);
    std::cout << (found ? found->val : -1) << " (expected 2)\n";
    std::cout << (searchBST(root, 5) == nullptr ? "null ok" : "bad") << "\n";
    return 0;
}
