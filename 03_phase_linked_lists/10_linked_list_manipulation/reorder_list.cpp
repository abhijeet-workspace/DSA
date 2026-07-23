// Reorder List — https://leetcode.com/problems/reorder-list/
// Reorder L0→L1→…→Ln into L0→Ln→L1→Ln-1→…
#include <iostream>

struct ListNode {
    int val;
    ListNode* next;
    explicit ListNode(int x) : val(x), next(nullptr) {}
};

void reorderList(ListNode* head) {
    if (!head || !head->next || !head->next->next) {
        return; // <3 nodes: already done
    }
    ListNode* slow = head;
    ListNode* fast = head;
    while (fast->next && fast->next->next) { // stop before second mid
        slow = slow->next;
        fast = fast->next->next;
    }
    ListNode* prev = nullptr;
    ListNode* curr = slow->next;
    slow->next = nullptr; // cut halves
    while (curr) { // reverse second half
        ListNode* nxt = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nxt;
    }
    ListNode* p1 = head;
    ListNode* p2 = prev;
    while (p2) { // weave
        ListNode* t1 = p1->next;
        ListNode* t2 = p2->next;
        p1->next = p2;
        p2->next = t1;
        p1 = t1;
        p2 = t2;
    }
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
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);
    reorderList(head);
    std::cout << "reordered: ";
    printList(head); // expected 1 -> 5 -> 2 -> 4 -> 3
    while (head) {
        ListNode* t = head;
        head = head->next;
        delete t;
    }
    return 0;
}
