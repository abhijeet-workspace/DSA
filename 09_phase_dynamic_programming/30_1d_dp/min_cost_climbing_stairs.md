# Min Cost Climbing Stairs

## Problem Statement
[LeetCode 746](https://leetcode.com/problems/min-cost-climbing-stairs/) — pay `cost[i]` to leave stair `i`; may start at 0 or 1; reach top (past last stair) with minimum total cost.

- **Inputs:** `vector<int> cost`.
- **Output:** min total payment.
- **Valid answer:** min over all valid climb sequences.
- **Edges:** length 2; zeros; increasing costs.

## Intuition
To stand at top index `n`, you arrived by paying to leave `n-1` or `n-2`. Recurrence mirrors climbing stairs with costs.

## Brute Force → Optimal
- **Brute:** recurse all paths — exponential.
- **Optimal:** rolling DP — O(N)/O(1).

## Data Structure / Approach Justification
**Chosen:** two rolling costs `a,b` for positions `i-2` and `i-1`.

- **vs full `dp[]`:** same idea, more memory.
- **vs modify `cost` in place:** saves allocation but mutates input.

## Logic Walkthrough
`a=b=0`. For `i=2..n`: `c = min(a+cost[i-2], b+cost[i-1])`, shift. Return `b`.

## Dry Run
`cost=[10,15,20]`:
- i=2 → min(0+10, 0+15)=10
- i=3 (top) → min(0+15, 10+20)=15

## Time & Space Complexity
Time **O(N)**. Space **O(1)**. Why: one pass, two scalars (section 4).

## Trade-offs & Alternatives
O(1) space once recurrence is clear. In-place mutate is fine if allowed.

## Common Mistakes / Edge Cases
Forgetting free start at 0 or 1; off-by-one on top index; treating cost of top as required.

## Interview Follow-ups / Variations
Climbing Stairs (70); house robber-style adjacent constraints.

## Tags
`1d-dp`, `min-cost`, `leetcode-746`, `difficulty:easy`
