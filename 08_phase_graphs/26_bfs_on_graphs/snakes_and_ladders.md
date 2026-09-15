# Snakes and Ladders

## 1. Problem Statement
[LeetCode 909](https://leetcode.com/problems/snakes-and-ladders/) — n×n board labeled 1..n² in boustrophedon order. `-1` is normal; otherwise teleport to that label. From square `x`, roll 1..6. Return minimum moves to n², or `-1`.

- **Inputs:** `board`.
- **Output:** min dice rolls.
- **Valid answer:** shortest path in square graph with forced teleports.
- **Edges:** no snakes/ladders; immediate win; impossible.

## 2. Intuition
BFS on squares 1..n². Edges to `cur+1..cur+6` (then apply board teleport). First time reaching n² is minimum rolls.

## 3. Brute Force → Optimal
- **Brute:** DFS with cycles — wrong/slow.
- **Optimal:** BFS O(n²).

## 4. Data Structure / Approach Justification
**Chosen:** BFS + label↔(r,c) mapping.

- **vs Dijkstra:** unnecessary (unit weights).

## 5. Logic Walkthrough
Map id to board cell (zigzag). BFS; when landing, follow snake/ladder once.

## 6. Dry Run
LC sample → **4** moves.

## 7. Time & Space Complexity
Time **O(n²)**. Space **O(n²)**. Why: each square once (section 4).

## 8. Trade-offs & Alternatives
Careful: do not chain teleports beyond one board value (per problem).

## 9. Common Mistakes / Edge Cases
Wrong zigzag mapping; revisiting squares; treating teleport as optional.

## 10. Interview Follow-ups / Variations
Minimum snakes to add; probability of winning.

## 11. Tags
`bfs`, `matrix`, `leetcode-909`, `difficulty:medium`
