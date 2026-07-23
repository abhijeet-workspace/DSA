# Radix Sort (LSD)

## Problem Statement
Sort non-negative integers with LSD radix sort (base 10).

## Intuition
Comparison sorts are Ω(N log N). Digit passes with stable counting sort beat that when digit count D is small.

## Brute Force → Optimal
Comparison sort O(N log N). Radix: O(D·(N+K)) with K=10.

## Data Structure / Approach Justification
`vector` for array + count/output buffers. Avoid in-place unstable digit hacks that break stability.

## Logic Walkthrough
Find max; for each `exp`=1,10,100… stably counting-sort by that digit.

## Dry Run
`{170,45,75,90,802,24,2,66}` → `{2,24,45,66,75,90,170,802}`.

## Time & Space Complexity
**Time:** O(D·(N+K)). **Space:** O(N+K).

## Trade-offs & Alternatives
Fails / needs care with negatives; comparison sorts are simpler general-purpose.

## Common Mistakes / Edge Cases
Unstable digit pass; `exp` overflow; assuming fixed digit width.

## Interview Follow-ups / Variations
MSD radix; handle negatives via transform.

## Tags
`topic: sorting` · `pattern: radix` · `difficulty: medium`
