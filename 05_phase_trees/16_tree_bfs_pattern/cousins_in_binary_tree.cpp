// Cousins in Binary Tree — https://leetcode.com/problems/cousins-in-binary-tree/
#include <iostream>
#include <queue>
#include <utility>

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    explicit TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

bool isCousins(TreeNode* root, int x, int y) {
    std::queue<std::pair<TreeNode*, TreeNode*>> q; // node, parent
    q.push({root, nullptr});
    TreeNode *px = nullptr, *py = nullptr;
    int dx = -1, dy = -1, depth = 0;
    while (!q.empty()) {
        const int sz = static_cast<int>(q.size());
        for (int i = 0; i < sz; ++i) {
            auto [u, p] = q.front();
            q.pop();
            if (u->val == x) {
                px = p;
                dx = depth;
            }
            if (u->val == y) {
                py = p;
                dy = depth;
            }
            if (u->left)
                q.push({u->left, u});
            if (u->right)
                q.push({u->right, u});
        }
        if (dx != -1 && dy != -1)
            break;
        ++depth;
    }
    return dx == dy && px != py;
}

int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->right = new TreeNode(4);
    root->right->right = new TreeNode(5);
    std::cout << std::boolalpha << isCousins(root, 5, 4) << " (expected true)\n";
    std::cout << isCousins(root, 2, 3) << " (expected false)\n";
    return 0;
}
