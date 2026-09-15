// Flatten Binary Tree to Linked List — https://leetcode.com/problems/flatten-binary-tree-to-linked-list/
// In-place flatten to right-skewed list in preorder; left always null.
#include <iostream>
#include <vector>

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    explicit TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

void flatten(TreeNode* root) {
    TreeNode* curr = root;
    while (curr) {
        if (curr->left) {
            TreeNode* pred = curr->left;
            while (pred->right) {
                pred = pred->right;
            }
            pred->right = curr->right;
            curr->right = curr->left;
            curr->left = nullptr;
        }
        curr = curr->right;
    }
}

std::vector<int> rightSpine(TreeNode* root) {
    std::vector<int> vals;
    while (root) {
        vals.push_back(root->val);
        root = root->right;
    }
    return vals;
}

int main() {
    // 1
    // / \
    // 2   5
    // / \   \
    // 3   4   6
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(5);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(4);
    root->right->right = new TreeNode(6);
    flatten(root);
    const auto vals = rightSpine(root);
    for (size_t i = 0; i < vals.size(); ++i) {
        if (i) std::cout << ' ';
        std::cout << vals[i];
    }
    std::cout << " (expected 1 2 3 4 5 6)\n";
    return 0;
}
