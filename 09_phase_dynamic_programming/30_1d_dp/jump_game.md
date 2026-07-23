# Jump Game

## Problem Statement
[LeetCode 55](https://leetcode.com/problems/jump-game/) — from index 0, `nums[i]` is max jump length; return whether last index is reachable.

- **Inputs:** `vector<int> nums`.
- **Output:** `bool`.
- **Valid answer:** true iff some jump sequence reaches `n-1`.
- **Edges:** single element; zeros in middle; jump exactly to end.

## Intuition
Track farthest reachable index while scanning; if current `i` exceeds that, fail.

## Brute Force → Optimal
- **Brute:** DFS/BFS from each index — up to O(N²).
- **Optimal:** greedy max-reach scan — O(N).

## Data Structure / Approach Justification
**Chosen:** single `maxReach` scalar (greedy, not classic DP table).

- **vs boolean `reachable[]`:** O(N) space DP; same correctness.
- **vs checking only `nums[i]!=0`:** wrong — need cumulative reach.

## Logic Walkthrough
For each `i`: if `i > maxReach` return false; update `maxReach = max(maxReach, i+nums[i])`; early true if `maxReach >= n-1`.

## Dry Run
`[2,3,1,1,4]`: reach grows to end → true.
`[3,2,1,0,4]`: stuck at index 3 with reach 3 → false.

## Time & Space Complexity
Time **O(N)**. Space **O(1)**. Why: one pass maintains global reach (section 4).

## Trade-offs & Alternatives
Greedy is simplest correct approach. DP boolean array is more “DP-shaped” for teaching.

## Common Mistakes / Edge Cases
Not tracking cumulative reach; off-by-one on last index; empty not given.

## Interview Follow-ups / Variations
Min jumps (45); Jump Game III with teleports.

## Tags
`greedy`, `1d-dp`, `jump-game`, `leetcode-55`, `difficulty:medium`
