// Average of Levels in Binary Tree — https://leetcode.com/problems/average-of-levels-in-binary-tree/
#include <iostream>
#include <vector>
#include <queue>

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    explicit TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

std::vector<double> averageOfLevels(TreeNode* root) {
    std::vector<double> ans;
    if (!root) {
        return ans;
    }
    std::queue<TreeNode*> q;
    q.push(root);
    while (!q.empty()) {
        const int sz = static_cast<int>(q.size());
        long long sum = 0;
        for (int i = 0; i < sz; ++i) {
            TreeNode* u = q.front();
            q.pop();
            sum += u->val;
            if (u->left) q.push(u->left);
            if (u->right) q.push(u->right);
        }
        ans.push_back(static_cast<double>(sum) / sz);
    }
    return ans;
}

int main() {
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);
    auto a = averageOfLevels(root);
    std::cout << a.size() << " levels (expected 3)\n";
    std::cout << a[0] << " " << a[1] << " " << a[2] << "\n";
    return 0;
}
