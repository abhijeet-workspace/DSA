# Find the Smallest Divisor Given a Threshold

## Problem Statement
[LeetCode 1283](https://leetcode.com/problems/find-the-smallest-divisor-given-a-threshold/) — choose positive divisor `d` minimizing d such that `sum ceil(nums[i]/d) <= threshold`.

- **Inputs:** `nums`, `threshold`.
- **Output:** `int` d.
- **Valid answer:** smallest feasible d in `[1, max(nums)]`.
- **Edges:** threshold = n (d must be max); small nums.

## Intuition
Larger d only decreases the sum → monotone. Same ceil as Koko.

## Brute Force → Optimal
- **Brute:** try every d — O(max · N).
- **Optimal:** binary search — O(N log Max).

## Data Structure / Approach Justification
**Chosen:** search-on-answer with ceil division.

- **vs Koko:** hours vs threshold; identical math
- **vs floating division:** precision traps

## Logic Walkthrough
`(x + d - 1) / d` in 64-bit; minimize feasible d.

## Dry Run
`[1,2,5,9]`, threshold 6 → d=5.

## Time & Space Complexity
Time **O(N log Max)**. Space **O(1)**. Why: log divisors × linear sum.

## Trade-offs & Alternatives
Textbook search-on-answer clone of 875.

## Common Mistakes / Edge Cases
Using floor; d=0; int overflow on sum.

## Interview Follow-ups / Variations
Koko; ship packages.

## Tags
`binary-search`, `search-on-answer`, `leetcode-1283`, `difficulty:medium`
