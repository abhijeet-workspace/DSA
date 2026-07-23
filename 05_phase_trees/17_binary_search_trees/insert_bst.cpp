// Insert into BST — https://leetcode.com/problems/insert-into-a-binary-search-tree/
// Insert val into BST; return root. Recurse to null leaf slot.
#include <iostream>

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    explicit TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

TreeNode* insertIntoBST(TreeNode* root, int val) {
    if (!root) {
        return new TreeNode(val); // empty slot
    }
    if (val < root->val) {
        root->left = insertIntoBST(root->left, val);
    } else {
        root->right = insertIntoBST(root->right, val); // val >= root
    }
    return root;
}

void printInOrder(TreeNode* root) {
    if (!root) {
        return;
    }
    printInOrder(root->left);
    std::cout << root->val << " ";
    printInOrder(root->right);
}

int main() {
    TreeNode* root = new TreeNode(4);
    root->left = new TreeNode(2);
    root->right = new TreeNode(7);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(3);

    std::cout << "Original: ";
    printInOrder(root);
    std::cout << "\nAfter insert 5: ";
    root = insertIntoBST(root, 5);
    printInOrder(root);
    std::cout << "(expected 1 2 3 4 5 7)\n";
    return 0;
}
