# Fractional Knapsack

## Problem Statement
Maximize total value under a weight capacity when **fractions** of items are allowed (classic greedy; contrast 0/1 knapsack).

- **Inputs:** items `(value, weight)`, capacity `W`.
- **Output:** max achievable value (double).
- **Valid answer:** may take a partial last item.
- **Edges:** capacity 0; item heavier than remaining capacity; single item.

## Intuition
Prefer highest value/weight ratio first. Take whole items while they fit; take a fraction of the next when capacity runs out.

## Brute Force → Optimal
- **Brute:** continuous fraction search — impractical.
- **Optimal:** sort by ratio descending — O(N log N).

## Data Structure / Approach Justification
**Chosen:** sort `(value, weight)` by `value/weight`, then scan.

- **vs 0/1 DP:** required when fractions are forbidden.
- **vs sort by value alone:** suboptimal density.

## Logic Walkthrough
Sort ratios. For each item: if `capacity >= weight`, take all; else add `value * capacity/weight` and stop.

## Dry Run
Items `(60,10),(100,20),(120,30)`, `W=50` → take all three ratios in order → total **240**.

## Time & Space Complexity
Time **O(N log N)**. Space **O(1)** extra. Why: greedy-choice holds for fractional knapsack (section 4).

## Trade-offs & Alternatives
Wrong algorithm for 0/1 knapsack. Floating ratios need care with ties / precision.

## Common Mistakes / Edge Cases
Applying fractional greedy to 0/1; integer division of value/weight; zero weight.

## Interview Follow-ups / Variations
Prove via exchange argument. Bounded knapsack / multiple copies.

## Tags
`greedy`, `knapsack`, `sorting`, `difficulty:medium`
