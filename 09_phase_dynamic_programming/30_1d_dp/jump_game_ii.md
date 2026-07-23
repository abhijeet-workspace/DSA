# Jump Game II

## Problem Statement
[LeetCode 45](https://leetcode.com/problems/jump-game-ii/) — minimum number of jumps to reach the last index (guaranteed reachable).

- **Inputs:** `vector<int> nums`.
- **Output:** min jump count.
- **Valid answer:** smallest jump sequence length.
- **Edges:** already at end (`n=1` → 0); jump covers entire array.

## Intuition
Treat the array as BFS layers: within the current jump window, track farthest; when window ends, take one jump and open a new window.

## Brute Force → Optimal
- **Brute / DP:** `dp[i] = 1 + min dp over reachers` — O(N²).
- **Optimal:** greedy BFS layers — O(N).

## Data Structure / Approach Justification
**Chosen:** `jumps`, `end` (window end), `far` (farthest in window).

- **vs O(N²) DP:** correct but slower; interviews expect greedy.
- **vs explicit queue BFS:** same idea, heavier constants.

## Logic Walkthrough
Scan `i` to `n-2`. Update `far`. When `i == end`, `++jumps`, set `end = far`.

## Dry Run
`[2,3,1,1,4]`:
- i=0: far=2, end→2, jumps=1
- i=1..2: far=4, at i=2 end→4, jumps=2 → done

## Time & Space Complexity
Time **O(N)**. Space **O(1)**. Why: one forward pass (section 4).

## Trade-offs & Alternatives
Greedy needs “always reachable” guarantee. Classic DP is clearer but O(N²).

## Common Mistakes / Edge Cases
Looping to `n-1` (extra jump); not updating `far` before extending window.

## Interview Follow-ups / Variations
Reachability only (55); hard variants with costs.

## Tags
`greedy`, `bfs-on-array`, `jump-game`, `leetcode-45`, `difficulty:medium`
