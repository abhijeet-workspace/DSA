// Binary Tree Paths — https://leetcode.com/problems/binary-tree-paths/
// Return all root-to-leaf paths as "a->b->c" strings.
#include <iostream>
#include <string>
#include <vector>

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    explicit TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

void dfs(TreeNode* node, std::string path, std::vector<std::string>& out) {
    if (!node) {
        return;
    }
    path += std::to_string(node->val);
    if (!node->left && !node->right) {
        out.push_back(path); // leaf: finish path
        return;
    }
    path += "->";
    dfs(node->left, path, out);
    dfs(node->right, path, out);
}

std::vector<std::string> binaryTreePaths(TreeNode* root) {
    std::vector<std::string> out;
    dfs(root, "", out);
    return out;
}

int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->right = new TreeNode(5);
    for (const auto& p : binaryTreePaths(root)) {
        std::cout << p << "\n";
    }
    std::cout << "(expected 1->2->5 and 1->3)\n";
    return 0;
}
