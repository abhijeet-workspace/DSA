// Increasing Order Search Tree — https://leetcode.com/problems/increasing-order-search-tree/
#include <iostream>

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    explicit TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

void inorder(TreeNode* n, TreeNode*& tail) {
    if (!n) return;
    inorder(n->left, tail);
    n->left = nullptr;
    tail->right = n;
    tail = n;
    inorder(n->right, tail);
}

TreeNode* increasingBST(TreeNode* root) {
    TreeNode dummy(0);
    TreeNode* tail = &dummy;
    inorder(root, tail);
    return dummy.right;
}

int main() {
    TreeNode* root = new TreeNode(5);
    root->left = new TreeNode(3);
    root->right = new TreeNode(6);
    root->left->left = new TreeNode(2);
    root->left->right = new TreeNode(4);
    root->right->right = new TreeNode(8);
    TreeNode* head = increasingBST(root);
    while (head) {
        std::cout << head->val << (head->right ? "->" : "\n");
        head = head->right;
    }
    return 0;
}
