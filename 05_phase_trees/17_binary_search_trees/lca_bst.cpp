// LCA of BST — https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree/
// Walk down until p and q split (or one equals curr); that node is LCA.
#include <iostream>

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    explicit TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    TreeNode* curr = root;
    while (curr) {
        if (p->val < curr->val && q->val < curr->val) {
            curr = curr->left; // both in left
        } else if (p->val > curr->val && q->val > curr->val) {
            curr = curr->right; // both in right
        } else {
            return curr; // split or match
        }
    }
    return nullptr;
}

int main() {
    TreeNode* root = new TreeNode(6);
    root->left = new TreeNode(2);
    root->right = new TreeNode(8);
    root->left->left = new TreeNode(0);
    root->left->right = new TreeNode(4);
    TreeNode* p = root->left;
    TreeNode* q = root->left->right;
    std::cout << lowestCommonAncestor(root, p, q)->val << " (expected 2)\n";
    return 0;
}
