// Find Largest Value in Each Tree Row —
// https://leetcode.com/problems/find-largest-value-in-each-tree-row/
#include <climits>
#include <iostream>
#include <queue>
#include <vector>

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    explicit TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

std::vector<int> largestValues(TreeNode* root) {
    std::vector<int> ans;
    if (!root)
        return ans;
    std::queue<TreeNode*> q;
    q.push(root);
    while (!q.empty()) {
        const int sz = static_cast<int>(q.size());
        int mx = INT_MIN;
        for (int i = 0; i < sz; ++i) {
            TreeNode* u = q.front();
            q.pop();
            mx = std::max(mx, u->val);
            if (u->left)
                q.push(u->left);
            if (u->right)
                q.push(u->right);
        }
        ans.push_back(mx);
    }
    return ans;
}

int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(3);
    root->right = new TreeNode(2);
    root->left->left = new TreeNode(5);
    root->left->right = new TreeNode(3);
    root->right->right = new TreeNode(9);
    auto a = largestValues(root);
    std::cout << a[0] << " " << a[1] << " " << a[2] << " (expected 1 3 9)\n";
    return 0;
}
