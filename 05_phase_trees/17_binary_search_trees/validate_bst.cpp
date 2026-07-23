// Validate BST — https://leetcode.com/problems/validate-binary-search-tree/
// DFS with (lo, hi) bounds; each node must lie strictly inside.
#include <iostream>
#include <climits>

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    explicit TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

bool isValid(TreeNode* node, long long lo, long long hi) {
    if (!node) {
        return true;
    }
    if (node->val <= lo || node->val >= hi) {
        return false; // outside ancestor range
    }
    return isValid(node->left, lo, node->val) &&
           isValid(node->right, node->val, hi);
}

bool isValidBST(TreeNode* root) {
    return isValid(root, LLONG_MIN, LLONG_MAX);
}

int main() {
    TreeNode* ok = new TreeNode(2);
    ok->left = new TreeNode(1);
    ok->right = new TreeNode(3);
    TreeNode* bad = new TreeNode(5);
    bad->left = new TreeNode(1);
    bad->right = new TreeNode(4);
    std::cout << std::boolalpha
              << isValidBST(ok) << " (expected true)\n"
              << isValidBST(bad) << " (expected false)\n";
    return 0;
}
