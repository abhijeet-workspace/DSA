# Even Odd Tree

## 1. Problem Statement
[LeetCode 1609](https://leetcode.com/problems/even-odd-tree/) — check even-odd level constraints: even levels strictly increasing odd values; odd levels strictly decreasing even values. Root level is 0.

- **Inputs:** `TreeNode* root`.
- **Output:** `bool`.
- **Valid answer:** all level rules hold.
- **Edges:** single odd root; equal neighbors; wrong parity.

## 2. Intuition
BFS with level index; validate parity and monotonicity against previous value on the level.

## 3. Brute Force → Optimal
- **Brute:** materialize levels then check.
- **Optimal:** check online in BFS — O(N).

## 4. Data Structure / Approach Justification
**Chosen:** BFS with `level` parity and `prev` sentinel.

| Alternative | Why it loses here |
|-------------|-------------------|
| DFS | Harder to compare left-to-right order |

## 5. Logic Walkthrough
1. Even level: val odd and `val > prev`.
2. Odd level: val even and `val < prev`.
3. Update prev; enqueue children.

## 6. Dry Run
`[1,10,4,3,null,7,9,12,8,6,null,null,2]` → true on LC sample.

## 7. Time & Space Complexity
- **Time:** O(N)
- **Space:** O(W)
- Why: one pass validation.

## 8. Trade-offs & Alternatives
Use `INT_MIN`/`INT_MAX` sentinels carefully for first element.

## 9. Common Mistakes / Edge Cases
Wrong root parity; non-strict compare; level index off-by-one.

## 10. Interview Follow-ups / Variations
Validate BST; even-odd linked list.

## 11. Tags
`binary-tree`, `bfs`, `leetcode-1609`, `difficulty:medium`
