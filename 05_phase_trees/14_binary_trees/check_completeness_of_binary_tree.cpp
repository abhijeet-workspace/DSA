// Check Completeness of a Binary Tree — https://leetcode.com/problems/check-completeness-of-a-binary-tree/
// True iff tree is complete (levels filled left-to-right).
#include <iostream>
#include <queue>

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    explicit TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

bool isCompleteTree(TreeNode* root) {
    if (!root) {
        return true;
    }
    std::queue<TreeNode*> q;
    q.push(root);
    bool seenNull = false;
    while (!q.empty()) {
        TreeNode* u = q.front();
        q.pop();
        if (!u) {
            seenNull = true;
            continue;
        }
        if (seenNull) {
            return false; // non-null after a gap
        }
        q.push(u->left);
        q.push(u->right);
    }
    return true;
}

int main() {
    TreeNode* ok = new TreeNode(1);
    ok->left = new TreeNode(2);
    ok->right = new TreeNode(3);
    ok->left->left = new TreeNode(4);
    ok->left->right = new TreeNode(5);
    ok->right->left = new TreeNode(6);
    std::cout << std::boolalpha << isCompleteTree(ok) << " (expected true)\n";

    TreeNode* bad = new TreeNode(1);
    bad->left = new TreeNode(2);
    bad->right = new TreeNode(3);
    bad->left->left = new TreeNode(4);
    bad->left->right = new TreeNode(5);
    bad->right->right = new TreeNode(7);
    std::cout << isCompleteTree(bad) << " (expected false)\n";
    return 0;
}
