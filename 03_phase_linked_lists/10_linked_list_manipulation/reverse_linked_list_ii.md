# Reverse Linked List II

## 1. Problem Statement
[LeetCode 92](https://leetcode.com/problems/reverse-linked-list-ii/) — reverse the portion of a singly linked list from position `left` to `right` (1-indexed inclusive); return the head.

- **Inputs:** `head`, integers `left ≤ right`.
- **Output:** head after partial reverse.
- **Valid answer:** only the `[left,right]` sublist reversed; outside nodes unchanged.
- **Edges:** `left == right`; reverse from head (`left == 1`); reverse to tail; full list.

## 2. Intuition
Walk to the node before `left`, then repeatedly cut the next node out of the remaining sublist and insert it right after that predecessor (head-insert into the window).

## 3. Brute Force → Optimal
- **Brute:** dump to array, reverse slice, rewrite — O(N) space.
- **Optimal:** one-pass head-insertion into the window — O(1) extra.

## 4. Data Structure / Approach Justification
**Chosen:** dummy + `before` pointer; iterative head-insert for `right-left` steps.

| Alternative | Why we skip it here |
|-------------|---------------------|
| Reverse full segment then reattach | Extra bookkeeping for segment ends |
| Recursion | Harder to bound the window cleanly |

## 5. Logic Walkthrough
1. Dummy → head; advance `before` to node before `left`.
2. `curr = before->next` (stays as the original left node / growing tail of reversed window).
3. Repeat `right-left` times: take `move = curr->next`, splice `move` after `before`.
4. Return `dummy.next`.

## 6. Dry Run
`1→2→3→4→5`, `left=2`, `right=4`: `before` on `1`; after inserts → `1→4→3→2→5`.

## 7. Time & Space Complexity
- **Time:** O(N)
- **Space:** O(1)

## 8. Trade-offs & Alternatives
Segment reverse + reconnect is clearer for some; head-insert is a single tight loop once `before` is found.

## 9. Common Mistakes / Edge Cases
Off-by-one on `left`/`right`; forgetting dummy when `left=1`; moving `curr` incorrectly so the window breaks.

## 10. Interview Follow-ups / Variations
Full reverse (LC 206); k-group reverse (LC 25); reverse every other sublist.

## 11. Tags
`linked-list`, `reverse`, `dummy-node`, `leetcode-92`, `difficulty:medium`
