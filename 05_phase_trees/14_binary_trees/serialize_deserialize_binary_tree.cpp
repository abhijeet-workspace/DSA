// Serialize / Deserialize Binary Tree — https://leetcode.com/problems/serialize-and-deserialize-binary-tree/
// Preorder with '#' null markers; round-trip encode then rebuild.
#include <iostream>
#include <string>
#include <sstream>

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    explicit TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Codec {
public:
    std::string serialize(TreeNode* root) {
        if (!root) {
            return "#,";
        }
        return std::to_string(root->val) + "," + serialize(root->left)
            + serialize(root->right);
    }

    TreeNode* deserialize(const std::string& data) {
        std::stringstream ss(data);
        return build(ss);
    }

private:
    TreeNode* build(std::stringstream& ss) {
        std::string tok;
        if (!std::getline(ss, tok, ',')) {
            return nullptr;
        }
        if (tok == "#" || tok.empty()) {
            return nullptr; // null marker
        }
        TreeNode* node = new TreeNode(std::stoi(tok));
        node->left = build(ss);  // next tokens = left subtree
        node->right = build(ss);
        return node;
    }
};

void freeTree(TreeNode* root) {
    if (!root) {
        return;
    }
    freeTree(root->left);
    freeTree(root->right);
    delete root;
}

int main() {
    TreeNode* r = new TreeNode(1);
    r->left = new TreeNode(2);
    r->right = new TreeNode(3);
    Codec c;
    const std::string s = c.serialize(r);
    TreeNode* out = c.deserialize(s);
    std::cout << "serialized: " << s << "\n";
    std::cout << "root=" << out->val << " left=" << out->left->val
              << " right=" << out->right->val << " (expected 1 2 3)\n";
    freeTree(r);
    freeTree(out);
    return 0;
}
