// Palindrome Linked List — https://leetcode.com/problems/palindrome-linked-list/
// Return true if the singly linked list reads the same forward and backward.
#include <iostream>

struct ListNode {
    int val;
    ListNode* next;
    explicit ListNode(int x) : val(x), next(nullptr) {}
};

bool isPalindrome(ListNode* head) {
    if (!head || !head->next) {
        return true;
    }
    ListNode* slow = head;
    ListNode* fast = head;
    while (fast && fast->next) { // find mid
        slow = slow->next;
        fast = fast->next->next;
    }
    ListNode* prev = nullptr;
    ListNode* curr = slow;
    while (curr) { // reverse second half
        ListNode* nxt = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nxt;
    }
    ListNode* p1 = head;
    ListNode* p2 = prev; // head of reversed half
    while (p2) { // compare halves
        if (p1->val != p2->val) {
            return false;
        }
        p1 = p1->next;
        p2 = p2->next;
    }
    return true;
}

int main() {
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(2);
    head->next->next->next = new ListNode(1);
    std::cout << std::boolalpha << isPalindrome(head)
              << " (expected true)\n";
    while (head) {
        ListNode* t = head;
        head = head->next;
        delete t;
    }
    return 0;
}
