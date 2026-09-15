// Vertical Order Traversal of a Binary Tree —
// https://leetcode.com/problems/vertical-order-traversal-of-a-binary-tree/ Group nodes by
// (col,row); same cell sorted by value. BFS with map of col -> multiset of (row,val).
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <utility>
#include <vector>

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    explicit TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

std::vector<std::vector<int>> verticalTraversal(TreeNode* root) {
    std::map<int, std::multiset<std::pair<int, int>>> cols;  // col -> {(row, val)}
    std::queue<std::pair<TreeNode*, std::pair<int, int>>> q; // node, {row, col}
    q.push({root, {0, 0}});
    while (!q.empty()) {
        auto [node, rc] = q.front();
        q.pop();
        const int row = rc.first;
        const int col = rc.second;
        cols[col].insert({row, node->val});
        if (node->left) {
            q.push({node->left, {row + 1, col - 1}});
        }
        if (node->right) {
            q.push({node->right, {row + 1, col + 1}});
        }
    }
    std::vector<std::vector<int>> ans;
    for (auto& [c, ms] : cols) {
        (void)c;
        ans.emplace_back();
        for (const auto& [r, v] : ms) {
            (void)r;
            ans.back().push_back(v);
        }
    }
    return ans;
}

int main() {
    //     3
    //    / \
    //   9  20
    //     /  \
    //    15   7
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);
    const auto out = verticalTraversal(root);
    for (const auto& col : out) {
        for (size_t i = 0; i < col.size(); ++i) {
            if (i)
                std::cout << ' ';
            std::cout << col[i];
        }
        std::cout << " | ";
    }
    std::cout << "(expected 9 | 3 15 | 20 | 7)\n";
    return 0;
}
