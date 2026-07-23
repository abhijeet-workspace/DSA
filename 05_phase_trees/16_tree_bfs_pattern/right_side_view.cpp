// Binary Tree Right Side View — https://leetcode.com/problems/binary-tree-right-side-view/
// Values visible standing on the right, top to bottom.
#include <iostream>
#include <queue>
#include <vector>

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    explicit TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

std::vector<int> rightSideView(TreeNode* root) {
    if (!root) {
        return {};
    }
    std::vector<int> result;
    std::queue<TreeNode*> q;
    q.push(root);
    while (!q.empty()) {
        const int levelSize = static_cast<int>(q.size());
        for (int i = 0; i < levelSize; ++i) {
            TreeNode* curr = q.front();
            q.pop();
            if (i == levelSize - 1) { // last in level = rightmost
                result.push_back(curr->val);
            }
            if (curr->left) {
                q.push(curr->left);
            }
            if (curr->right) {
                q.push(curr->right);
            }
        }
    }
    return result;
}

int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->right = new TreeNode(5);
    root->right->right = new TreeNode(4);
    const auto view = rightSideView(root);
    std::cout << "Right Side View:";
    for (int v : view) {
        std::cout << " " << v;
    }
    std::cout << " (expected 1 3 4)\n";
    return 0;
}
