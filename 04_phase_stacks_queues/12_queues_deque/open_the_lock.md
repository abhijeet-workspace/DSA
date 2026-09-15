# Open the Lock

## 1. Problem Statement
[LeetCode 752](https://leetcode.com/problems/open-the-lock/) — 4-wheel lock `'0000'`–`'9999'`; each move turns one wheel ±1. Avoid `deadends`; return min moves to `target` or `-1`.

- **Inputs:** `deadends` list, `target` string.
- **Output:** shortest move count.
- **Edges:** target `0000`; start is dead; unreachable.

## 2. Intuition
Each state has 8 neighbors (4 wheels × 2 dirs). Unweighted graph → BFS from `"0000"`; queue holds states; set marks visited/dead.

## 3. Brute Force → Optimal
- **Brute:** DFS with pruning — can explode.
- **Optimal:** BFS — O(10⁴) states fixed.

## 4. Data Structure / Approach Justification
**Chosen:** `queue` for BFS + `unordered_set` visited.

| Alternative | Note |
|-------------|------|
| Bidirectional BFS | Faster constants for large graphs |
| A* / Dijkstra | Unnecessary — unit weights |

## 5. Logic Walkthrough
1. Insert all deadends into visited; if start dead return -1.
2. BFS: for each state, generate 8 neighbors; skip visited; if neighbor==target return steps+1.
3. Exhaust queue → -1.

## 6. Dry Run
`deadends=["0201","0101","0102","1212","2002"]`, `target="0202"` → 6.

## 7. Time & Space Complexity
- **Time:** O(1) essentially — at most 10000 states × 8 edges
- **Space:** O(10000) visited + queue

## 8. Trade-offs & Alternatives
Bidirectional BFS from start and target when deadends are sparse.

## 9. Common Mistakes / Edge Cases
Not marking start visited; wrapping `'0'`↔`'9'`; treating deadends only at enqueue vs dequeue inconsistently.

## 10. Interview Follow-ups / Variations
Word ladder; walls and gates; perfect squares (BFS on remainders).

## 11. Tags
`queue`, `bfs`, `leetcode-752`, `difficulty:medium`
