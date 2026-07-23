// Construct Binary Tree from Preorder and Inorder — https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/
// Build unique tree from preorder + inorder (distinct values).
#include <iostream>
#include <vector>
#include <unordered_map>

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    explicit TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

TreeNode* build(const std::vector<int>& pre, int& i, int L, int R,
                const std::unordered_map<int, int>& pos) {
    if (L > R) {
        return nullptr; // empty range
    }
    const int v = pre[static_cast<size_t>(i++)]; // next preorder root
    TreeNode* root = new TreeNode(v);
    const int m = pos.at(v); // inorder split index
    root->left = build(pre, i, L, m - 1, pos); // left subtree
    root->right = build(pre, i, m + 1, R, pos); // right subtree
    return root;
}

TreeNode* buildTree(std::vector<int>& preorder, std::vector<int>& inorder) {
    std::unordered_map<int, int> pos;
    for (int i = 0; i < static_cast<int>(inorder.size()); ++i) {
        pos[inorder[static_cast<size_t>(i)]] = i; // value -> inorder index
    }
    int i = 0; // shared preorder cursor
    return build(preorder, i, 0, static_cast<int>(inorder.size()) - 1, pos);
}

void printInorder(TreeNode* t) {
    if (!t) {
        return;
    }
    printInorder(t->left);
    std::cout << t->val << " ";
    printInorder(t->right);
}

int main() {
    std::vector<int> pre = {3, 9, 20, 15, 7};
    std::vector<int> in = {9, 3, 15, 20, 7};
    TreeNode* r = buildTree(pre, in);
    printInorder(r);
    std::cout << "(expected 9 3 15 20 7)\n";
    return 0;
}
