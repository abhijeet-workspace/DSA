# Sort List

## 1. Problem Statement
[LeetCode 148](https://leetcode.com/problems/sort-list/) — given the head of a singly linked list, return the list sorted in ascending order.

- **Inputs:** `ListNode* head`.
- **Output:** head of sorted list (nodes reused).
- **Valid answer:** nondecreasing values along `next` links.
- **Edges:** empty; one node; already sorted; reverse order; duplicates.

## 2. Intuition
Array merge sort needs random access; on lists, merge is natural O(1) link splicing. Bottom-up merge sort doubles run length each pass for O(1) extra space.

## 3. Brute Force → Optimal
- **Brute:** copy values to array, sort, rewrite — O(N log N) time, O(N) space.
- **Optimal:** linked-list merge sort — O(N log N) time, O(1) extra (bottom-up) or O(log N) recursion stack (top-down).

## 4. Data Structure / Approach Justification
**Chosen:** bottom-up merge sort with `split` + `merge` helpers.

| Alternative | Why we skip it here |
|-------------|---------------------|
| Top-down (mid via slow/fast) | Clean but O(log N) stack |
| Array sort rewrite | Uses O(N) memory; misses list skill |

## 5. Logic Walkthrough
1. Count `n`.
2. For `size = 1, 2, 4, …`: walk the list in pairs of runs of length `size`.
3. `split` severs a run; `merge` splices two sorted runs; attach after `prev`.
4. Return `dummy.next`.

## 6. Dry Run
`4→2→1→3`, size 1 merges → `2→4→1→3`, size 2 merges → `1→2→3→4`.

## 7. Time & Space Complexity
- **Time:** O(N log N) — log N passes × O(N) merge work.
- **Space:** O(1) extra pointers (bottom-up).

## 8. Trade-offs & Alternatives
Top-down is easier to code; bottom-up meets strict O(1) space. Prefer array sort only when memory is free and simplicity wins.

## 9. Common Mistakes / Edge Cases
Forgetting to null-terminate after `split`; losing the next-pair pointer before merge; not advancing `prev` to the merged run's tail; empty second half.

## 10. Interview Follow-ups / Variations
Top-down with slow/fast mid; sort doubly linked list; insertion sort on nearly sorted list.

## 11. Tags
`sorting`, `linked-list`, `merge-sort`, `leetcode-148`, `difficulty:medium`
