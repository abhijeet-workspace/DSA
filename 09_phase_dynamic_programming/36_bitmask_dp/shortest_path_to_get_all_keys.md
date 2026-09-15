# Shortest Path to Get All Keys

## Problem Statement
[LeetCode 864](https://leetcode.com/problems/shortest-path-to-get-all-keys/) — grid with keys/locks; shortest path to collect all keys.

- **Inputs:** `grid` strings.
- **Output:** min steps or -1.
- **Valid answer:** BFS (r,c,keymask).
- **Edges:** unreachable; start on key.

## Intuition
State includes key bitmask; locks need matching key bit.

## Brute Force → Optimal
- **Brute:** search without mask fails.
- **Optimal:** BFS O(R*C*2^K).

## Data Structure / Approach Justification
**Chosen:** queue + seen[r][c][mask].

## Logic Walkthrough
@ start; a-f keys; A-F locks; # wall.

## Dry Run
Sample -> **8**.

## Time & Space Complexity
Time **O(R*C*2^K)**. Space same. Why: states (section 4).

## Trade-offs & Alternatives
K<=6.

## Common Mistakes / Edge Cases
Passing lock without key; not tracking keys.

## Interview Follow-ups / Variations
Shortest Path Visiting All Nodes.

## Tags
`bitmask-dp`, `bfs`, `leetcode-864`, `difficulty:hard`
