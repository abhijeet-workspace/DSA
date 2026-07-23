// Subtree of Another Tree — https://leetcode.com/problems/subtree-of-another-tree/
// True if subRoot is a subtree of root (same structure and values).
#include <iostream>

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    explicit TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

bool isSameTree(TreeNode* a, TreeNode* b) {
    if (!a || !b) {
        return a == b; // both null or mismatch
    }
    return a->val == b->val && isSameTree(a->left, b->left) &&
           isSameTree(a->right, b->right);
}

bool isSubtree(TreeNode* root, TreeNode* subRoot) {
    if (!root) {
        return false;
    }
    if (isSameTree(root, subRoot)) {
        return true; // match rooted here
    }
    return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
}

int main() {
    TreeNode* r = new TreeNode(3);
    r->left = new TreeNode(4);
    r->right = new TreeNode(5);
    r->left->left = new TreeNode(1);
    r->left->right = new TreeNode(2);
    TreeNode* s = new TreeNode(4);
    s->left = new TreeNode(1);
    s->right = new TreeNode(2);
    std::cout << std::boolalpha << isSubtree(r, s) << " (expected true)\n";
    return 0;
}
