# Candy

## Problem Statement
[LeetCode 135](https://leetcode.com/problems/candy/) — give each child at least one candy; higher rating than a neighbor must get more candies than that neighbor; minimize total candies.

- **Inputs:** `ratings[i]` for each child in a line.
- **Output:** minimum total candies.
- **Valid answer:** any optimal assignment’s sum.
- **Edges:** `n=1`; strictly increasing / decreasing; plateaus of equal ratings.

## Intuition
Satisfy left-neighbor and right-neighbor constraints separately: climb from left, then climb from right, taking the max at each index.

## Brute Force → Optimal
- **Brute:** try assignments / hill-climbing — exponential or slow.
- **Optimal:** two linear passes + O(N) candy array — O(N).

## Data Structure / Approach Justification
**Chosen:** `candies[i]` initialized to 1; L→R then R→L with `max`.

- **vs one-pass peak/valley formulas:** same idea, more error-prone.
- **vs sorting by rating:** more code; two-pass is standard.

## Logic Walkthrough
Init all 1. For `i=1..n-1`, if rating rises left→right, `candies[i]=candies[i-1]+1`. For `i=n-2..0`, if rises right→left, take `max(candies[i], candies[i+1]+1)`. Sum.

## Dry Run
`[1,0,2]`: after L→R → `[1,1,2]`; R→L bumps index 0 → `[2,1,2]`; sum **5**.

## Time & Space Complexity
Time **O(N)**. Space **O(N)**. Why: each neighbor edge enforced once (section 4).

## Trade-offs & Alternatives
O(1)-extra-space slope methods exist but are harder to get right in interviews.

## Common Mistakes / Edge Cases
Using `=` instead of `max` on the second pass; giving extras on equal ratings; forgetting base 1 candy.

## Interview Follow-ups / Variations
Circular line of children; maximize fairness under a candy budget.

## Tags
`greedy`, `array`, `two-pass`, `leetcode-135`, `difficulty:hard`
