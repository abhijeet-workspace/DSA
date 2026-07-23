// Merge k Sorted Lists — https://leetcode.com/problems/merge-k-sorted-lists/
// Min-heap over K list heads; also demos: matrix kth, pairs, arrays.
#include <algorithm>
#include <iostream>
#include <queue>
#include <tuple>
#include <vector>

struct ListNode {
    int val;
    ListNode* next;
    explicit ListNode(int x) : val(x), next(nullptr) {}
};

ListNode* makeList(const std::vector<int>& vals) {
    if (vals.empty()) {
        return nullptr;
    }
    ListNode* head = new ListNode(vals[0]);
    ListNode* cur = head;
    for (size_t i = 1; i < vals.size(); ++i) {
        cur->next = new ListNode(vals[i]);
        cur = cur->next;
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

ListNode* mergeKLists(std::vector<ListNode*>& lists) {
    using P = std::pair<int, ListNode*>;
    std::priority_queue<P, std::vector<P>, std::greater<P>> minHeap;
    for (ListNode* head : lists) {
        if (head) {
            minHeap.push({head->val, head}); // seed with each non-null head
        }
    }
    ListNode dummy(0);
    ListNode* tail = &dummy;
    while (!minHeap.empty()) {
        auto [val, node] = minHeap.top();
        minHeap.pop();
        (void)val;
        tail->next = node;
        tail = tail->next;
        if (node->next) {
            minHeap.push({node->next->val, node->next}); // advance that list
        }
    }
    return dummy.next;
}

int kthSmallest(const std::vector<std::vector<int>>& matrix, int k) {
    using T = std::tuple<int, int, int>; // val, row, col
    std::priority_queue<T, std::vector<T>, std::greater<T>> minHeap;
    const int n = static_cast<int>(matrix.size());
    for (int r = 0; r < std::min(k, n); ++r) {
        minHeap.push({matrix[static_cast<size_t>(r)][0], r, 0});
    }
    int result = 0;
    while (k-- > 0) {
        auto [val, r, c] = minHeap.top();
        minHeap.pop();
        result = val;
        if (c + 1 < n) {
            minHeap.push({matrix[static_cast<size_t>(r)][static_cast<size_t>(c + 1)], r, c + 1});
        }
    }
    return result;
}

std::vector<std::vector<int>> kSmallestPairs(const std::vector<int>& nums1,
                                             const std::vector<int>& nums2, int k) {
    using T = std::tuple<int, int, int>; // sum, i, j
    std::priority_queue<T, std::vector<T>, std::greater<T>> minHeap;
    for (int j = 0; j < std::min(k, static_cast<int>(nums2.size())); ++j) {
        minHeap.push({nums1[0] + nums2[static_cast<size_t>(j)], 0, j});
    }
    std::vector<std::vector<int>> result;
    while (k-- > 0 && !minHeap.empty()) {
        auto [sum, i, j] = minHeap.top();
        minHeap.pop();
        (void)sum;
        result.push_back({nums1[static_cast<size_t>(i)], nums2[static_cast<size_t>(j)]});
        if (i + 1 < static_cast<int>(nums1.size())) {
            minHeap.push({nums1[static_cast<size_t>(i + 1)] + nums2[static_cast<size_t>(j)], i + 1, j});
        }
    }
    return result;
}

std::vector<int> mergeKSortedArrays(const std::vector<std::vector<int>>& arrays) {
    using T = std::tuple<int, int, int>; // val, arrayIdx, elemIdx
    std::priority_queue<T, std::vector<T>, std::greater<T>> minHeap;
    for (int i = 0; i < static_cast<int>(arrays.size()); ++i) {
        if (!arrays[static_cast<size_t>(i)].empty()) {
            minHeap.push({arrays[static_cast<size_t>(i)][0], i, 0});
        }
    }
    std::vector<int> result;
    while (!minHeap.empty()) {
        auto [val, i, j] = minHeap.top();
        minHeap.pop();
        result.push_back(val);
        if (j + 1 < static_cast<int>(arrays[static_cast<size_t>(i)].size())) {
            minHeap.push({arrays[static_cast<size_t>(i)][static_cast<size_t>(j + 1)], i, j + 1});
        }
    }
    return result;
}

int main() {
    std::vector<ListNode*> lists = {
        makeList({1, 4, 7}),
        makeList({2, 5, 8}),
        makeList({0, 3, 6, 9}),
    };
    ListNode* merged = mergeKLists(lists);
    std::cout << "mergeK: ";
    printList(merged); // expected 0 -> 1 -> ... -> 9
    while (merged) {
        ListNode* t = merged;
        merged = merged->next;
        delete t;
    }

    const std::vector<std::vector<int>> matrix = {{1, 5, 9}, {10, 11, 13}, {12, 13, 15}};
    std::cout << "kth= " << kthSmallest(matrix, 8) << " (expected 13)\n";

    const auto pairs = kSmallestPairs({1, 7, 11}, {2, 4, 6}, 3);
    std::cout << "pairs:";
    for (const auto& p : pairs) {
        std::cout << " [" << p[0] << "," << p[1] << "]";
    }
    std::cout << " (expected [1,2] [1,4] [1,6])\n";

    const auto arr = mergeKSortedArrays({{1, 4, 7}, {2, 5, 8}, {3, 6, 9}});
    std::cout << "arrays:";
    for (int x : arr) {
        std::cout << " " << x;
    }
    std::cout << "\n";
    return 0;
}
