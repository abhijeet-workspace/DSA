// DP on Trees — House Robber III (337), diameter (543), distribute coins (979).
// Bottom-up DFS returns subtree states; combine at parent.
#include <algorithm>
#include <cmath>
#include <iostream>
#include <utility>

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    explicit TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// {rob_this, skip_this}
std::pair<int, int> robHelper(TreeNode* root) {
    if (!root) {
        return {0, 0};
    }
    const auto L = robHelper(root->left);
    const auto R = robHelper(root->right);
    const int robThis = root->val + L.second + R.second;
    const int skipThis =
        std::max(L.first, L.second) + std::max(R.first, R.second);
    return {robThis, skipThis};
}

int robHouseIII(TreeNode* root) {
    const auto r = robHelper(root);
    return std::max(r.first, r.second);
}

int treeDiameterHeight(TreeNode* root, int& diameter) {
    if (!root) {
        return 0;
    }
    const int lh = treeDiameterHeight(root->left, diameter);
    const int rh = treeDiameterHeight(root->right, diameter);
    diameter = std::max(diameter, lh + rh);
    return 1 + std::max(lh, rh);
}

int distributeCoinsHelper(TreeNode* root, int& moves) {
    if (!root) {
        return 0;
    }
    const int leftEx = distributeCoinsHelper(root->left, moves);
    const int rightEx = distributeCoinsHelper(root->right, moves);
    moves += std::abs(leftEx) + std::abs(rightEx);
    return root->val - 1 + leftEx + rightEx; // excess coins leaving this node
}

int distributeCoins(TreeNode* root) {
    int moves = 0;
    distributeCoinsHelper(root, moves);
    return moves;
}

int main() {
    TreeNode* r1 = new TreeNode(3);
    r1->left = new TreeNode(2);
    r1->right = new TreeNode(3);
    r1->left->right = new TreeNode(3);
    r1->right->right = new TreeNode(1);
    std::cout << robHouseIII(r1) << " (expected 7)\n";

    TreeNode* r2 = new TreeNode(3);
    r2->left = new TreeNode(0);
    r2->right = new TreeNode(0);
    std::cout << distributeCoins(r2) << " (expected 2)\n";

    int diameter = 0;
    treeDiameterHeight(r1, diameter);
    std::cout << diameter << " (expected diameter edges on r1)\n";

    delete r1->left->right;
    delete r1->right->right;
    delete r1->left;
    delete r1->right;
    delete r1;
    delete r2->left;
    delete r2->right;
    delete r2;
    return 0;
}
