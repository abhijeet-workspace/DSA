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

// 0 = needs camera, 1 = covered, 2 = has camera
int ans = 0;
int dfs(TreeNode* node) {
    if (!node) return 1;
    int L = dfs(node->left), R = dfs(node->right);
    if (L == 0 || R == 0) { ++ans; return 2; }
    if (L == 2 || R == 2) return 1;
    return 0;
}

int minCameraCover(TreeNode* root) {
    ans = 0;
    if (dfs(root) == 0) ++ans;
    return ans;
}

int main() {
    TreeNode a(0), b(0), c(0), d(0), e(0);
    a.left = &b; b.left = &c; b.right = &d; // simple
    // better sample: [0,0,null,0,0]
    TreeNode r(0), l(0), ll(0), lr(0);
    r.left = &l; l.left = &ll; l.right = &lr;
    std::cout << minCameraCover(&r) << " (expected 1)\n";
    return 0;
}
