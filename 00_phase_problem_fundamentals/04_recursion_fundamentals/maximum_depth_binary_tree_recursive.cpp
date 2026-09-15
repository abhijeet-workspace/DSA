// Maximum Depth of Binary Tree — LC 104 (recursive)
#include <algorithm>
#include <iostream>

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

int maxDepth(TreeNode* root) {
    if (!root)
        return 0;
    return 1 + std::max(maxDepth(root->left), maxDepth(root->right));
}

int main() {
    TreeNode n3(3), n9(9), n20(20), n15(15), n7(7);
    n3.left = &n9;
    n3.right = &n20;
    n20.left = &n15;
    n20.right = &n7;
    std::cout << maxDepth(&n3) << " (expected 3)\n";
    std::cout << maxDepth(nullptr) << " (expected 0)\n";
    return 0;
}
