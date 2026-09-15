// Swap Nodes in Pairs — https://leetcode.com/problems/swap-nodes-in-pairs/
// Swap every two adjacent nodes; return the new head.
#include <iostream>

struct ListNode {
    int val;
    ListNode* next;
    explicit ListNode(int x) : val(x), next(nullptr) {}
};

ListNode* swapPairs(ListNode* head) {
    ListNode dummy(0);
    dummy.next = head;
    ListNode* prev = &dummy;
    while (prev->next && prev->next->next) {
        ListNode* a = prev->next;
        ListNode* b = a->next;
        a->next = b->next; // a → rest
        b->next = a;       // b → a
        prev->next = b;    // prev → b
        prev = a;          // next pair after a
    }
    return dummy.next;
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
    ListNode* res = swapPairs(head);
    std::cout << "swapped: ";
    printList(res); // expected 2 -> 1 -> 4 -> 3
    while (res) {
        ListNode* t = res;
        res = res->next;
        delete t;
    }
    return 0;
}
