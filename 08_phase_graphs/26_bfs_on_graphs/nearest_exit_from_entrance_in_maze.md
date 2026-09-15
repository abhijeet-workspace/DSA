# Nearest Exit from Entrance in Maze

## 1. Problem Statement
[LeetCode 1926](https://leetcode.com/problems/nearest-exit-from-entrance-in-maze/) — maze of empty `'.'` and walls `'+'`. Start at `entrance` (empty). An exit is any empty cell on the border **other than** the entrance. Return minimum steps to an exit, or `-1`.

- **Inputs:** `maze`, `entrance`.
- **Output:** min steps.
- **Valid answer:** BFS distance to nearest border empty ≠ entrance.
- **Edges:** entrance on border but not counting itself; blocked maze.

## 2. Intuition
BFS from entrance through empty cells; first time you reach a border cell (not start), that distance is answer.

## 3. Brute Force → Optimal
- **Brute:** DFS all paths — not minimal.
- **Optimal:** BFS O(RC).

## 4. Data Structure / Approach Justification
**Chosen:** level-order BFS mutating visited to `'+'`.

- **vs 0-1 BFS:** unnecessary.

## 5. Logic Walkthrough
Mark entrance visited. BFS neighbors; if neighbor on border, return dist+1; else enqueue.

## 6. Dry Run
Sample → nearest exit in **1** step.

## 7. Time & Space Complexity
Time **O(RC)**. Space **O(RC)**. Why: each cell once (section 4).

## 8. Trade-offs & Alternatives
Keep separate visited if maze must stay immutable.

## 9. Common Mistakes / Edge Cases
Returning 0 when entrance is on border; walking through walls; off-by-one distance.

## 10. Interview Follow-ups / Variations
Shortest path to multiple exits; with keys/doors.

## 11. Tags
`bfs`, `maze`, `leetcode-1926`, `difficulty:medium`
