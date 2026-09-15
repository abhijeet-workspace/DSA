// Sort List — LC 148
// Sort a singly linked list in O(N log N) time and O(1) extra space (bottom-up merge).
#include <iostream>

struct ListNode {
    int val;
    ListNode* next;
    explicit ListNode(int x) : val(x), next(nullptr) {}
};

ListNode* split(ListNode* head, int n) {
    while (--n && head) {
        head = head->next;
    }
    if (!head) {
        return nullptr;
    }
    ListNode* second = head->next;
    head->next = nullptr;
    return second;
}

ListNode* merge(ListNode* a, ListNode* b) {
    ListNode dummy(0);
    ListNode* tail = &dummy;
    while (a && b) {
        if (a->val <= b->val) {
            tail->next = a;
            a = a->next;
        } else {
            tail->next = b;
            b = b->next;
        }
        tail = tail->next;
    }
    tail->next = a ? a : b;
    while (tail->next) {
        tail = tail->next; // advance to end for caller chaining
    }
    return dummy.next;
}

ListNode* sortList(ListNode* head) {
    if (!head || !head->next) {
        return head;
    }
    int n = 0;
    for (ListNode* p = head; p; p = p->next) {
        ++n;
    }
    ListNode dummy(0);
    dummy.next = head;
    for (int size = 1; size < n; size *= 2) {
        ListNode* prev = &dummy;
        ListNode* cur = dummy.next;
        while (cur) {
            ListNode* left = cur;
            ListNode* right = split(left, size);
            cur = split(right, size);
            prev->next = merge(left, right);
            while (prev->next) {
                prev = prev->next;
            }
        }
    }
    return dummy.next;
}

void printList(ListNode* head) {
    for (ListNode* p = head; p; p = p->next) {
        std::cout << p->val;
        if (p->next) {
            std::cout << " ";
        }
    }
}

void freeList(ListNode* head) {
    while (head) {
        ListNode* n = head->next;
        delete head;
        head = n;
    }
}

int main() {
    ListNode* a = new ListNode(4);
    a->next = new ListNode(2);
    a->next->next = new ListNode(1);
    a->next->next->next = new ListNode(3);
    ListNode* sorted = sortList(a);
    printList(sorted);
    std::cout << " (expected 1 2 3 4)\n";
    freeList(sorted);
    return 0;
}
