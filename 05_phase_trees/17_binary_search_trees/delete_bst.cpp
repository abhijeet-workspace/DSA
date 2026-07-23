// Delete Node in BST — https://leetcode.com/problems/delete-node-in-a-bst/
// Delete key from BST; return new root. Successor replaces two-child case.
#include <iostream>

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    explicit TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

TreeNode* findMin(TreeNode* node) {
    while (node->left) {
        node = node->left; // inorder successor in right subtree
    }
    return node;
}

TreeNode* deleteNode(TreeNode* root, int key) {
    if (!root) {
        return nullptr;
    }
    if (key < root->val) {
        root->left = deleteNode(root->left, key);
    } else if (key > root->val) {
        root->right = deleteNode(root->right, key);
    } else {
        if (!root->left) {
            TreeNode* temp = root->right;
            delete root;
            return temp; // 0 or 1 child (right)
        }
        if (!root->right) {
            TreeNode* temp = root->left;
            delete root;
            return temp; // only left child
        }
        TreeNode* temp = findMin(root->right);
        root->val = temp->val; // copy successor
        root->right = deleteNode(root->right, temp->val);
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
    TreeNode* root = new TreeNode(5);
    root->left = new TreeNode(3);
    root->right = new TreeNode(6);
    root->left->left = new TreeNode(2);
    root->left->right = new TreeNode(4);
    root->right->right = new TreeNode(7);

    std::cout << "Original: ";
    printInOrder(root);
    std::cout << "\nAfter delete 3: ";
    root = deleteNode(root, 3);
    printInOrder(root);
    std::cout << "(expected 2 4 5 6 7)\n";
    return 0;
}
