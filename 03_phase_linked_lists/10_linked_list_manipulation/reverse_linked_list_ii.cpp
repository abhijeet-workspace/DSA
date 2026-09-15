// Reverse Linked List II — https://leetcode.com/problems/reverse-linked-list-ii/
// Reverse the sublist from position left to right (1-indexed); return head.
#include <iostream>

struct ListNode {
    int val;
    ListNode* next;
    explicit ListNode(int x) : val(x), next(nullptr) {}
};

ListNode* reverseBetween(ListNode* head, int left, int right) {
    if (!head || left == right) {
        return head;
    }
    ListNode dummy(0);
    dummy.next = head;
    ListNode* before = &dummy;
    for (int i = 1; i < left; ++i) {
        before = before->next;
    }
    ListNode* curr = before->next; // first node of sublist
    for (int i = 0; i < right - left; ++i) {
        ListNode* move = curr->next; // node to bring after before
        curr->next = move->next;
        move->next = before->next;
        before->next = move;
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
    head->next->next->next->next = new ListNode(5);
    ListNode* res = reverseBetween(head, 2, 4);
    std::cout << "reversed [2,4]: ";
    printList(res); // expected 1 -> 4 -> 3 -> 2 -> 5
    while (res) {
        ListNode* t = res;
        res = res->next;
        delete t;
    }
    return 0;
}
