# Coin Change

## Problem Statement
[LeetCode 322](https://leetcode.com/problems/coin-change/) — fewest coins to make `amount`; unlimited each denomination; `-1` if impossible.

- **Inputs:** `vector<int> coins`, `int amount`.
- **Output:** min coin count or `-1`.
- **Valid answer:** any optimal count (coins themselves not required).
- **Edges:** `amount=0` → 0; no combination; coin > amount.

## Intuition
`dp[x] = min over coins c of dp[x-c] + 1` (when `x>=c`). Unbounded knapsack for min count.

## Brute Force → Optimal
- **Brute:** recurse remaining amount — exponential.
- **Optimal:** bottom-up DP — O(amount · N).

## Data Structure / Approach Justification
**Chosen:** `dp[0..amount]` with sentinel `amount+1` for unreachable.

- **vs BFS by coin-count layers:** also O(amount · N); natural for “shortest path”.
- **vs greedy largest-first:** wrong for arbitrary coin systems.

## Logic Walkthrough
`dp[0]=0`, others sentinel. For each amount `x`, try every coin. If final > amount → `-1`.

## Dry Run
`coins=[1,2,5]`, `amount=11`:
- builds up to `dp[11]=3` via `5+5+1`

## Time & Space Complexity
Time **O(amount · N)**. Space **O(amount)**. Why: fill each amount from all coins (section 4).

## Trade-offs & Alternatives
DFS+memo same asymptotics. BFS useful when framing as shortest path in amount space.

## Common Mistakes / Edge Cases
Greedy; sentinel overflow; forgetting `amount=0`.

## Interview Follow-ups / Variations
Number of combinations (518); limited coin counts.

## Tags
`1d-dp`, `unbounded-knapsack`, `leetcode-322`, `difficulty:medium`
