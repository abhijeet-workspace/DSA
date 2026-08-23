# Capacity To Ship Packages Within D Days

## Problem Statement
[LeetCode 1011](https://leetcode.com/problems/capacity-to-ship-packages-within-d-days/) — packages must stay in order; return the minimum ship capacity to finish in `days` days.

- **Inputs:** `weights`, `days`.
- **Output:** `int` capacity.
- **Valid answer:** smallest feasible capacity.
- **Edges:** days = n (capacity = max weight); days = 1 (capacity = sum).

## Intuition
Feasibility is monotone in capacity. Search `[max(weight), sum]`.

## Brute Force → Optimal
- **Brute:** try every capacity — O(sum · N).
- **Optimal:** binary search on answer — O(N log sum).

## Data Structure / Approach Justification
**Chosen:** minimize-the-maximum / Koko template.

- **vs split array largest sum (410):** same check, k splits instead of days
- **vs DP:** unnecessary once monotonicity is clear

## Logic Walkthrough
Greedy pack until cap would be exceeded, then a new day. If days needed ≤ D, try smaller cap.

## Dry Run
`[1..10]`, 5 days → 15.

## Time & Space Complexity
Time **O(N log S)** (S = sum). Space **O(1)**. Why: log capacities × linear pack.

## Trade-offs & Alternatives
Canonical search-on-answer problem in this study plan.

## Common Mistakes / Edge Cases
lo = 1 (cannot ship the heaviest); mutating order.

## Interview Follow-ups / Variations
Koko (875); split array largest sum (410).

## Tags
`binary-search`, `search-on-answer`, `leetcode-1011`, `difficulty:medium`
