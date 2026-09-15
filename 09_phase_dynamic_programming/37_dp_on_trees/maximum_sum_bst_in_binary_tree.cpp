#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

#include <climits>

struct Info {
    bool bst;
    int mn, mx, sum;
};

int bestSum = 0;

Info dfs(TreeNode* node) {
    if (!node)
        return {true, INT_MAX, INT_MIN, 0};
    auto L = dfs(node->left), R = dfs(node->right);
    if (L.bst && R.bst && L.mx < node->val && node->val < R.mn) {
        const int s = L.sum + R.sum + node->val;
        bestSum = std::max(bestSum, s);
        return {true, std::min(L.mn, node->val), std::max(R.mx, node->val), s};
    }
    return {false, 0, 0, 0};
}

int maxSumBST(TreeNode* root) {
    bestSum = 0;
    dfs(root);
    return bestSum;
}

int main() {
    TreeNode a(1), b(4), c(3), d(2), e(4), f(2), g(5), h(4), i(6);
    a.left = &b;
    a.right = &c;
    b.left = &d;
    b.right = &e;
    c.left = &f;
    c.right = &g;
    g.left = &h;
    g.right = &i;
    std::cout << maxSumBST(&a) << " (expected 20)\n";
    return 0;
}
