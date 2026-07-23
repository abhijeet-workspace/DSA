# Remove Nth Node From End of List

## Problem Statement
[LeetCode 19](https://leetcode.com/problems/remove-nth-node-from-end-of-list/) — remove the nth node from the end of a singly linked list; return the new head.

- **Inputs:** `head`, positive `n` (1-indexed from end).
- **Output:** new head after deletion.
- **Valid answer:** list with that node removed; others unchanged order.
- **Edges:** remove head (`n == length`); remove tail (`n == 1`); single node.

## Intuition
Keep a fixed gap of `n` between two pointers so when the lead hits null, the trail sits just before the delete target. Dummy handles head deletion.

## Brute Force → Optimal
- **Brute:** count length, remove `(L-n+1)`th — two passes.
- **Optimal:** one-pass gap of `n` from dummy — O(N).

## Data Structure / Approach Justification
**Chosen:** dummy + two pointers with lead of `n+1` steps from dummy.

- **vs two-pass length:** same time, two traversals.
- **vs recursion depth counter:** O(N) stack.

## Logic Walkthrough
Advance `first` `n+1` times from `dummy`. Move `first`/`second` until `first` is null. `second->next` is the victim; bypass and delete it. Return `dummy.next`.

## Dry Run
`1→2→3→4→5`, `n=2`: after gap, joint walk ends with `second` at `3`; delete `4` → `1→2→3→5`.

## Time & Space Complexity
Time **O(N)**. Space **O(1)**. Why: one traversal with constant pointers (section 4).

## Trade-offs & Alternatives
Two-pass is less error-prone on off-by-one; one-pass is the classic interview version.

## Common Mistakes / Edge Cases
Off-by-one (`n` vs `n+1` from dummy); forgetting dummy when deleting head; not freeing the node.

## Interview Follow-ups / Variations
Return nth from end without delete; remove every nth; doubly linked delete.

## Tags
`linked-list`, `two-pointers`, `dummy-node`, `difficulty:medium`
