// Sort List — https://leetcode.com/problems/sort-list/
// Merge-sort a linked list (mid via slow/fast).
#include <iostream>

struct ListNode {
    int val;
    ListNode* next;
    explicit ListNode(int x) : val(x), next(nullptr) {}
};

ListNode* merge(ListNode* a, ListNode* b) {
    ListNode dummy(0);
    ListNode* t = &dummy;
    while (a && b) {
        if (a->val <= b->val) {
            t->next = a;
            a = a->next;
        } else {
            t->next = b;
            b = b->next;
        }
        t = t->next;
    }
    t->next = a ? a : b;
    return dummy.next;
}

ListNode* sortList(ListNode* head) {
    if (!head || !head->next) {
        return head;
    }
    ListNode* slow = head;
    ListNode* fast = head->next;
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    }
    ListNode* mid = slow->next;
    slow->next = nullptr;
    return merge(sortList(head), sortList(mid));
}

void printList(ListNode* head) {
    while (head) {
        std::cout << head->val;
        if (head->next) {
            std::cout << " -> ";
        }
        head = head->next;
    }
    std::cout << "\n";
}

int main() {
    ListNode* head = new ListNode(4);
    head->next = new ListNode(2);
    head->next->next = new ListNode(1);
    head->next->next->next = new ListNode(3);
    head = sortList(head);
    std::cout << "result: ";
    printList(head); // expected 1 -> 2 -> 3 -> 4
    while (head) {
        ListNode* t = head;
        head = head->next;
        delete t;
    }
    return 0;
}
