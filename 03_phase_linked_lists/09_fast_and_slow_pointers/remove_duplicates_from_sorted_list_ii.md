# Remove Duplicates from Sorted List II

## 1. Problem Statement
[LeetCode 82](https://leetcode.com/problems/remove-duplicates-from-sorted-list-ii/) — given a sorted linked list, delete all nodes that have duplicate numbers, leaving only distinct numbers.

- **Inputs:** sorted `ListNode* head`.
- **Output:** new head with all duplicate values removed entirely.
- **Valid answer:** only values that appeared once remain, sorted.
- **Edges:** all duplicates; no duplicates; duplicates at head; empty.

## 2. Intuition
Dummy predecessor walks groups: if a run length &gt; 1, skip the whole run; else keep the unique node.

## 3. Brute Force → Optimal
- **Brute:** count frequencies then rebuild — O(N) space.
- **Optimal:** one-pass dummy + runner on sorted runs — O(1) space.

## 4. Data Structure / Approach Justification
**Chosen:** dummy + adjacent two-pointer scan of equal runs.

- **vs hash counts:** unnecessary given sorted order.
- **vs LC 83 (keep one):** different — here remove all copies of duplicated values.

## 5. Logic Walkthrough
While `prev->next`: set `curr = prev->next`. If `curr->next` shares value, advance while equal and set `prev->next` past the run; else `prev = curr`.

## 6. Dry Run
`1→2→3→3→4→4→5`: skip both `3`s and both `4`s → `1→2→5`.

## 7. Time & Space Complexity
Time **O(N)**. Space **O(1)**. Why: each node visited once (section 4).

## 8. Trade-offs & Alternatives
Frequency map works on unsorted lists; sorted property enables O(1) space.

## 9. Common Mistakes / Edge Cases
Keeping one copy (LC 83 habit); losing dummy when head is duplicated; infinite loop if not advancing past the run.

## 10. Interview Follow-ups / Variations
Remove duplicates I (keep one); delete nodes by value; sort then unique.

## 11. Tags
`linked-list`, `two-pointers`, `leetcode-82`, `difficulty:medium`
