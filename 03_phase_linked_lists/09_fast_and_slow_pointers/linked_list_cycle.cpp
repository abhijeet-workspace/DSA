// Linked List Cycle — https://leetcode.com/problems/linked-list-cycle/
// Return true if the singly linked list contains a cycle.
#include <iostream>

struct ListNode {
    int val;
    ListNode* next;
    explicit ListNode(int x) : val(x), next(nullptr) {}
};

bool hasCycle(ListNode* head) {
    if (!head || !head->next) { // empty / single cannot cycle
        return false;
    }
    ListNode* slow = head;
    ListNode* fast = head;
    while (fast && fast->next) { // need room for two steps
        slow = slow->next; // +1
        fast = fast->next->next; // +2
        if (slow == fast) { // collision inside cycle
            return true;
        }
    }
    return false; // fast hit null — acyclic
}

int main() {
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = head->next; // cycle at 2
    std::cout << std::boolalpha << hasCycle(head) << " (expected true)\n";
    head->next->next->next->next = nullptr; // break cycle
    std::cout << hasCycle(head) << " (expected false)\n";
    delete head->next->next->next;
    delete head->next->next;
    delete head->next;
    delete head;
    return 0;
}
