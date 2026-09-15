#include <algorithm>
#include <iostream>
#include <vector>

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

#include <utility>
int ans = 0;
std::pair<int, int> dfs(TreeNode* node) {
    if (!node) return {-1, -1};
    auto L = dfs(node->left), R = dfs(node->right);
    int left = 1 + L.second;   // came from left child means previous move was right from child
    int right = 1 + R.first;
    ans = std::max({ans, left, right});
    return {left, right};
}

int longestZigZag(TreeNode* root) {
    ans = 0;
    dfs(root);
    return ans;
}

int main() {
    // [1,null,1,1,1,null,null,1,1,null,1,null,null,null,1]
    TreeNode a(1), b(1), c(1), d(1), e(1), f(1), g(1), h(1);
    a.right = &b; b.left = &c; b.right = &d; d.left = &e; d.right = &f; e.right = &g; g.right = &h;
    std::cout << longestZigZag(&a) << " (expected 3)\n";
    return 0;
}
