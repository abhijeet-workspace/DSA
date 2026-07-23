# Radix Sort

## Problem Statement
Classic algorithm — sort non-negative integers digit-by-digit using a stable subroutine (LSD, base 10).

- **Inputs:** `vector<int> arr` of non-negative ints.
- **Output:** `arr` sorted ascending.
- **Valid answer:** non-decreasing order.
- **Edges:** empty; single digit; `max=0`.

## Intuition
Stable-sort by least significant digit, then next, … up to MSD. Stability preserves earlier digit order while ordering the current digit.

## Brute Force → Optimal
- **Brute:** comparison sort O(N log N).
- **Optimal:** D passes of counting sort on digits → O(D(N+B)), B=10 here.

## Data Structure / Approach Justification
**Chosen:** LSD + per-digit counting sort (stable, simple).

- **vs MSD:** can short-circuit varying lengths; harder.
- **vs plain counting:** radix handles larger key width without O(K) huge tables.

## Logic Walkthrough
Find `maxVal`. For `exp = 1,10,100,…` while `maxVal/exp > 0`, counting-sort by digit `(x/exp)%10` from the back.

## Dry Run
`[170,45,75,90]` by 1s → `[170,90,45,75]`; by 10s → `[45,75,90,170]`.

## Time & Space Complexity
Time **O(D(N+B))** with B=10. Space **O(N+B)**. Why: one stable digit pass per digit of max (section 4).

## Trade-offs & Alternatives
Excellent for fixed-width integers; not for arbitrary objects. Larger bases (e.g. 2¹⁶) cut passes at more bucket cost.

## Common Mistakes / Edge Cases
Unstable digit sort; stopping before highest digit; negatives without key transform.

## Interview Follow-ups / Variations
Why must digit sort be stable? MSD radix; string radix / bucket sort.

## Tags
`sorting`, `radix-sort`, `counting-sort`, `non-comparison`, `difficulty:medium`
