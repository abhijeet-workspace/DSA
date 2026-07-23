// Path Sum II — https://leetcode.com/problems/path-sum-ii/
// All root-to-leaf paths whose values sum to targetSum.
#include <iostream>
#include <vector>

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    explicit TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

void dfs(TreeNode* root, int targetSum, std::vector<int>& path,
         std::vector<std::vector<int>>& result) {
    if (!root) {
        return;
    }
    path.push_back(root->val); // extend path
    if (!root->left && !root->right && root->val == targetSum) {
        result.push_back(path); // leaf match
    } else {
        dfs(root->left, targetSum - root->val, path, result);
        dfs(root->right, targetSum - root->val, path, result);
    }
    path.pop_back(); // backtrack
}

std::vector<std::vector<int>> pathSum(TreeNode* root, int targetSum) {
    std::vector<std::vector<int>> result;
    std::vector<int> path;
    dfs(root, targetSum, path, result);
    return result;
}

int main() {
    TreeNode* root = new TreeNode(5);
    root->left = new TreeNode(4);
    root->right = new TreeNode(8);
    root->left->left = new TreeNode(11);
    root->left->left->left = new TreeNode(7);
    root->left->left->right = new TreeNode(2);
    root->right->left = new TreeNode(13);
    root->right->right = new TreeNode(4);
    root->right->right->left = new TreeNode(5);
    root->right->right->right = new TreeNode(1);

    const auto paths = pathSum(root, 22);
    for (const auto& p : paths) {
        std::cout << "[ ";
        for (int x : p) {
            std::cout << x << " ";
        }
        std::cout << "]\n";
    }
    // expected: [5 4 11 2] and [5 8 4 5]
    return 0;
}
