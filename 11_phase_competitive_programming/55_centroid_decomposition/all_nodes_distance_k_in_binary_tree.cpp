// All Nodes Distance K in Binary Tree — LeetCode 863
// Build parent links, BFS from target to distance K.
#include <algorithm>
#include <iostream>
#include <queue>
#include <unordered_map>
#include <vector>

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

void buildParent(TreeNode* node, TreeNode* p, std::unordered_map<TreeNode*, TreeNode*>& par) {
    if (!node)
        return;
    par[node] = p;
    buildParent(node->left, node, par);
    buildParent(node->right, node, par);
}

std::vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
    std::unordered_map<TreeNode*, TreeNode*> par;
    buildParent(root, nullptr, par);
    std::queue<TreeNode*> q;
    std::unordered_map<TreeNode*, bool> seen;
    q.push(target);
    seen[target] = true;
    int dist = 0;
    while (!q.empty()) {
        if (dist == k)
            break;
        int sz = static_cast<int>(q.size());
        for (int i = 0; i < sz; ++i) {
            TreeNode* u = q.front();
            q.pop();
            for (TreeNode* v : {u->left, u->right, par[u]}) {
                if (v && !seen[v]) {
                    seen[v] = true;
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
    //      3
    //     / \
    //    5   1
    //   / \ / \
    //  6  2 0  8
    //    / \
    //   7   4
    TreeNode n3(3), n5(5), n1(1), n6(6), n2(2), n0(0), n8(8), n7(7), n4(4);
    n3.left = &n5;
    n3.right = &n1;
    n5.left = &n6;
    n5.right = &n2;
    n1.left = &n0;
    n1.right = &n8;
    n2.left = &n7;
    n2.right = &n4;
    auto ans = distanceK(&n3, &n5, 2);
    std::sort(ans.begin(), ans.end());
    std::cout << "nodes:";
    for (int x : ans)
        std::cout << " " << x;
    std::cout << " (expected 1 4 7)\n";
    return 0;
}
