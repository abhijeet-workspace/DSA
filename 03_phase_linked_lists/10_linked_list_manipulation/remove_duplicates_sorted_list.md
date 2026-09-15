# Remove Duplicates from Sorted List

## 1. Problem Statement
[LeetCode 83](https://leetcode.com/problems/remove-duplicates-from-sorted-list/) — given a sorted singly linked list, delete all duplicate values so each distinct number appears once; return the head.

- **Inputs:** sorted `ListNode* head` (non-decreasing).
- **Output:** head of deduplicated list.
- **Valid answer:** first occurrence of each value kept; relative order preserved.
- **Edges:** empty; all unique; all equal; runs of length ≥ 3.

## 2. Intuition
Because the list is sorted, duplicates are adjacent — walk and skip `next` while equal to `curr`.

## 3. Brute Force → Optimal
- **Brute:** hash set of seen values on unsorted logic — unnecessary given sorted order.
- **Optimal:** single pointer skip of equal neighbors — O(N), O(1).

## 4. Data Structure / Approach Justification
**Chosen:** one `curr` pointer; unlink and free when `curr->val == curr->next->val`.

| Alternative | Why we skip it here |
|-------------|---------------------|
| Hash set | Overkill; sorted adjacency suffices |
| Two-pointer write like arrays | Same idea; list needs unlink not overwrite |

## 5. Logic Walkthrough
1. `curr = head`.
2. While `curr` and `curr->next`: if equal, bypass `curr->next`; else advance `curr`.
3. Return `head`.

## 6. Dry Run
`1→1→2→3→3`: skip first dup → `1→2→3→3`; skip last → `1→2→3`.

## 7. Time & Space Complexity
- **Time:** O(N)
- **Space:** O(1)

## 8. Trade-offs & Alternatives
LC 82 removes *all* nodes of duplicated values (keep none) — different unlink rule.

## 9. Common Mistakes / Edge Cases
Advancing after skip (misses triple runs); freeing without updating `next`; unsorted input assumption.

## 10. Interview Follow-ups / Variations
Remove all duplicates (LC 82); remove elements equal to `val` (LC 203); unique on unsorted list.

## 11. Tags
`linked-list`, `sorted`, `dedup`, `leetcode-83`, `difficulty:easy`
