// Merge k Sorted Lists — https://leetcode.com/problems/merge-k-sorted-lists/
// Min-heap of list heads; pop min and push next from same list.
#include <iostream>
#include <queue>
#include <vector>

struct ListNode {
    int val;
    ListNode* next;
    explicit ListNode(int x) : val(x), next(nullptr) {}
};

ListNode* makeList(const std::vector<int>& vals) {
    ListNode dummy(0);
    ListNode* t = &dummy;
    for (int v : vals) {
        t->next = new ListNode(v);
        t = t->next;
    }
    return dummy.next;
}

void freeList(ListNode* h) {
    while (h) {
        ListNode* n = h->next;
        delete h;
        h = n;
    }
}

ListNode* mergeKLists(std::vector<ListNode*>& lists) {
    using P = std::pair<int, ListNode*>;
    std::priority_queue<P, std::vector<P>, std::greater<P>> pq;
    for (ListNode* h : lists) {
        if (h) pq.push({h->val, h});
    }
    ListNode dummy(0);
    ListNode* tail = &dummy;
    while (!pq.empty()) {
        auto [v, node] = pq.top();
        pq.pop();
        (void)v;
        tail->next = node;
        tail = tail->next;
        if (node->next) pq.push({node->next->val, node->next});
    }
    return dummy.next;
}

int main() {
    std::vector<ListNode*> lists = {makeList({1, 4, 5}), makeList({1, 3, 4}), makeList({2, 6})};
    ListNode* m = mergeKLists(lists);
    for (ListNode* p = m; p; p = p->next) {
        std::cout << p->val;
        if (p->next) std::cout << "->";
    }
    std::cout << " (expected 1->1->2->3->4->4->5->6)\n";
    freeList(m);
    return 0;
}
