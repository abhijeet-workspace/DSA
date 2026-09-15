# Vertical Order Traversal of a Binary Tree

## Problem Statement
[LeetCode 987](https://leetcode.com/problems/vertical-order-traversal-of-a-binary-tree/) — report node values by vertical column left→right; within column by row top→bottom; ties by value ascending.

- **Inputs:** binary tree root.
- **Output:** `vector<vector<int>>` columns.
- **Valid answer:** col = parent±1; row increases downward.
- **Edges:** skewed tree; same (row,col) nodes.

## Intuition
Assign (row,col) coordinates; bucket by col; sort each bucket by (row,val).

## Brute Force → Optimal
- **Brute:** collect triples then global sort — O(N log N).
- **Optimal same class:** BFS + `map<col, multiset<(row,val)>>`.

## Data Structure / Approach Justification
**Chosen:** `map` for ordered columns + `multiset` for ordered cells.

- **vs unordered + sort keys:** similar asymptotics.

## Logic Walkthrough
BFS with coordinates; insert into col multiset; emit columns in map order.

## Dry Run
Root col0; 9 at -1; 20 at +1; 15 at 0 → column 0 is `3,15`.

## Time & Space Complexity
Time **O(N log N)**. Space **O(N)**.

## Trade-offs & Alternatives
LC 314 Vertical Order (no value tie-break) uses pure BFS queues.

## Common Mistakes / Edge Cases
Wrong tie-break (position vs value); swapping row/col.

## Interview Follow-ups / Variations
Binary Tree Vertical Order Traversal (314).

## Tags
`tree`, `bfs`, `hash-map`, `leetcode-987`, `difficulty:hard`
