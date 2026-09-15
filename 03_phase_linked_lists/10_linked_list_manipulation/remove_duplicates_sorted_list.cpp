// Remove Duplicates from Sorted List —
// https://leetcode.com/problems/remove-duplicates-from-sorted-list/ Delete all duplicates so each
// distinct value appears once in a sorted list.
#include <iostream>

struct ListNode {
    int val;
    ListNode* next;
    explicit ListNode(int x) : val(x), next(nullptr) {}
};

ListNode* deleteDuplicates(ListNode* head) {
    ListNode* curr = head;
    while (curr && curr->next) {
        if (curr->val == curr->next->val) {
            ListNode* dup = curr->next;
            curr->next = dup->next; // skip duplicate
            delete dup;
        } else {
            curr = curr->next;
        }
    }
    return head;
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
    ListNode* head = new ListNode(1);
    head->next = new ListNode(1);
    head->next->next = new ListNode(2);
    head->next->next->next = new ListNode(3);
    head->next->next->next->next = new ListNode(3);
    ListNode* res = deleteDuplicates(head);
    std::cout << "unique: ";
    printList(res); // expected 1 -> 2 -> 3
    while (res) {
        ListNode* t = res;
        res = res->next;
        delete t;
    }
    return 0;
}
