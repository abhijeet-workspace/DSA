// Linked List Random Node — LC 382
#include <cstdlib>
#include <iostream>

struct ListNode {
    int val;
    ListNode* next;
    explicit ListNode(int v) : val(v), next(nullptr) {}
};

struct Solution {
    ListNode* head;
    explicit Solution(ListNode* h) : head(h) {}
    int getRandom() {
        int ans = head->val, i = 1;
        for (ListNode* cur = head->next; cur; cur = cur->next) {
            ++i;
            if (std::rand() % i == 0)
                ans = cur->val;
        }
        return ans;
    }
};

int main() {
    std::srand(4);
    ListNode n0(10), n1(1), n2(2), n3(3);
    n0.next = &n1;
    n1.next = &n2;
    n2.next = &n3;
    Solution s(&n0);
    for (int i = 0; i < 4; ++i)
        std::cout << s.getRandom() << " ";
    std::cout << "\n";
    return 0;
}
