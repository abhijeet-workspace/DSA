# Remove Nth Node From End of List

## 1. Problem Statement
[LeetCode 19](https://leetcode.com/problems/remove-nth-node-from-end-of-list/) — remove the nth node from the end of a singly linked list; return the new head.

- **Inputs:** `ListNode* head`, integer `n` (1-indexed from the end).
- **Output:** new head after deletion.
- **Valid answer:** list with that node bypassed.
- **Edges:** remove head; remove last; single-node list; `n = length`.

## 2. Intuition
Keep two pointers a fixed gap of `n` apart. When the leader hits null, the trailer sits just before the victim.

## 3. Brute Force → Optimal
- **Brute:** count length, then walk `length - n` — two passes.
- **Optimal:** gap two-pointers in one pass (dummy head for head deletion).

## 4. Data Structure / Approach Justification
**Chosen:** dummy + leading/trailing pointers distance `n`.

- **vs count then index:** extra full pass; same asymptotics.
- **vs store in array:** O(N) space unnecessary.

## 5. Logic Walkthrough
1. Dummy → head. Advance `first` `n + 1` steps from dummy.
2. Move `first` and `second` together until `first` is null.
3. Bypass `second->next`; return `dummy.next`.

## 6. Dry Run
`1→2→3→4→5`, `n = 2`: after lead, gap holds; stop with `second` on `3`; delete `4` → `1→2→3→5`.

## 7. Time & Space Complexity
Time **O(N)**. Space **O(1)**. Why: one traversal, constant pointers (section 4).

## 8. Trade-offs & Alternatives
Two-pass length count is clearer for beginners; gap pointers are interview-standard.

## 9. Common Mistakes / Edge Cases
Off-by-one on gap (`n` vs `n+1` from dummy); forgetting dummy when deleting head; not freeing node in C++.

## 10. Interview Follow-ups / Variations
Remove from front; find kth from end without delete; rotate list (related gap idea).

## 11. Tags
`linked-list`, `two-pointers`, `fast-slow-pointers`, `leetcode-19`, `difficulty:medium`
