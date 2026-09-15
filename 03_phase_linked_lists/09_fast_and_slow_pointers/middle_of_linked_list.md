# Middle of the Linked List

## 1. Problem Statement
[LeetCode 876](https://leetcode.com/problems/middle-of-the-linked-list/) — return the middle node of a singly linked list; if even length, return the second middle.

- **Inputs:** non-empty `ListNode* head`.
- **Output:** pointer to middle node.
- **Valid answer:** for length `N`, node at index `N/2` (0-based).
- **Edges:** single node; even length (`1..6` → `4`); odd length.

## 2. Intuition
Fast moves twice as fast as slow; when fast ends, slow is halfway.

## 3. Brute Force → Optimal
- **Brute:** count length, then walk `N/2` — two passes.
- **Optimal:** one-pass slow/fast — same O(N) time, one traversal.

## 4. Data Structure / Approach Justification
**Chosen:** slow/fast pointers (no length counter).

- **vs count then index:** extra full pass; same asymptotics.
- **vs store in array:** O(N) space unnecessary.

## 5. Logic Walkthrough
Start both at `head`. While `fast` and `fast->next` exist, `slow++`, `fast+=2`. Return `slow`.

## 6. Dry Run
`1→2→3→4→5`: steps end with `fast` null-ish and `slow` on `3`. For `1→2→3→4`, loop stops with `slow` on `3` (second middle).

## 7. Time & Space Complexity
Time **O(N)**. Space **O(1)**. Why: single traversal with two pointers (section 4).

## 8. Trade-offs & Alternatives
Two-pass count is clearer for beginners; slow/fast is interview-standard and reusable for palindrome/reorder.

## 9. Common Mistakes / Edge Cases
Returning first middle on even length; null-deref when advancing fast; empty list (problem usually guarantees ≥1).

## 10. Interview Follow-ups / Variations
Delete middle; find 1/3 point; palindrome / reorder list reuse mid-find.

## 11. Tags
`linked-list`, `fast-slow-pointers`, `leetcode-876`, `difficulty:easy`
