# Palindrome Linked List

## 1. Problem Statement
[LeetCode 234](https://leetcode.com/problems/palindrome-linked-list/) — return whether a singly linked list is a palindrome.

- **Inputs:** `ListNode* head`.
- **Output:** `bool`.
- **Valid answer:** `true` iff values read the same forward and backward.
- **Edges:** empty / one node; even vs odd length; all equal; not palindrome.

## 2. Intuition
Find the middle with slow/fast, reverse the second half, compare halves with two pointers.

## 3. Brute Force → Optimal
- **Brute:** copy values to array / stack — O(N) space.
- **Optimal:** mid + reverse + compare — O(1) extra space (mutates list; restore optional).

## 4. Data Structure / Approach Justification
**Chosen:** fast/slow for mid, then reverse second half.

- **vs array copy:** wastes O(N) memory interviews often disallow.
- **vs recursion stack:** still O(N) space for call frames.

## 5. Logic Walkthrough
1. Advance `slow` +1 / `fast` +2 to middle.
2. Reverse list from `slow` onward.
3. Walk `p1` from head and `p2` from reversed head; any mismatch → false.

## 6. Dry Run
`1→2→2→1`: mid at second `2`; reverse → `1→2`; compare with first half → match → `true`.
`1→2→3`: reverse second half `3→2`; compare `1` vs `3` → `false`.

## 7. Time & Space Complexity
Time **O(N)**. Space **O(1)**. Why: constant pointers only (section 4).

## 8. Trade-offs & Alternatives
Array copy is simpler under time pressure; mid-reverse is the O(1)-space expectation.

## 9. Common Mistakes / Edge Cases
Wrong middle on even length; forgetting to stop compare when second half ends; null-deref on reverse.

## 10. Interview Follow-ups / Variations
Restore list after check; palindrome doubly linked list; reorder list reuses mid+reverse.

## 11. Tags
`linked-list`, `fast-slow-pointers`, `two-pointers`, `leetcode-234`, `difficulty:easy`
