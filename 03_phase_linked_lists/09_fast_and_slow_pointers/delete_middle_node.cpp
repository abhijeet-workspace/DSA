// Delete the Middle Node — https://leetcode.com/problems/delete-the-middle-node-of-a-linked-list/
// Delete middle (second middle if even); return new head.
#include <iostream>

struct ListNode {
    int val;
    ListNode* next;
    explicit ListNode(int x) : val(x), next(nullptr) {}
};

ListNode* deleteMiddle(ListNode* head) {
    if (!head->next) {
        delete head;
        return nullptr;
    }
    ListNode* slow = head;
    ListNode* fast = head;
    ListNode* prev = nullptr;
    while (fast && fast->next) {
        prev = slow;
        slow = slow->next;
        fast = fast->next->next;
    }
    prev->next = slow->next;
    delete slow;
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
    head->next = new ListNode(3);
    head->next->next = new ListNode(4);
    head->next->next->next = new ListNode(7);
    head->next->next->next->next = new ListNode(1);
    head->next->next->next->next->next = new ListNode(2);
    head->next->next->next->next->next->next = new ListNode(6);
    head = deleteMiddle(head);
    std::cout << "result: ";
    printList(head); // expected 1 -> 3 -> 4 -> 1 -> 2 -> 6
    while (head) {
        ListNode* t = head;
        head = head->next;
        delete t;
    }
    return 0;
}
