#include <algorithm>
#include <iostream>
#include <vector>

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

#include <functional>
#include <unordered_map>

std::vector<TreeNode*> allPossibleFBT(int n) {
    std::unordered_map<int, std::vector<TreeNode*>> memo;
    std::function<std::vector<TreeNode*>(int)> dfs = [&](int k) -> std::vector<TreeNode*> {
        if (memo.count(k)) return memo[k];
        std::vector<TreeNode*> res;
        if (k % 2 == 0) return memo[k] = res;
        if (k == 1) { res.push_back(new TreeNode(0)); return memo[k] = res; }
        for (int L = 1; L < k; L += 2) {
            auto lefts = dfs(L), rights = dfs(k - 1 - L);
            for (auto* l : lefts) for (auto* r : rights) {
                auto* root = new TreeNode(0);
                root->left = l; root->right = r;
                res.push_back(root);
            }
        }
        return memo[k] = res;
    };
    return dfs(n);
}

int main() {
    std::cout << allPossibleFBT(7).size() << " (expected 5)\n";
    std::cout << allPossibleFBT(3).size() << " (expected 1)\n";
    return 0;
}
