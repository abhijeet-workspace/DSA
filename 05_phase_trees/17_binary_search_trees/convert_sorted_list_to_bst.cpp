// Convert Sorted List to Binary Search Tree —
// https://leetcode.com/problems/convert-sorted-list-to-binary-search-tree/
#include <iostream>

struct ListNode {
    int val;
    ListNode* next;
    explicit ListNode(int x) : val(x), next(nullptr) {}
};

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    explicit TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

TreeNode* sortedListToBST(ListNode* head) {
    if (!head)
        return nullptr;
    if (!head->next)
        return new TreeNode(head->val);
    ListNode* prev = nullptr;
    ListNode* slow = head;
    ListNode* fast = head;
    while (fast && fast->next) {
        prev = slow;
        slow = slow->next;
        fast = fast->next->next;
    }
    if (prev)
        prev->next = nullptr; // cut left half
    TreeNode* root = new TreeNode(slow->val);
    root->left = sortedListToBST(head == slow ? nullptr : head);
    root->right = sortedListToBST(slow->next);
    return root;
}

int main() {
    ListNode* h = new ListNode(-10);
    h->next = new ListNode(-3);
    h->next->next = new ListNode(0);
    h->next->next->next = new ListNode(5);
    h->next->next->next->next = new ListNode(9);
    TreeNode* root = sortedListToBST(h);
    std::cout << root->val << " (expected 0)\n";
    return 0;
}
