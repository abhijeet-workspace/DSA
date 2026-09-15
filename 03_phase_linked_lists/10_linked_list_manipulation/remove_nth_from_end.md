# Remove Nth Node From End of List

## 1. Problem Statement
[LeetCode 19](https://leetcode.com/problems/remove-nth-node-from-end-of-list/) — remove the nth node from the end of a singly linked list; return the new head.

- **Inputs:** `head`, positive `n` (1-indexed from end).
- **Output:** new head after deletion.
- **Valid answer:** list with that node removed; others unchanged order.
- **Edges:** remove head (`n == length`); remove tail (`n == 1`); single node.

## 2. Intuition
Keep a fixed gap of `n` between two pointers so when the lead hits null, the trail sits just before the delete target. Dummy handles head deletion.

## 3. Brute Force → Optimal
- **Brute:** count length, remove `(L-n+1)`th — two passes.
- **Optimal:** one-pass gap of `n` from dummy — O(N).

## 4. Data Structure / Approach Justification
**Chosen:** dummy + two pointers with lead of `n+1` steps from dummy.

| Alternative | Why we skip it here |
|-------------|---------------------|
| Two-pass length | Same time, two traversals |
| Recursion depth counter | O(N) stack |

## 5. Logic Walkthrough
1. Advance `first` `n+1` times from `dummy`.
2. Move `first`/`second` until `first` is null.
3. Bypass `second->next` (victim); return `dummy.next`.

## 6. Dry Run
`1→2→3→4→5`, `n=2`: after gap, joint walk ends with `second` at `3`; delete `4` → `1→2→3→5`.

## 7. Time & Space Complexity
- **Time:** O(N)
- **Space:** O(1)

## 8. Trade-offs & Alternatives
Two-pass is less error-prone on off-by-one; one-pass is the classic interview version.

## 9. Common Mistakes / Edge Cases
Off-by-one (`n` vs `n+1` from dummy); forgetting dummy when deleting head; not freeing the node.

## 10. Interview Follow-ups / Variations
Return nth from end without delete; remove every nth; doubly linked delete.

## 11. Tags
`linked-list`, `two-pointers`, `dummy-node`, `leetcode-19`, `difficulty:medium`
