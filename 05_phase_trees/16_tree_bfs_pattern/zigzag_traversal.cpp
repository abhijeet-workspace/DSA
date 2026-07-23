// Binary Tree Zigzag Level Order — https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/
// Level order alternating left→right and right→left.
#include <iostream>
#include <queue>
#include <vector>

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    explicit TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

std::vector<std::vector<int>> zigzagLevelOrder(TreeNode* root) {
    std::vector<std::vector<int>> result;
    if (!root) {
        return result;
    }
    std::queue<TreeNode*> q;
    q.push(root);
    bool leftToRight = true;
    while (!q.empty()) {
        const int size = static_cast<int>(q.size());
        std::vector<int> level(static_cast<size_t>(size));
        for (int i = 0; i < size; ++i) {
            TreeNode* curr = q.front();
            q.pop();
            const int index = leftToRight ? i : (size - 1 - i); // place by direction
            level[static_cast<size_t>(index)] = curr->val;
            if (curr->left) {
                q.push(curr->left);
            }
            if (curr->right) {
                q.push(curr->right);
            }
        }
        result.push_back(std::move(level));
        leftToRight = !leftToRight; // flip each level
    }
    return result;
}

int main() {
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);
    const auto res = zigzagLevelOrder(root);
    for (const auto& level : res) {
        std::cout << "[ ";
        for (int x : level) {
            std::cout << x << " ";
        }
        std::cout << "] ";
    }
    std::cout << "\n(expected [ 3 ] [ 20 9 ] [ 15 7 ])\n";
    return 0;
}
