// Same Tree — https://leetcode.com/problems/same-tree/
// True iff two trees match in structure and node values.
#include <iostream>

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    explicit TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

bool isSameTree(TreeNode* p, TreeNode* q) {
    if (!p || !q) {
        return p == q; // both null or one missing
    }
    return p->val == q->val && isSameTree(p->left, q->left)
        && isSameTree(p->right, q->right);
}

int main() {
    TreeNode* a = new TreeNode(1);
    a->left = new TreeNode(2);
    a->right = new TreeNode(3);
    TreeNode* b = new TreeNode(1);
    b->left = new TreeNode(2);
    b->right = new TreeNode(3);
    std::cout << std::boolalpha << isSameTree(a, b) << " (expected true)\n";
    delete a->left;
    delete a->right;
    delete a;
    delete b->left;
    delete b->right;
    delete b;
    return 0;
}
