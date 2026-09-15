// Merge Two Binary Trees — https://leetcode.com/problems/merge-two-binary-trees/
// Overlay trees: sum overlapping nodes; keep non-null side otherwise.
#include <iostream>

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    explicit TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
    if (!t1) {
        return t2;
    }
    if (!t2) {
        return t1;
    }
    t1->val += t2->val; // overlap: sum
    t1->left = mergeTrees(t1->left, t2->left);
    t1->right = mergeTrees(t1->right, t2->right);
    return t1;
}

void printPreorder(TreeNode* n) {
    if (!n) {
        return;
    }
    std::cout << n->val << " ";
    printPreorder(n->left);
    printPreorder(n->right);
}

int main() {
    TreeNode* a = new TreeNode(1);
    a->left = new TreeNode(3);
    a->right = new TreeNode(2);
    a->left->left = new TreeNode(5);
    TreeNode* b = new TreeNode(2);
    b->left = new TreeNode(1);
    b->right = new TreeNode(3);
    b->left->right = new TreeNode(4);
    b->right->right = new TreeNode(7);
    TreeNode* m = mergeTrees(a, b);
    printPreorder(m);
    std::cout << "(expected 3 4 5 4 5 7)\n";
    return 0;
}
