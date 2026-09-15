// All Nodes Distance K in Binary Tree —
// https://leetcode.com/problems/all-nodes-distance-k-in-binary-tree/
#include <iostream>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <vector>

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    explicit TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

void markParent(TreeNode* n, TreeNode* p, std::unordered_map<TreeNode*, TreeNode*>& parent) {
    if (!n) {
        return;
    }
    if (p) {
        parent[n] = p;
    }
    markParent(n->left, n, parent);
    markParent(n->right, n, parent);
}

std::vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
    std::unordered_map<TreeNode*, TreeNode*> parent;
    markParent(root, nullptr, parent);
    std::queue<TreeNode*> q;
    std::unordered_set<TreeNode*> seen;
    q.push(target);
    seen.insert(target);
    int dist = 0;
    while (!q.empty() && dist < k) {
        const int sz = static_cast<int>(q.size());
        for (int i = 0; i < sz; ++i) {
            TreeNode* u = q.front();
            q.pop();
            for (TreeNode* v : {u->left, u->right, parent.count(u) ? parent[u] : nullptr}) {
                if (v && !seen.count(v)) {
                    seen.insert(v);
                    q.push(v);
                }
            }
        }
        ++dist;
    }
    std::vector<int> ans;
    while (!q.empty()) {
        ans.push_back(q.front()->val);
        q.pop();
    }
    return ans;
}

int main() {
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(5);
    root->right = new TreeNode(1);
    root->left->left = new TreeNode(6);
    root->left->right = new TreeNode(2);
    root->right->left = new TreeNode(0);
    root->right->right = new TreeNode(8);
    root->left->right->left = new TreeNode(7);
    root->left->right->right = new TreeNode(4);
    auto ans = distanceK(root, root->left, 2);
    std::cout << "count=" << ans.size() << " (expected 3)\n";
    for (int x : ans) {
        std::cout << x << " ";
    }
    std::cout << "\n";
    return 0;
}
