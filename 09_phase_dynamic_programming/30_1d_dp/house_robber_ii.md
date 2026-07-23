# House Robber II

## Problem Statement
[LeetCode 213](https://leetcode.com/problems/house-robber-ii/) — houses on a circle (first and last adjacent); max loot with no two adjacent.

- **Inputs:** `vector<int> nums`.
- **Output:** max loot under circular constraint.
- **Valid answer:** max of valid circular selections.
- **Edges:** `n=1`; `n=2`; all equal.

## Intuition
Cannot take both ends → answer = max(linear rob `[0..n-2]`, linear rob `[1..n-1]`).

## Brute Force → Optimal
- **Brute:** all valid circular subsets — exponential.
- **Optimal:** two House Robber I passes — O(N).

## Data Structure / Approach Justification
**Chosen:** reuse linear `robLinear` on two ranges.

- **vs state machine with “robbed first” flag:** same complexity, more states to track.
- **vs one pass on full circle:** incorrect — ignores wrap adjacency.

## Logic Walkthrough
`n==1` → `nums[0]`. Else return `max(robLinear(0,n-2), robLinear(1,n-1))`.

## Dry Run
`[2,3,2]`:
- rob `[2,3]` → 3; rob `[3,2]` → 3 → answer 3
`[1,2,3,1]`:
- rob `[1,2,3]` → 4; rob `[2,3,1]` → 4 → answer 4

## Time & Space Complexity
Time **O(N)**. Space **O(1)**. Why: two linear scans (section 4).

## Trade-offs & Alternatives
Helper reuse keeps code short. Explicit circular DP states work but are harder to get right.

## Common Mistakes / Edge Cases
Running one linear pass on the full array; forgetting `n=1`.

## Interview Follow-ups / Variations
House Robber III on trees (337).

## Tags
`1d-dp`, `circular`, `house-robber`, `leetcode-213`, `difficulty:medium`
