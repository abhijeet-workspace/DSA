// Count Good Nodes — https://leetcode.com/problems/count-good-nodes-in-binary-tree/
// Count nodes whose value is >= every ancestor on the root-to-node path.
#include <algorithm>
#include <iostream>

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    explicit TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

int dfs(TreeNode* n, int mx) {
    if (!n) {
        return 0;
    }
    const int good = n->val >= mx ? 1 : 0; // good if >= max so far
    mx = std::max(mx, n->val);
    return good + dfs(n->left, mx) + dfs(n->right, mx);
}

int goodNodes(TreeNode* root) {
    return root ? dfs(root, root->val) : 0;
}

int main() {
    TreeNode* r = new TreeNode(3);
    r->left = new TreeNode(1);
    r->right = new TreeNode(4);
    r->left->left = new TreeNode(3);
    r->right->left = new TreeNode(1);
    r->right->right = new TreeNode(5);
    std::cout << goodNodes(r) << " (expected 4)\n";
    return 0;
}
