# Jump Game III

## 1. Problem Statement
[LeetCode 1306](https://leetcode.com/problems/jump-game-iii/) — array `arr`. From index `start`, you may jump to `i + arr[i]` or `i - arr[i]` (in bounds). Return true if you can reach any index with value `0`.

- **Inputs:** `arr`, `start`.
- **Output:** bool.
- **Valid answer:** reachability in the jump graph.
- **Edges:** start already 0; cycles; out of bounds jumps.

## 2. Intuition
Treat indices as nodes with up to two outgoing edges. BFS/DFS from start with visited marking.

## 3. Brute Force → Optimal
- **Brute:** explore without visited — infinite loops.
- **Optimal:** BFS/DFS O(n) with visited.

## 4. Data Structure / Approach Justification
**Chosen:** BFS; mark visited by setting `arr[i]=-1`.

- **vs DFS recursion:** same; watch depth.
- **vs Union-Find:** less natural.

## 5. Logic Walkthrough
Queue start. Pop; if value 0 success. Else mark visited and enqueue valid ± jumps.

## 6. Dry Run
Sample from index 5 reaches 0 → true.

## 7. Time & Space Complexity
Time **O(n)**. Space **O(n)**. Why: each index once (section 4).

## 8. Trade-offs & Alternatives
Separate bool visited if input must be preserved.

## 9. Common Mistakes / Edge Cases
Not marking visited (cycles); allowing jump of 0 repeatedly without check; wrong bounds.

## 10. Interview Follow-ups / Variations
Jump Game I/II; minimum jumps to zero.

## 11. Tags
`bfs`, `array`, `leetcode-1306`, `difficulty:medium`
