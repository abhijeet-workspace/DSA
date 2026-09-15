// Find Mode in BST — https://leetcode.com/problems/find-mode-in-binary-search-tree/
// Inorder streams equals together; track prev count vs max; collect all modes.
#include <iostream>
#include <vector>

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    explicit TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
    TreeNode* prev_ = nullptr;
    int count_ = 0;
    int max_count_ = 0;
    std::vector<int> modes_;

    void handle(int val) {
        if (prev_ && prev_->val == val) {
            ++count_;
        } else {
            count_ = 1;
        }
        if (count_ > max_count_) {
            max_count_ = count_;
            modes_.clear();
            modes_.push_back(val);
        } else if (count_ == max_count_) {
            modes_.push_back(val);
        }
        // prev_ updated by caller after visit
    }

    void inorder(TreeNode* node) {
        if (!node) {
            return;
        }
        inorder(node->left);
        handle(node->val);
        prev_ = node;
        inorder(node->right);
    }

  public:
    std::vector<int> findMode(TreeNode* root) {
        prev_ = nullptr;
        count_ = 0;
        max_count_ = 0;
        modes_.clear();
        inorder(root);
        return modes_;
    }
};

int main() {
    /*
          1
           \
            2
           /
          2
    */
    TreeNode* root = new TreeNode(1);
    root->right = new TreeNode(2);
    root->right->left = new TreeNode(2);
    const auto modes = Solution().findMode(root);
    std::cout << "modes:";
    for (int x : modes) {
        std::cout << " " << x;
    }
    std::cout << " (expected 2)\n";

    TreeNode* multi = new TreeNode(1);
    multi->left = new TreeNode(1);
    multi->right = new TreeNode(2);
    multi->right->left = new TreeNode(2);
    const auto modes2 = Solution().findMode(multi);
    std::cout << "modes:";
    for (int x : modes2) {
        std::cout << " " << x;
    }
    std::cout << " (expected 1 2)\n";
    return 0;
}
