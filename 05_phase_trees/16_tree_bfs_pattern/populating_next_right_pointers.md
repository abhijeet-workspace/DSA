# Populating Next Right Pointers in Each Node

## 1. Problem Statement
[LeetCode 116](https://leetcode.com/problems/populating-next-right-pointers-in-each-node/) — perfect binary tree; populate each node’s `next` to its right neighbor (null at level end).

- **Inputs:** `Node* root` with `left/right/next`.
- **Output:** same tree with `next` links.
- **Valid answer:** level-order linked lists.
- **Edges:** empty; single node; full perfect tree.

## 2. Intuition
BFS by level, or use existing `next` of parents to wire children without a queue: `left->next = right`, `right->next = parent->next->left`.

## 3. Brute Force → Optimal
- **Brute:** BFS queue storing level — O(N) time, O(W) space.
- **Optimal:** level pointers using `next` — O(N) time, O(1) extra.

## 4. Data Structure / Approach Justification
**Chosen:** BFS with level size (clear and correct; works similarly for 117).

| Alternative | Why it loses here |
|-------------|-------------------|
| O(1) parent wiring | Slightly trickier; interview bonus |
| DFS | Need care to set left before using parent next |

## 5. Logic Walkthrough
1. Queue root.
2. For each level, previous node’s `next = current`; last gets null.
3. Enqueue children.

## 6. Dry Run
Perfect `[1,2,3,4,5,6,7]`: 2→3, 4→5→6→7.

## 7. Time & Space Complexity
- **Time:** O(N)
- **Space:** O(W) queue (O(1) with pointer climb)
- Why: each node linked once.

## 8. Trade-offs & Alternatives
LC 117 (non-perfect) needs scanning for next non-null child — same BFS still works.

## 9. Common Mistakes / Edge Cases
Forgetting to null-terminate; wiring across levels; assuming non-perfect input for 116 tricks.

## 10. Interview Follow-ups / Variations
Populating Next Right II (117); flatten to list.

## 11. Tags
`binary-tree`, `bfs`, `linked-list`, `leetcode-116`, `difficulty:medium`
