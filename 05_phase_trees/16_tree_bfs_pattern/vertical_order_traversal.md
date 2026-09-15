# Vertical Order Traversal of a Binary Tree

## 1. Problem Statement
[LeetCode 987](https://leetcode.com/problems/vertical-order-traversal-of-a-binary-tree/) — report node values by vertical column left→right; within column by row top→bottom; ties by value ascending.

- **Inputs:** binary tree root.
- **Output:** `vector<vector<int>>` columns.
- **Valid answer:** col = parent±1; row increases downward.
- **Edges:** skewed tree; same (row,col) nodes.

## 2. Intuition
Assign (row,col) coordinates; bucket by col; sort each bucket by (row,val).

## 3. Brute Force → Optimal
- **Brute:** collect triples then global sort — O(N log N).
- **Optimal same class:** BFS + `map<col, multiset<(row,val)>>`.

## 4. Data Structure / Approach Justification
**Chosen:** `map` for ordered columns + `multiset` for ordered cells.

- **vs unordered + sort keys:** similar asymptotics.

## 5. Logic Walkthrough
BFS with coordinates; insert into col multiset; emit columns in map order.

## 6. Dry Run
Root col0; 9 at -1; 20 at +1; 15 at 0 → column 0 is `3,15`.

## 7. Time & Space Complexity
Time **O(N log N)**. Space **O(N)**.

## 8. Trade-offs & Alternatives
LC 314 Vertical Order (no value tie-break) uses pure BFS queues.

## 9. Common Mistakes / Edge Cases
Wrong tie-break (position vs value); swapping row/col.

## 10. Interview Follow-ups / Variations
Binary Tree Vertical Order Traversal (314).

## 11. Tags
`tree`, `bfs`, `hash-map`, `leetcode-987`, `difficulty:hard`
