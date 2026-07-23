// Middle of the Linked List — https://leetcode.com/problems/middle-of-the-linked-list/
// Return the middle node; if two middles, return the second.
#include <iostream>

struct ListNode {
    int val;
    ListNode* next;
    explicit ListNode(int x) : val(x), next(nullptr) {}
};

ListNode* middleNode(ListNode* head) {
    ListNode* slow = head;
    ListNode* fast = head;
    while (fast && fast->next) { // stop when fast cannot take 2 steps
        slow = slow->next; // +1
        fast = fast->next->next; // +2
    }
    return slow; // slow at middle (second if even length)
}

int main() {
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);
    ListNode* mid = middleNode(head);
    std::cout << "middle: " << mid->val << " (expected 3)\n";
    delete head->next->next->next->next;
    delete head->next->next->next;
    delete head->next->next;
    delete head->next;
    delete head;
    return 0;
}
