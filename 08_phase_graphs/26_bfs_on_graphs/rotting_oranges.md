# Rotting Oranges

## 1. Problem Statement
[LeetCode 994](https://leetcode.com/problems/rotting-oranges/) — grid cells: `0` empty, `1` fresh, `2` rotten. Each minute, rotten oranges infect 4-adjacent fresh ones. Return minutes to rot all, or `-1` if impossible.

- **Inputs:** `grid[m][n]`.
- **Output:** minutes or `-1`.
- **Valid answer:** minimum simultaneous infection time.
- **Edges:** no fresh → `0`; unreachable fresh → `-1`.

## 2. Intuition
All initially rotten oranges infect in parallel → multi-source BFS; each queue layer is one minute.

## 3. Brute Force → Optimal
- **Brute:** simulate scans until stable — up to **O((MN)²)**.
- **Optimal:** one multi-source BFS — **O(MN)**.

## 4. Data Structure / Approach Justification
**Chosen:** queue of rotten cells + fresh counter.

- **vs repeated full-grid sweeps:** slower and messier.
- **vs DFS:** wrong for simultaneous “time” layers.

## 5. Logic Walkthrough
Enqueue all `2`s, count `1`s. While queue and fresh remain: process layer, infect neighbors, `--fresh`. Return minutes if fresh hit 0 else `-1`.

## 6. Dry Run
Sample 3×3 needs 4 minutes; last fresh at bottom-right infects last.

## 7. Time & Space Complexity
Time **O(MN)**. Space **O(MN)** queue. Why: each cell enqueued ≤1 (section 4).

## 8. Trade-offs & Alternatives
Same template as 01 Matrix / walls and gates. Mutating grid avoids a visited matrix.

## 9. Common Mistakes / Edge Cases
Incrementing minutes when queue empty leftover; forgetting `fresh==0` early return; diagonal infection.

## 10. Interview Follow-ups / Variations
Fire spread; zombie infection; gates and walls distance.

## 11. Tags
`grid`, `bfs`, `multi-source`, `leetcode-994`, `difficulty:medium`
